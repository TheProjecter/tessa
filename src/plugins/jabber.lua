gloox = require("gloox")

current_status = "offline";

jid = nil;
client = nil;

-- Misc.
statusmap = { 
			online = gloox.PresenceAvailable, 
			chat = gloox.PresenceChat, 
			away = gloox.PresenceAway, 
			dnd = gloox.PresenceDnd, 
			xa = gloox.PresenceXa, 
			offline = gloox.PresenceUnavailable 
			}
-----------]]


function onGlobalStatusChange(newstatus)
		print(current_status);
		if newstatus ~= current_status then
			if current_status == "offline" then
				-- We need to connect
				jid = gloox.JID(configs:get("jid") or core:error("NOLOGIN", "No JID in configs"));
				client = gloox.Client(jid, configs:get("password"));
				eventhandler = gloox.DefaultConnectionListener(FireLuaEvent);
				--print("swig_type", gloox.swig_type(eventhandler), gloox.swig_type(FireLuaEvent));
				client:registerConnectionListener(eventhandler);
				client:connect(false);
				print("Connecting...");
				events:subscribe("Events/Network/Jabber/Connected",	function ()
																client:setPresence(statusmap[(newstatus.status or "online")], newstatus.priority or 0, newstatus.msg or ""); 
																events:unsubscribe()
															end);
				return; 
			end
			client:setPresence(statusmap[(newstatus.status or "online")], newstatus.priority or 0, newstatus.msg or "");
			
		end
end

function onRun()
	if client and status ~= "offline" then
--		core:error("Recv");
		client:recv(1000);
	end
end

------ Create our events --------------

events:create("Events/Network/Jabber/Connected");
events:create("Events/Network/Jabber/Disconnected");
events:create("Events/Network/Jabber/TLSConnect");
events:create("Events/Network/Jabber/ResourceError");
events:create("Events/Network/Jabber/SessionBindError");

events:subscribe("Events/Protocols/Global/StatusChange", onGlobalStatusChange);
events:subscribe("Events/Core/Run", onRun);
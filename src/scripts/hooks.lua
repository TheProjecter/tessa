-- hooks.lua
-- Joshua's Lua Hack of the Day (JLHotD) for 2007-02-01
--
-- Copyright (c) 2007 Joshua Wise <joshua@joshuawise.com>. Use it for
-- whatever you like, as long as you credit me if you do.
--
-- See http://lua-users.org/wiki/JoshuaWise for a usage example.

-- Note from MattJ... I know a better way to do this. Involving recursion, and the 'and' operator. It also allows use to return values, unlike this one.

hooks = {}
function hooks:new()
	local o = {}
	setmetatable(o, self)
	
	return o
end

hooks.__index = hooks
hooks.__magic = {}

function hooks:insert(func, weight)
	local t = { __magic = hooks.__magic, belongsto = self, func = func, weight = weight or 0}
	table.insert(self, t)
	table.sort(self, function (a,b)
		return a.weight < b.weight
	end)
	return t
end

function hooks:remove(t)
	if t.__magic ~= hooks.__magic or t.belongsto ~= self then
		log:error("this table doesn't belong to me!", 2)
	end
	for i,v in ipairs(self) do
		if v == t then
			table.remove(self, i)
		end
	end
	table.sort(self, function (a,b)
		return a.weight < b.weight
	end)
end

function hooks:__call(...)
	--if main then main(); main = nil; end
	-- os.execute("beep -f 500 -l 50 -r "..tostring(#self));
	-- os.execute("sleep 1");
	for k,v in ipairs(self) do
		local s, m = pcall(v.func, ...);
		if not s then log:error("hooks", m); end
	end
end

module"hooks"

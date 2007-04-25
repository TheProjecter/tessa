require "scripts/hooks"; -- Thanks to Joshua Wise for this, though I have thought of an even better way...

events = {};

function events:create(name)
	events[name] = hooks:new();
	return events[name];
end

function events:subscribe(name, callback)
	assert(events[name]);
	return events[name]:insert(callback); -- Returns a handle, that may be passed to :unsubscribe()
end

function events:unsubscribe(handle)
	if handle then
		events[name]:remove(handle);
	end
end

function events:fire(name, ...)
	if type(name) == "string" then
		return events[name](...);
	else
		return name(...);
	end
end
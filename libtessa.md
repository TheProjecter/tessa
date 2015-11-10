# Introduction #

libtessa is a single C library for interfacing with the Tessa (Lua) core. It provides all you need to create a GUI, or other front-end interface, for Tessa.

libtessa provides several interfaces for performing different functions.


## Core loader ##
This part deals with the execution of the core script(s). It is highly recommended to run this in a seperate thread.

## `FireLuaEvent` Interface ##
Due to current issues with the way our gloox bindings are produced, it needs this interface to hand over events to the core. The GUI should not use this, and it must only be called from the same thread as the core.

In the future this interface may be removed.

## Events System Interface (GUI side) ##
This interface provides the means for the GUI to receive events (such as incoming messages, etc.).

Two choices:

---


`SubscribeEvent(char* name, TessaEventHandler*, long id, void* data = NULL);`

`UnsubscribeEvent(char* name, TessaEventHandler*);`

`int (*TessaEventHandler)(long id, LuaTable& event, void* data = NULL);`

--------------------------------- OR ----------------------------------------

`SetEventHandler(TessaEventHandler*); // All events will be passed to this handler`


---


In the latter case we will need to have a numeric ID for each event. I am very much in support of each event having a structured name, and the translation between names/IDs should be done in Lua for efficiency.


`TriggerEvent(char* name, LuaTable&);`
> `TriggerEvent` code is in SVN as `PostLuaEvent()`. It posts the event to a queue. It goes in hand with `lcGetGUIEvent()` which is used by Lua to retrieve events from this queue.

## Services ##
It is clear to me that we do need something separate to events. However it could still use the events system. Imagine the event "`Services/MessageWindow/AddIcon`", ack'ed with "`Events/MessageWindow/IconAdded`", etc.

In this system, services are simply events beginning with "`Services/`".
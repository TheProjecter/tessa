**Warning:** **Work in progress!**

# Tessa IM #
Tessa is a FOSS, cross-platform, modular Jabber client, employing C++ and Lua.
## Philosophy ##

Goals:
  1. Be flexible
  1. Be small
  1. Be easier
  1. Be cross-platform

<sub>Yes, these may look familiar...</sub>

Also, you can view a 'map' of the things we want Tessa to be, at TessaMap.

## Network ##
Tessa will be able to support multiple network plugins. However the first, and main one will be a Jabber plugin, using gloox ( http://camaya.net/gloox/ ).
## GUI ##
The GUI is the hardest part of this application. It has the need to be both cross-platform and flexible. Building Tessa in a way that it relies on a specific GUI API would violate goal #1 of the project.

The first GUI will be developed in wxWidgets, with the chance to develop more as Tessa grows. (If you would like a different interface for Tessa, and think you could do it, [email us](http://groups.google.co.uk/group/tessa-dev) or find us in the Tessa Jabber conference at tessa@conference.jaim.at).


## Plugins ##

**Why plugins?**

Practically all people who have used plugins in one application or another will agree they are excellent.

However, there are more reasons that make using plugins in applications a good idea:
  * They attract a good developer community (which only means good for any OSS application)
  * They enforce structure within the application
  * Smaller parts are easy and quicker to develop, debug and maintain
  * Replaceable parts allow for great customisation of the application by end-users, who don't need technical knowledge to use them

**Technical**

Plugins may be either binary or Lua. Binary plugins must be valid Lua modules. _(currently)_

For more info on how plugins will integrate with Tessa's core, see [Plugins](Plugins.md).
## Feedback ##

Discussion of this document can take place in [Feedback on Tessa IM](http://obsidianlake.com/wiki/doku.php?id=tessafeedback)
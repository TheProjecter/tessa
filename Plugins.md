# Plugins #

Details relating to plugins. Things they need, how they work, etc. Actual Tessa API is elsewhere.

## General ##

Try and avoid the need to restart after loading/unloading plugins, or changing settings.

## Interface ##
Access some area of the message window, to show contact details.
Status bar in the message window. onclick events, right-click events.

Some general API to display a dialog is needed. I don't think will be too hard with wxw and most libraries.

Add entries to roster rows (icons, avatar, status lines, etc.).


## Network ##
**Incoming messages** Outgoing messages
**Send messages** Incoming iq's (unhandled only?)
**Send iq's** Presence (perhaps outgoing should be restricted, to make sure for example, invisibility cannot be compromised)

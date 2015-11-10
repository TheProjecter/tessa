# Introduction #

Tessa uses a library called gloox to connect with the Jabber server. As well as gloox you need the Lua bindings, which Tessa uses to load gloox.

# Requirements #

You need
gloox 0.9 from http://camaya.net/glooxdownload (recommended RC4: [here](http://camaya.net/download/gloox-0.9-rc4.tar.bz2))

You also need the bindings (which must be from the **SAME** version of gloox that you download): http://camaya.net/glooxbindings
(Note, for now, the bindings for gloox 0.9-rc4 are here: http://camaya.net/download/glooxbindings-0.1.3.tar.bz2 )

Extract both of the above to folders somewhere.

You also need to install liblua5.1(-dev) and swig (a program to make the bindings for us). This should do it:

`sudo aptitude install liblua5.1-dev swig`

# Instructions #

## Command-line ##

The building is handled by a single script. The only thing you have to do is tell it where you extracted gloox, and the gloox bindings to.

`cd ~/Development/tessa/bindings` (Assuming that is where you downloaded the Tessa SVN to)

Now:

`nano buildluamodule`

Change the paths near the top of the file as necessary, to point to the extracted gloox source, and extracted gloox bindings folders. Press Ctrl+O to save, and then Ctrl+X to exit.

Type:

`./buildluamodule`

You should now have a file called 'gloox.so'. To check type:

`ls gloox.so`

If you don't see anything, the build process probably went wrong. If you are sure that you set the paths correctly before you started, join the Tessa mailing list and paste the output of ./buildluamodule, or you can join our conference at **tessa@conference.jaim.at** where we will do our best to help you out.

If you see gloox.so, however, congratulations! The next thing you need to do is install it where Tessa will find it. This can be in the same directory as the tessa binary (bin/Debug/ or bin/Release/) or it can be in /usr/local/lib/lua/5.1/.
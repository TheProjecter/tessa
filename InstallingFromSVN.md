# Introduction #

The Tessa SVN repository is where the Tessa development team keep a 'master copy' of Tessa's source code. This includes code that may not have been tested and released. If you find a problem however, please do report it to our [bug tracker](http://code.google.com/p/tessa/issues/list)!

# Ubuntu (All versions) #

**Note:** This article assumes that you are using the terminal command line to follow these steps.

## Installing required files ##

Install the necessary libraries that Tessa depends upon, and the tools needed to download/build Tessa:

`sudo aptitude install build-essential libwxgtk2.6-0 libwxgtk2.6-dev wx2.6-headers wx-common subversion liblua5.1-dev liblua5.1`

### Note ###
When not installing in the usual location (/bin,/usr/local,/usr/include, but some other path like /usr/local/):

You might need to log out and back in, or start a new terminal emulator after you install packages suck as gloox or wxgtk, before you run the script that builds the gloox bindings, because you might not have gloox-config in your PATH. Otherwise edit your PATH environment variable and you don't have to log out and back in.

## Download the source ##

```
mkdir ~/Development
svn co http://tessa.googlecode.com/svn/trunk/ ~/Development/tessa
```

## Build using the command line ##
### Build (compile) Tessa ###

```
cd ~/Development/tessa/src
g++ *.cpp -I/usr/include/lua5.1 `wx-config --cxxflags --libs`-llua5.1 -o tessa
```

**Update:** For the new network access, you must build and install the gloox bindings. See BuildingGlooxBindings for simple instructions.

### Run! ###

```
cd ~/Development/tessa
./tessa
```

## Build using Code::Blocks ##

Download a .deb file (installer) for Code::Blocks here: http://forums.codeblocks.org/index.php?board=20.0

When prompted, open the .deb file. Click 'Install package'.

If you want debugger support, in Terminal type:
`sudo aptitude install gdb`

Now, run Code::Blocks from your Applications menu (it will be under 'Development' or 'Programming').

In Code::Blocks, select 'File'->'Open...'. Locate Development/tessa folder in your home folder. Open tessa.cbp.

On the 'Build' menu select 'Build and Run'. Enjoy!

**Update:** The gloox Lua bindings are needed for Tessa to connect to Jabber. See BuildingGlooxBindings for more info.

# All other systems #

Install Ubuntu, and carry out previous steps :P

# Troubleshooting #

### liblua5.1.a not found ###
On some systems (**gentoo**, at least) the liblua binary is named differently. Assuming your libraries are in /usr/lib/, type the following:

`ln -s /usr/lib/liblua.a /usr/lib/liblua5.1.a`

### Problems building in Terminal/command line ###
If you have problems, make sure that you typed every command as it is here, copy/paste if you can.
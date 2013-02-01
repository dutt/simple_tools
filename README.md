simple_tools
============

Wrappers around common unix tools to make them slightly more user friendly

So far it's just one though, tar.

star - simple tar.
=======

Usage:
* tar pack FILE - pack a file in a tar archive named like the file + ".tar"
* tar pack FILE ARCHIVE - same as above but with a specified archive name
* tar compress FILE - same as pack but compresses using gzip
* tar compress FILE ARCHIVE - you've got one guess.
* tar unpack FILE - unpack a file, with or without compression.

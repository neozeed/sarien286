![sairen 386 on pcem](https://github.com/neozeed/sarien286/assets/9031439/2817b30f-7900-4666-8446-d748d982f0da)


This is shamelessly forked from https://github.com/SimonKagstrom/sarien-j2me

I mashed it into something that'll run on both pharlap 286's & 386' dos extenders.

It runs on my IBM PS/2 model 60, so that's nice.  I then swapped out for a model 80 motherboard, and it runs there too!

I modified it to load/save games in the same directory.

I tested it on Space Quest 2.0f  should work on the steam/cd-rom collections. I think.

For some reason the VGA driver doesn't work, but the CGA one does.

If you want to run this on 80286/8086 use the real mode version (makereal)
To bulid for a 386, use the Makefile.386
Currently the CGA driver, pharcga3.c crashes if built with Watcom 7, so Ive included a uuencode one built with Watcom 10

I used Microsoft C 6.0a, and pharlap 286 2.5
I used WATCOM C 386 Optimizing Compiler Version 7.0 and pharlap 386 4.1


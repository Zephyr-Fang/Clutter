#ifndef __VERSION_H
#define __VERSION_H

#define VERSIONCODE 4
#define VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))
#define RELEASE   "0.0.4-r360"
#define COPYRIGHT "Copyright (C) 2009 Niek Linnenbank\r\n" \
                  "This is free software; see the source for copying conditions.  There is NO\r\n" \
                  "warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\r\n\r\n"

#define COMPILER  "i686-pc-linux-gnu-gcc (Gentoo 4.4.0 p1.1) 4.4.0"
#define DATETIME  "2009-09-06 00:05:31.284555"
#define ARCH      "X86"

#define BUILDUSER "fox"
#define BUILDHOST "nemesis"
#define BUILDOS   "Linux 2.6.29.4"
#define BUILDARCH "x86_64"
#define BUILDCPU  "Intel(R) Core(TM)2 CPU T5600 @ 1.83GHz"
#define BUILDPY   "Python 2.5.4"
#define BUILDER   "SCons 1.2.0"
#define BUILDPATH "/home/fox/svn/FreeNOS/trunk"
#define BUILDURL  "https://freenos.googlecode.com/svn/trunk"

#endif

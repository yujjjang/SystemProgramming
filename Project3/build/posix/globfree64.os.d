$(common-objpfx)posix/globfree64.os: \
 ../sysdeps/unix/sysv/linux/wordsize-64/globfree64.c \
 ../include/stdc-predef.h $(common-objpfx)libc-modules.h \
 ../include/libc-symbols.h $(common-objpfx)config.h \
 ../sysdeps/generic/symbol-hacks.h ../sysdeps/wordsize-64/globfree64.c

../include/stdc-predef.h:

$(common-objpfx)libc-modules.h:

../include/libc-symbols.h:

$(common-objpfx)config.h:

../sysdeps/generic/symbol-hacks.h:

../sysdeps/wordsize-64/globfree64.c:
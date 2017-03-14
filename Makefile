SRCS=gpiolib.c gpiodemo.c
CFLAGS=
CC=gcc
INSTALL=/usr/local/bin/

all: gpioctl gpiodemo

gpioctl: gpiolib.c
	$(CC) $(CFLAGS) -DCTL -o gpioctl gpiolib.c

gpiodemo: gpiodemo.c
	$(CC) $(CFLAGS) -o gpiodemo gpiolib.c gpiodemo.c

install: all
	install -m 4755 gpiodemo $(INSTALL)
	install -m 4755 gpioctl $(INSTALL)

clean:
	-rm -f gpiodemo gpioctl

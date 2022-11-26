all: build

CC=g++
CPPFLAGS=$(shell sdl2-config --libs --cflags) --shared -I./ -fPIC

build:
	$(CC) $(CPPFLAGS) -o PTk.so ./PTk/PTk.cc
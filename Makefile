
CC=g++
CFLAGS=-g -std=c++11 -Wall -O

all: mandelbrot

mandelbrot: mandelbrot.o asciiimage.o
	${CC} ${CFLAGS} -o mandelbrot mandelbrot.o asciiimage.o

mandelbrot.o: mandelbrot.cpp asciiimage.h
	${CC} ${CFLAGS} -c -o mandelbrot.o mandelbrot.cpp

asciiimage.o: asciiimage.cpp asciiimage.h
	${CC} ${CFLAGS} -c -o asciiimage.o asciiimage.cpp

clean:
	rm -f mandelbrot.o asciiimage.o mandelbrot
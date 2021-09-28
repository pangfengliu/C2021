CXX = gcc

CPPFLAGS = -std=c99 -Wall

executables = 283 3 50040-1 50040 50078 50115 50153 50154 5 6-1 6

%.diff: % %.in
	./$< < $<.in | diff -w - ./$<.out

clean:
	rm $(executables)




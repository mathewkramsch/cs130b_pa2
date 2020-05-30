# makefile

all: incrSubsequence.cpp
	g++ incrSubsequence.cpp -o incrSubsequence
clean:
	/bin/rm -f incrSubsequence

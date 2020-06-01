# makefile

incrSubsequence: incrSubsequence.cpp
	g++ $^ -o $@

cuttingStrings: cuttingStrings.cpp
	g++ $^ -o $@

exactChange: exactChange.cpp
	g++ $^ -o $@

all: incrSubsequence cuttingStrings exactChange

clean:
	/bin/rm -f incrSubsequence exactChange cuttingStrings

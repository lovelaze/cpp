

all: datetest

datetest: DateTest.cpp
	clang++-3.5 -std=gnu++0x -Wall -g DateTest.cpp Date.cpp IsoDate.cpp Julian.cpp Gregorian.cpp -o DateTest.out

run:
	./DateTest.out

.PHONY: clean run

clean:
	rm -rf *.out

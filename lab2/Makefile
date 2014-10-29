

all: DateTest

DateTest: DateTest.cpp
	clang++-3.5 -std=gnu++0x -Wall -g DateTest.cpp date.cpp isodate.cpp julian.cpp gregorian.cpp kattistime.cpp -o DateTest.out

datetest: datetest.cpp
	clang++-3.5 -std=gnu++0x -Wall -g datetest.cpp date.cpp isodate.cpp julian.cpp gregorian.cpp kattistime.cpp -o DateTest.out

run:
	./DateTest.out

.PHONY: clean run

clean:
	rm -rf *.out

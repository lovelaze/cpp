CXX = g++

all: test

test: test.cpp
	$(CXX) -std=gnu++0x -Wall -g test.cpp date.cpp isodate.cpp julian.cpp gregorian.cpp kattistime.cpp -o test.out

datetest: datetest.cpp
	$(CXX) -std=gnu++0x -Wall -g datetest.cpp date.cpp isodate.cpp julian.cpp gregorian.cpp kattistime.cpp -o test.out

run:
	./test.out

.PHONY: clean run

clean:
	rm -rf *.out

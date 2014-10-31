CXX = g++

all: test

test: test.cpp
	$(CXX) -std=gnu++0x -Wall -g test.cpp date.cpp isodate.cpp gregorian.cpp julian.cpp kattistime.cpp -o test.out

datetest: datetest.cpp
	$(CXX) -std=gnu++0x -Wall -g datetest.cpp date.cpp isodate.cpp gregorian.cpp julian.cpp kattistime.cpp -o test.out

test22a:
	$(CXX) -std=gnu++0x -Wall -g cprog09lab22a.cpp date.cpp isodate.cpp gregorian.cpp julian.cpp kattistime.cpp -o test.out

test22c:
	$(CXX) -std=gnu++0x -Wall -g cprog09lab22c.cpp date.cpp isodate.cpp gregorian.cpp julian.cpp kattistime.cpp -o test.out

run:
	./test.out

.PHONY: clean run

clean:
	rm -rf *.out
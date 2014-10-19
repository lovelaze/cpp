
all: datetest


datetest: DateTest.cpp
	clang++-3.5 -std=c++11 -Wall -g DateTest.cpp Date.cpp -o DateTest.out

run:
	./DateTest.out

.PHONY: clean run

clean:
	rm -rf *.out
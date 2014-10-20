
all: datetest


datetest: DateTest.cpp
	clang++ -std=gnu++0x -Wall -g DateTest.cpp Date.cpp Julian.cpp -o DateTest.out

run:
	./DateTest.out

.PHONY: clean run

clean:
	rm -rf *.out

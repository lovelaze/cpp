# Change these
cxxtestpath = /info/cprog11/cxxtest/
testcode    = example_test.h

all: matrix

testcode.cpp: $(testcode)
	python $(cxxtestpath)cxxtestgen.py --error-printer -o testcode.cpp $(testcode)

runtest0%: testcode.cpp
	g++ -I $(cxxtestpath) -o runtest0$* testcode.cpp Matrix0$*.o

clean:
	touch runtest01 testcode.cpp
	rm runtest0* testcode.cpp


matrix:
	clang++-3.5 -std=gnu++0x -Wall -g matrix_test.cpp -o matrix_test.out
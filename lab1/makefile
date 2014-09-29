all: template_container
	
does_it_fit:
	/info/DD2387/labs/cxxtest/cxxtestgen.py --error-printer -o simple_testrunner.cpp simple.cxxtest.cpp
	g++ -c -o count_if_followed_by.o count_if_followed_by.cpp
	g++ -o simple_test.out -I /info/DD2387/labs/cxxtest/ simple_testrunner.cpp count_if_followed_by.o


simple_container: UIntVector.cpp UIntVector.h test_vec.cpp
	g++ -std=gnu++0x -Wall -g test_vec.cpp UIntVector.cpp -o test_vec.out 

template_container:
	g++	-std=gnu++0x -Wall -g test_template_vec.cpp -o VectorMain.out
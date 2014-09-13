all: does_it_fit

does_it_fit:
	/info/DD2387/labs/cxxtest/cxxtestgen.py --error-printer -o simple_testrunner.cpp simple.cxxtest.cpp
	g++ -c -o count_if_followed_by.o count_if_followed_by.cpp
	g++ -o simple_test.out -I /info/DD2387/labs/cxxtest/ simple_testrunner.cpp count_if_followed_by.o



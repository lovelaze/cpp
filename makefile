all:

does_it_fit:
	/info/DD2387/labs/cxxtest/cxxtestgen.py --error-printer -o simple_testrunner.cpp simple.cxxtest.cpp
	g++ -c -o count_if_followed_by.o count_if_followed_by.cpp
	g++ -o simple_test.out -I /info/DD2387/labs/cxxtest/ simple_testrunner.cpp count_if_followed_by.o


simpe_container:
	/info/DD2387/labs/cxxtest/cxxtestgen.py --error-printer -o simple_testrunner.cpp test_vec.cpp
	g++ -c -o UIntVector.o UIntVector.cpp
	g++ -o test_vec.out -I /info/DD2387/labs/cxxtest/ simple_testrunner.cpp UIntVector.o
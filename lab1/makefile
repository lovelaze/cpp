cxxpath = /info/DD2387/labs/cxxtest/cxxtestgen.py
#cxxpath = cxxtestgen
#CXX = clang++
CXX = g++
CXXFLAGS = -std=gnu++11 -static-libstdc++ -Wall -g


#%.out: %.cpp
#	g++ -std=c++0x -g -Wall $*.cpp -o $*.out

all: hello_world does_it_fit will_it_float simple_container template_container template_container_kattis_test matrix

hello_world:
	$(CXX) $(CXXFLAGS) -c hello.cpp -o hello.o
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
	$(CXX) $(CXXFLAGS) main.o hello.o -o hello_world.out
	
does_it_fit:
	$(cxxpath) --error-printer -o simple_testrunner.cpp simple.cxxtest.cpp
	$(CXX) $(CXXFLAGS) -c -o count_if_followed_by.o count_if_followed_by.cpp
	$(CXX) $(CXXFLAGS) -o simple_test.out -I /info/DD2387/labs/cxxtest/ simple_testrunner.cpp count_if_followed_by.o

will_it_float:
	$(CXX) $(CXXFLAGS) birth.cpp -o birth.out
	$(CXX) $(CXXFLAGS) bad_plumming.cpp -o bad_plumming.out

simple_container:
	$(CXX) $(CXXFLAGS) test_vec.cpp  -o test_vec.out 

template_container:
	$(CXX) $(CXXFLAGS) test_template_vec.cpp -o VectorMain.out

template_container_kattis_test:
	$(CXX) $(CXXFLAGS) test_template_kattis.cpp -o VectorKattisTest.out

matrix:
	$(CXX) $(CXXFLAGS) 1.1/matrix_test.cpp 1.1/matrix.cpp -o matrix_test.out


clean:
	rm -rf *.out *.o 

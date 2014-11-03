CXX = clang++-3.5

all: test

test: test.cpp
	$(CXX) -std=gnu++0x -Wall -g test.cpp date.cpp middle.cpp gregorian.cpp julian.cpp kattistime.cpp -o test.out


datetest: datetest.cpp
	$(CXX) -std=gnu++0x -Wall -g datetest.cpp date.cpp middle.cpp gregorian.cpp julian.cpp kattistime.cpp -o test.out

test22a:
	$(CXX) -std=gnu++0x -Wall -g cprog09lab22a.cpp date.cpp middle.cpp gregorian.cpp julian.cpp kattistime.cpp -o test.out
run22a:
	cat lab22a.in | ./test.out > utdata.txt
	diff utdata.txt lab22a.out | less

test22b:
	$(CXX) -std=gnu++0x -Wall -g cprog11lab22b.cpp date.cpp middle.cpp gregorian.cpp kattistime.cpp -o test.out

run22b:
	cat cprog11lab22b.in | ./test.out > utdata.txt
	diff utdata.txt cprog11lab22b.out | less

test22c:
	$(CXX) -std=gnu++0x -Wall -g cprog09lab22c.cpp date.cpp middle.cpp gregorian.cpp julian.cpp kattistime.cpp -o test.out
	
run22c:
	cat lab22c.in | ./test.out > utdata.txt
	diff utdata.txt lab22c.out | less

testcal:
	$(CXX) -std=gnu++0x -Wall -g caltest.cpp date.cpp middle.cpp gregorian.cpp julian.cpp kattistime.cpp -o test.out
runcal:
	./test.out


.PHONY: clean run

run:
	./test.out

clean:
	rm -rf *.out
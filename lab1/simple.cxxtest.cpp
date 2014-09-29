#include <cxxtest/TestSuite.h>

#include "count_if_followed_by.h"


class MyTestSuite : public CxxTest::TestSuite {
  public:
    void test1 () {
      char const  data[6] = {'G','G','X','G','X','G'};
      int  const test_len = 4;

      int  const   result = count_if_followed_by (data, test_len, 'X', 'G');

      // SYNOPSIS:
      //   result should be 1 since the length specified is 4,
      //   and only one pair of [X, G] is present in that range!

      TS_ASSERT_EQUALS(result, 1);
    }

	// SYNOPSIS:
	// result should be 1 since the length (5) shouldn't permit the second XG
	// to be checked (it is permitted though). Only one pair of [X,G] is present but the result is 2.
	void test2 () {
		char const  data[6] = {'G','G','X','G','X','G'};
		
      	int  const test_len = 5;

		int  const   result = count_if_followed_by (data, test_len, 'X', 'G');

		TS_ASSERT_DIFFERS(result, 1);

	}

	void test3() {
		
		char const  data[6] = {'G','G','X','G','X','G'};
		
      	int  const test_len = 0;

		int  const   result = count_if_followed_by (data, test_len, 'F', 'G');

		TS_ASSERT_EQUALS(result, 0);
		
	}
	
	void test4() {
		char const  data[5] = "bajs";
		
      	int  const test_len = 4;

		int  const   result = count_if_followed_by (data, test_len, 'a', 'j');

		TS_ASSERT_EQUALS(result, 1);
		
	}
};

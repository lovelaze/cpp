#include <cxxtest/TestSuite.h>

#include "count_if_followed_by.h"


class MyTestSuite : public CxxTest::TestSuite {
  public:
    void test1Correct () {
      char const  data[6] = {'G','G','X','G','X','G'};
      int  const test_len = 4;

      int  const   result = count_if_followed_by (data, test_len, 'X', 'G');

      // SYNOPSIS:
      //   result should be 1 since the length specified is 4,
      //   and only one pair of [X, G] is present in that range!

      TS_ASSERT_EQUALS(result, 1);
    }

    // SYNOPSIS:
	// result should be 0 since the length specified is 0
    void test2Correct() {
		
		char const  data[6] = {'G','G','X','G','X','G'};
		
      	int  const test_len = 0;

		int  const   result = count_if_followed_by (data, test_len, 'F', 'G');

		TS_ASSERT_EQUALS(result, 0);
		
	}

	// SYNOPSIS:
	// result should be 2
	void test3Correct() {
		char const  data[5] = {'H','E','J','E','J'};
		
      	int  const test_len = 5;

		int  const   result = count_if_followed_by (data, test_len, 'E', 'J');

		TS_ASSERT_EQUALS(result, 2);
	}

	// SYNOPSIS:
	// result should be 2, testing with string initialization
	void test4Correct() {
		char const  data[10] = "korvbanan";
		
      	int  const test_len = 9;

		int  const   result = count_if_followed_by (data, test_len, 'a', 'n');

		TS_ASSERT_EQUALS(result, 2);
	}

	// SYNOPSIS:
	// result should be 1 since the length (5) shouldn't permit the second XG
	// to be checked (it is permitted though). Only one pair of [X,G] is present but the result is 2.
	void test1Incorrect () {
		char const  data[6] = {'G','G','X','G','X','G'};
		
      	int  const test_len = 5;

		int  const   result = count_if_followed_by (data, test_len, 'X', 'G');

		TS_ASSERT_DIFFERS(result, 1);

	}

	// SYNOPSIS:
	// result should be 0 since the range specified is 1, and we are comparing two characters
	void test2Incorrect() {
		char const  data[6] = {'X','G','X','G','X','G'};
		
      	int  const test_len = 1;

		int  const   result = count_if_followed_by (data, test_len, 'X', 'G');

		TS_ASSERT_DIFFERS(result, 0);

	}

	// SYNOPSIS:
	// result should be 0, since the function should not be allowed to read outside the specified length
	void test3Incorrect() {
		char const  data[4] = {'X','G', 'X'};

		
      	int  const test_len = 3;

		int  const   result = count_if_followed_by (data, test_len, 'X', '\0');

		TS_ASSERT_DIFFERS(result, 0);

	}
};

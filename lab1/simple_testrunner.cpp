/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "/home/fredrik/git/cpp/lab1/simple.cxxtest.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "simple.cxxtest.cpp", 6, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test1Correct : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test1Correct() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 8, "test1Correct" ) {}
 void runTest() { suite_MyTestSuite.test1Correct(); }
} testDescription_suite_MyTestSuite_test1Correct;

static class TestDescription_suite_MyTestSuite_test2Correct : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test2Correct() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 23, "test2Correct" ) {}
 void runTest() { suite_MyTestSuite.test2Correct(); }
} testDescription_suite_MyTestSuite_test2Correct;

static class TestDescription_suite_MyTestSuite_test3Correct : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test3Correct() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 37, "test3Correct" ) {}
 void runTest() { suite_MyTestSuite.test3Correct(); }
} testDescription_suite_MyTestSuite_test3Correct;

static class TestDescription_suite_MyTestSuite_test4Correct : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test4Correct() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 49, "test4Correct" ) {}
 void runTest() { suite_MyTestSuite.test4Correct(); }
} testDescription_suite_MyTestSuite_test4Correct;

static class TestDescription_suite_MyTestSuite_test1Incorrect : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test1Incorrect() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 62, "test1Incorrect" ) {}
 void runTest() { suite_MyTestSuite.test1Incorrect(); }
} testDescription_suite_MyTestSuite_test1Incorrect;

static class TestDescription_suite_MyTestSuite_test2Incorrect : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test2Incorrect() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 75, "test2Incorrect" ) {}
 void runTest() { suite_MyTestSuite.test2Incorrect(); }
} testDescription_suite_MyTestSuite_test2Incorrect;

static class TestDescription_suite_MyTestSuite_test3Incorrect : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test3Incorrect() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 88, "test3Incorrect" ) {}
 void runTest() { suite_MyTestSuite.test3Incorrect(); }
} testDescription_suite_MyTestSuite_test3Incorrect;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

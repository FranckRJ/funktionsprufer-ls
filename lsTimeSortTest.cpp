#include <functional>

#include "lsTimeSortTest.hpp"

lsTimeSortTest::lsTimeSortTest()
{
	funToTestExist = true;
}

int lsTimeSortTest::launchTest()
{
	lsTimeSortTest test;

	test.startTest(" -------- Test : time-sort.", false);

	return test.errCount;
}

void lsTimeSortTest::processTest()
{
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("time-sort-tests"), mkSpCppStrVal("-lt dir-test-over-INT_MAX"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("time-sort-tests"), mkSpCppStrVal("-ltr dir-test-over-INT_MAX"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("time-sort-tests"), mkSpCppStrVal("-lt dir-test-over-UINT_MAX"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("time-sort-tests"), mkSpCppStrVal("-ltr dir-test-over-UINT_MAX"));
}

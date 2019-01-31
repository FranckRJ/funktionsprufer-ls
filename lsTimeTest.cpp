#include <functional>

#include "lsTimeTest.hpp"

lsTimeTest::lsTimeTest()
{
	funToTestExist = true;
}

int lsTimeTest::launchTest()
{
	lsTimeTest test;

	test.startTest(" -------- Test : time.", false);

	return test.errCount;
}

void lsTimeTest::processTest()
{
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("time-tests"), mkSpCppStrVal("-l"));
}

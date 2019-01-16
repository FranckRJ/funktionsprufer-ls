#include <functional>

#include "lsUgidTest.hpp"

lsUgidTest::lsUgidTest()
{
	funToTestExist = true;
}

int lsUgidTest::launchTest()
{
	lsUgidTest test;

	test.startTest(" -------- Test : ugid.", false);

	return test.errCount;
}

void lsUgidTest::processTest()
{
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("ugid-tests"), mkSpCppStrVal("-l /etc/"));
}

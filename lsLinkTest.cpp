#include <functional>

#include "lsLinkTest.hpp"

lsLinkTest::lsLinkTest()
{
	funToTestExist = true;
}

int lsLinkTest::launchTest()
{
	lsLinkTest test;

	test.startTest(" -------- Test : link.", false);

	return test.errCount;
}

void lsLinkTest::processTest()
{
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("/var"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("/var zfile"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("/var/"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("/var/ zfile"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l /var"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l /var zfile"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l /var/"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l /var/ zfile"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("zfile /var"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("zfile /var/"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l zfile /var"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l zfile /var/"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("link-to-nothing"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l link-to-nothing"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("link-to-nothing/"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l link-to-nothing/"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal(""));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-R"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-lR"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("dir-for-cycle"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-R dir-for-cycle"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l dir-for-cycle"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-lR dir-for-cycle"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("dir-for-cycle/another-dir-for-cycle"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-R dir-for-cycle/another-dir-for-cycle"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l dir-for-cycle/another-dir-for-cycle"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-lR dir-for-cycle/another-dir-for-cycle"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("dir-for-cycle/cyclic-link"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-R dir-for-cycle/cyclic-link"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("dir-for-cycle/cyclic-link/"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-R dir-for-cycle/cyclic-link/"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l dir-for-cycle/cyclic-link"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-lR dir-for-cycle/cyclic-link"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-l dir-for-cycle/cyclic-link/"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("link-tests"), mkSpCppStrVal("-lR dir-for-cycle/cyclic-link/"));
}

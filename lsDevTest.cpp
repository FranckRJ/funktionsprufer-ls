#include <functional>

#include "lsDevTest.hpp"

lsDevTest::lsDevTest()
{
	funToTestExist = true;
}

int lsDevTest::launchTest()
{
	lsDevTest test;

	test.startTest(" -------- Test : dev.", false);

	return test.errCount;
}

void lsDevTest::processTest()
{
	//supprimer les differences normales (contenu dossier fd et mineur de certains devices).
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("/dev"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-l /dev"));
	//testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-R /dev"));
	//testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-Rl /dev"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("ls-to-dev/"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-l ls-to-dev/"));
	//testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-R ls-to-dev/"));
	//testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-Rl ls-to-dev/"));
}

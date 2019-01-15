#include <functional>

#include "lsBasicArgsTest.hpp"

lsBasicArgsTest::lsBasicArgsTest()
{
	funToTestExist = true;
}

int lsBasicArgsTest::launchTest()
{
	lsBasicArgsTest test;

	test.startTest(" -------- Test : basic-args.", false);

	return test.errCount;
}

void lsBasicArgsTest::processTest()
{
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("basic-args-tests"), mkSpCppStrVal("file"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("basic-args-tests"), mkSpCppStrVal("-l file"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("basic-args-tests"), mkSpCppStrVal("dir"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("basic-args-tests"), mkSpCppStrVal("-l dir"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("basic-args-tests"), mkSpCppStrVal("dir/file_in_dir"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("basic-args-tests"), mkSpCppStrVal("-l dir/file_in_dir"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("basic-args-tests"), mkSpCppStrVal("file dir"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("basic-args-tests"), mkSpCppStrVal("-l file dir"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("basic-args-tests"), mkSpCppStrVal("dir file"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("basic-args-tests"), mkSpCppStrVal("-l dir file"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("basic-args-tests"), mkSpCppStrVal("file dir file dir/file_in_dir dir"));
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("basic-args-tests"), mkSpCppStrVal("-l file dir file dir/file_in_dir dir"));
}

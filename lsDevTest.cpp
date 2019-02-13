#include <functional>

#include "lsDevTest.hpp"

namespace
{
	void removeDevMinorAndFdContent(std::string& str)
	{
		std::string::size_type offset = 0;

		while ((offset = str.find(',', offset)) != std::string::npos)
		{
			int endOffset = offset + 1;
			while (str[endOffset] == ' ' || (str[endOffset] >= '0' && str[endOffset] <= '9'))
				++endOffset;
			str.erase(offset, endOffset - offset);
		}
		offset = str.find("/fd:");
		if (offset != std::string::npos)
		{
			str.erase(offset + 5);
		}
	}
}

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
	std::function<spNoPaddingCppStrVal(spCppStrVal, spCppStrVal)> baseDevFunction =
		[&](spCppStrVal baseDir, spCppStrVal args)
		{
			std::string tmpVal = exec_ls(baseDir, args, true)->getVal();
			removeDevMinorAndFdContent(tmpVal);
			return mkSpNoPaddingCppStrVal(tmpVal, "", !dontShowOnlyDiff);
		};
	std::function<spNoPaddingCppStrVal(spCppStrVal, spCppStrVal)> testDevFunction =
		[&](spCppStrVal baseDir, spCppStrVal args)
		{
			std::string tmpVal = exec_ls(baseDir, args, false)->getVal();
			removeDevMinorAndFdContent(tmpVal);
			return mkSpNoPaddingCppStrVal(tmpVal, "", !dontShowOnlyDiff);
		};

	testThisFun(baseDevFunction, testDevFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("/dev"));
	testThisFun(baseDevFunction, testDevFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-l /dev"));
	testThisFun(baseDevFunction, testDevFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-R /dev"));
	testThisFun(baseDevFunction, testDevFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-Rl /dev"));

	testThisFun(baseDevFunction, testDevFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("ls-to-dev/"));
	testThisFun(baseDevFunction, testDevFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-l ls-to-dev/"));
	testThisFun(baseDevFunction, testDevFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-R ls-to-dev/"));
	testThisFun(baseDevFunction, testDevFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-Rl ls-to-dev/"));
}

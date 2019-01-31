#include <functional>

#include "lsDevTest.hpp"

namespace
{
	void removeDevMinor(std::string& str)
	{
		std::string::size_type offset = 0;

		while ((offset = str.find(',', offset)) != std::string::npos)
		{
			int endOffset = offset + 1;
			while (str[endOffset] == ' ' || (str[endOffset] >= '0' && str[endOffset] <= '9'))
				++endOffset;
			str.erase(offset, endOffset - offset);
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
			removeDevMinor(tmpVal);
			return mkSpNoPaddingCppStrVal(tmpVal);
		};
	std::function<spNoPaddingCppStrVal(spCppStrVal, spCppStrVal)> testDevFunction =
		[&](spCppStrVal baseDir, spCppStrVal args)
		{
			std::string tmpVal = exec_ls(baseDir, args, false)->getVal();
			removeDevMinor(tmpVal);
			return mkSpNoPaddingCppStrVal(tmpVal);
		};

	//supprimer les differences normales (contenu dossier fd et mineur de certains devices).
	testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("/dev"));
	testThisFun(baseDevFunction, testDevFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-l /dev"));
	//testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-R /dev"));
	//testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-Rl /dev"));

	testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("ls-to-dev/"));
	testThisFun(baseDevFunction, testDevFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-l ls-to-dev/"));
	//testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-R ls-to-dev/"));
	//testThisFun(baseFunction, testFunction, mkSpCppStrVal("dev-tests"), mkSpCppStrVal("-Rl ls-to-dev/"));
}

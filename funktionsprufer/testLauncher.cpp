#include <iostream>

#include "absTest.hpp"
#include "colors.hpp"
#include "testLauncher.hpp"

void testLauncher::defRemoveFun(testLauncher *launcher, std::string param)
{
	launcher->removeTest(param);
}

void testLauncher::defErrOnlyFun(testLauncher *launcher, std::string param)
{
	(void)launcher;
	(void)param;
	absTest::showOnlyErrors = true;
}

void testLauncher::defNoColorFun(testLauncher *launcher, std::string param)
{
	(void)launcher;
	(void)param;
	colors::showColors = false;
}

void testLauncher::defHelpFun(testLauncher *launcher, std::string param)
{
	(void)param;
	launcher->printHelpAndExit();
}

void testLauncher::defNoOptArgFun(testLauncher *launcher, std::string param)
{
	launcher->addForcedTest(param);
}

void testLauncher::addTest(std::string name, std::function<int()> newTest)
{
	testList.emplace(name, newTest);
}

void testLauncher::addForcedTest(std::string name)
{
	forcedTests.push_back(name);
}

void testLauncher::removeTest(std::string name)
{
	removedTests.push_back(name);
}

void testLauncher::addOption(std::string name, std::function<void(testLauncher*, std::string)> newOptionFun)
{
	optionsFun.emplace(name, newOptionFun);
}

void testLauncher::setNoOptArgFun(std::function<void(testLauncher*, std::string)> newNoOptArgFun)
{
	noOptArgFun = newNoOptArgFun;
}

void testLauncher::setHelpInf(std::string newHelpInf)
{
	helpInf = newHelpInf;
}

void testLauncher::printHelpAndExit()
{
	std::cout << helpInf << std::endl;
	exit(0);
}

void testLauncher::processArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string curArg = argv[i];

		if (curArg[0] == '-')
		{
			std::string curParam = "";

			if (curArg[1] != '-')
			{
				curParam = curArg.substr(2);
				curArg = curArg.substr(0, 2);
			}

			std::map<std::string, std::function<void(testLauncher*, std::string)>>::iterator it = optionsFun.find(curArg);

			if (it != optionsFun.end())
			{
				it->second(this, curParam);
			}
			else
			{
				printHelpAndExit();
			}
		}
		else if (noOptArgFun)
		{
			noOptArgFun(this, curArg);
		}
	}
}

void testLauncher::processTests()
{
	if (forcedTests.empty())
	{
		absTest::isVerbose = false;
		for (const std::pair<std::string, std::function<int()>>& thisFunc : testList)
		{
			if (std::find(removedTests.begin(), removedTests.end(), thisFunc.first) == removedTests.end())
			{
				int tmpResult = thisFunc.second();

				if (tmpResult > 0)
				{
					errCount += tmpResult;
					++nbOfTestsWithError;
				}
			}
		}
	}
	else
	{
		absTest::isVerbose = true;
		for (const std::string& forcedFunc : forcedTests)
		{
			std::map<std::string, std::function<int()>>::iterator it = testList.find(forcedFunc);

			if (it != testList.end())
			{
				int tmpResult = it->second();

				if (tmpResult > 0)
				{
					errCount += tmpResult;
					++nbOfTestsWithError;
				}
			}
			else
			{
				std::cout << "Erreur : pas de tests nomme " << forcedFunc << "." << std::endl << std::endl;
			}
		}
	}
}

void testLauncher::printResume()
{
	std::cout << colors::bold();
	if (errCount == 0)
	{
		std::cout << colors::green();
		std::cout << "Erreurs : 0.";
	}
	else
	{
		std::cout << colors::red();
		std::cout << "Erreurs : " << errCount << ". Tests concernes : " << nbOfTestsWithError << ".";
	}
	std::cout << colors::reset() << std::endl;
}

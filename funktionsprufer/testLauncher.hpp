#ifndef TESTLAUNCHER_HPP
#define TESTLAUNCHER_HPP

#include <string>
#include <functional>
#include <map>
#include <list>

class testLauncher
{
public:
	static void defRemoveFun(testLauncher *launcher, std::string param);
	static void defErrOnlyFun(testLauncher *launcher, std::string param);
	static void defNoColorFun(testLauncher *launcher, std::string param);
	static void defHelpFun(testLauncher *launcher, std::string param);
	static void defNoOptArgFun(testLauncher *launcher, std::string param);
public:
	void addTest(std::string name, std::function<int()> newTest);
	void addForcedTest(std::string name);
	void removeTest(std::string name);
	void addOption(std::string name, std::function<void(testLauncher*, std::string)> newOptionFun);
	void setNoOptArgFun(std::function<void(testLauncher*, std::string)> newNoOptArgFun);
	void setHelpInf(std::string newHelpInf);
	void printHelpAndExit();
	void processArgs(int argc, char **argv);
	void processTests();
	void printResume();
private:
	std::string helpInf;
	std::map<std::string, std::function<int()>> testList;
	std::list<std::string> removedTests;
	std::list<std::string> forcedTests;
	std::map<std::string, std::function<void(testLauncher*, std::string)>> optionsFun;
	std::function<void(testLauncher*, std::string)> noOptArgFun;
	int errCount = 0;
	int nbOfTestsWithError = 0;
};

#endif

#include <functional>
#include <string>
#include <vector>
#include <atomic>
#include <cstdlib>
#include <signal.h>
#include <sys/select.h>

#include "lsTest.hpp"
#include "funktionsprufer/openFile.hpp"
#include "funktionsprufer/cppStrVal.hpp"
#include "funktionsprufer/noPaddingCppStrVal.hpp"
#include "funktionsprufer/stdOutputGetter.hpp"

namespace
{
	std::atomic<bool> sig_chld_catched;

	void sig_chld_handler(int sig)
	{
		(void)sig;
		sig_chld_catched = true;
	}

	std::vector<std::string> split_string(std::string str, char sep)
	{
		std::vector<std::string> listOfSubStr;
		size_t idxFind = 0;
		std::string subStr;

		while ((idxFind = str.find(sep)) != std::string::npos)
		{
			subStr = str.substr(0, idxFind);
			if (subStr.length() > 0)
			{
				listOfSubStr.push_back(subStr);
			}
			str.erase(0, idxFind + 1);
		}
		if (str.length() > 0)
		{
			listOfSubStr.push_back(str);
		}
		return (listOfSubStr);
	}
}

lsTest::lsTest()
{
	funToTestExist = true;
	funToTestNeedCrashTest = false;
	baseFunction =
		[&](spCppStrVal baseDir, spCppStrVal args)
		{
			chdir(baseDir->getVal().c_str());
			struct timeval timeout = {5,0};
			int select_ret = 0;
			pid_t childPid = 0;

			signal(SIGCHLD, sig_chld_handler);
			sig_chld_catched = false;

			if ((childPid = fork()) == 0)
			{
				std::vector<std::string> argsTab = split_string(args->getVal(), ' ');
				char *programName = strdup("ls");
				char *argv[2 + argsTab.size()];
				argv[0] = programName;
				for (size_t i = 0; i < argsTab.size(); ++i)
				{
					argv[1 + i] = strdup(argsTab[i].c_str());
				}
				argv[1 + argsTab.size()] = nullptr;
				stdOutputGetter tmp(openFile::tmpfileName);
				execv("/bin/ls", argv);
				exit(0);
			}

			select_ret = select(0, NULL, NULL, NULL, &timeout);
			signal(SIGCHLD, SIG_DFL);

			kill(childPid, SIGKILL);
			if (select_ret == 0)
			{
				return mkSpNoPaddingCppStrVal("TIMEOUT (> 5s)");
			}
			else if (sig_chld_catched)
			{
				return mkSpNoPaddingCppStrVal("Stdout :\n" + openFile::getTmpfileContent());
			}
			else
			{
				return mkSpNoPaddingCppStrVal("ERROR");
			}
		};
	testFunction =
		[&](spCppStrVal baseDir, spCppStrVal args)
		{
			chdir(baseDir->getVal().c_str());
			struct timeval timeout = {5,0};
			int select_ret = 0;
			pid_t childPid = 0;

			signal(SIGCHLD, sig_chld_handler);
			sig_chld_catched = false;

			if ((childPid = fork()) == 0)
			{
				std::vector<std::string> argsTab = split_string(args->getVal(), ' ');
				char *programName = strdup("ft_ls");
				char *argv[2 + argsTab.size()];
				argv[0] = programName;
				for (size_t i = 0; i < argsTab.size(); ++i)
				{
					argv[1 + i] = strdup(argsTab[i].c_str());
				}
				argv[1 + argsTab.size()] = nullptr;
				stdOutputGetter tmp(openFile::tmpfileName);
				execv("../ft_ls/ft_ls", argv);
				exit(0);
			}

			select_ret = select(0, NULL, NULL, NULL, &timeout);
			signal(SIGCHLD, SIG_DFL);

			kill(childPid, SIGKILL);
			if (select_ret == 0)
			{
				return mkSpNoPaddingCppStrVal("TIMEOUT (> 5s)");
			}
			else if (sig_chld_catched)
			{
				return mkSpNoPaddingCppStrVal("Stdout :\n" + openFile::getTmpfileContent());
			}
			else
			{
				return mkSpNoPaddingCppStrVal("ERROR");
			}
		};
}

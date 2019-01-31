#include <iostream>
#include <unistd.h>

#include "funktionsprufer/testLauncher.hpp"
#include "lsBasicArgsTest.hpp"
#include "lsUgidTest.hpp"
#include "lsLinkTest.hpp"
#include "lsTimeTest.hpp"

static std::string HELP_INFOS =
R"str(DESCRIPTION:
Execute les tests de ls.

LISTE DES COMMANDES:
<nom_du_test>             Affiche le detail de ce test (mode verbeux).
                          Plusieurs tests peuvent etres appeles, seuls les tests appeles
                          seront testes.
-r<nom_du_test>           Desactive ce test en mode non-verbeux.
--erronly                 Affiche uniquement les tests echoues lors du mode verbeux.
--nocolor                 Desactive l'affichage avec des couleurs.
--help                    Affiche cette page d'aide.)str";

void untar_tests_files()
{
	pid_t childPid = 0;

	if ((childPid = fork()) == 0)
	{
		execl("./untar_tests_files.sh", "./untar_tests_files.sh", NULL);
		exit(0);
	}
	waitpid(childPid, NULL, 0);
}

int main(int argc, char **argv)
{
	testLauncher launcher;

	std::cout << std::unitbuf;

	launcher.setHelpInf(HELP_INFOS);

	launcher.addTest("basic-args", std::bind(lsBasicArgsTest::launchTest));
	launcher.addTest("ugid", std::bind(lsUgidTest::launchTest));
	launcher.addTest("link", std::bind(lsLinkTest::launchTest));
	launcher.addTest("time", std::bind(lsTimeTest::launchTest));

	launcher.addOption("-r", std::bind(testLauncher::defRemoveFun, std::placeholders::_1, std::placeholders::_2));
	launcher.addOption("--erronly", std::bind(testLauncher::defErrOnlyFun, std::placeholders::_1, std::placeholders::_2));
	launcher.addOption("--nocolor", std::bind(testLauncher::defNoColorFun, std::placeholders::_1, std::placeholders::_2));
	launcher.addOption("--help", std::bind(testLauncher::defHelpFun, std::placeholders::_1, std::placeholders::_2));
	launcher.setNoOptArgFun(std::bind(testLauncher::defNoOptArgFun, std::placeholders::_1, std::placeholders::_2));

	untar_tests_files();

	launcher.processArgs(argc, argv);

	std::cout << " ----------------------- ls -----------------------" << std::endl;

	launcher.processTests();

	launcher.printResume();

	return 0;
}

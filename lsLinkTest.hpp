#ifndef LSLINKTEST_HPP
#define LSLINKTEST_HPP

#include "lsTest.hpp"

class lsLinkTest : public lsTest
{
public:
	lsLinkTest();
	static int launchTest();
protected:
	void processTest();
};

#endif

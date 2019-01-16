#ifndef LSUGIDTEST_HPP
#define LSUGIDTEST_HPP

#include "lsTest.hpp"

class lsUgidTest : public lsTest
{
public:
	lsUgidTest();
	static int launchTest();
protected:
	void processTest();
};

#endif

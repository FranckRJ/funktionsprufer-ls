#ifndef LSTIMETEST_HPP
#define LSTIMETEST_HPP

#include "lsTest.hpp"

class lsTimeTest : public lsTest
{
public:
	lsTimeTest();
	static int launchTest();
protected:
	void processTest();
};

#endif

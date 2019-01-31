#ifndef LSDEVTEST_HPP
#define LSDEVTEST_HPP

#include "lsTest.hpp"

class lsDevTest : public lsTest
{
public:
	lsDevTest();
	static int launchTest();
protected:
	void processTest();
};

#endif

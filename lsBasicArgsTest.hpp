#ifndef LSBASICARGSTEST_HPP
#define LSBASICARGSTEST_HPP

#include "lsTest.hpp"

class lsBasicArgsTest : public lsTest
{
public:
	lsBasicArgsTest();
	static int launchTest();
protected:
	void processTest();
};

#endif

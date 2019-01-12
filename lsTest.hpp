#ifndef LSTEST_HPP
#define LSTEST_HPP

#include "funktionsprufer/absTest.hpp"
#include "funktionsprufer/cppStrVal.hpp"

class lsTest : public absTest
{
public:
	lsTest();
protected:
	std::function<spCppStrVal(spCppStrVal, spCppStrVal)> baseFunction;
	std::function<spCppStrVal(spCppStrVal, spCppStrVal)> testFunction;
};

#endif

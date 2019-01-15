#ifndef LSTEST_HPP
#define LSTEST_HPP

#include "funktionsprufer/absTest.hpp"
#include "funktionsprufer/cppStrVal.hpp"
#include "funktionsprufer/noPaddingCppStrVal.hpp"

class lsTest : public absTest
{
public:
	lsTest();
protected:
	std::function<spNoPaddingCppStrVal(spCppStrVal, spCppStrVal)> baseFunction;
	std::function<spNoPaddingCppStrVal(spCppStrVal, spCppStrVal)> testFunction;
};

#endif

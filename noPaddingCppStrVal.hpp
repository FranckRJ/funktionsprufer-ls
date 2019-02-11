#ifndef NOPADDINGCPPSTRVAL_HPP
#define NOPADDINGCPPSTRVAL_HPP

#include <string>
#include <memory>

#include "funktionsprufer/absVal.hpp"
#include "funktionsprufer/cppStrVal.hpp"

class noPaddingCppStrVal;

using spNoPaddingCppStrVal = std::shared_ptr<noPaddingCppStrVal>;

template <class... Args>
spNoPaddingCppStrVal mkSpNoPaddingCppStrVal(Args... args)
{
	return std::make_shared<noPaddingCppStrVal>(std::forward<Args>(args)...);
}

class noPaddingCppStrVal : public cppStrVal
{
public:
	noPaddingCppStrVal(std::string newVal = "", std::string newName = "", bool newOnlyDiffAfterCmp = true);
	bool equalsSameType(spAbsVal<std::string> cmpVal);
private:
	bool onlyDiffAfterCmp;
};

#endif

#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>

#include "noPaddingCppStrVal.hpp"

noPaddingCppStrVal::noPaddingCppStrVal(std::string newVal, std::string newName, bool newOnlyDiffAfterCmp) : cppStrVal(newVal, newName)
{
	onlyDiffAfterCmp = newOnlyDiffAfterCmp;
}

bool noPaddingCppStrVal::equalsSameType(spAbsVal<std::string> cmpVal)
{
	noPaddingCppStrVal *ptrCmpVal = dynamic_cast<noPaddingCppStrVal*>(cmpVal.get());

	if (ptrCmpVal != nullptr)
	{
		std::string str1 = getVal();
		std::string str2 = ptrCmpVal->getVal();

		str1.erase(std::remove(str1.begin(), str1.end(), ' '), str1.end());
		str1.erase(std::remove(str1.begin(), str1.end(), '\t'), str1.end());
		str1.erase(std::remove(str1.begin(), str1.end(), '\n'), str1.end());
		str2.erase(std::remove(str2.begin(), str2.end(), ' '), str2.end());
		str2.erase(std::remove(str2.begin(), str2.end(), '\t'), str2.end());
		str2.erase(std::remove(str2.begin(), str2.end(), '\n'), str2.end());
		return (str1 == str2);
	}
	else
	{
		return false;
	}
}

#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>

#include "noPaddingCppStrVal.hpp"

namespace
{
	void moveIterators(std::string::iterator& itStartLine, std::string::iterator& itCurPos, std::string& str, bool untilNextLine = false)
	{
		while (itCurPos != str.end() && (*itStartLine == ' ' || *itCurPos == '\t' || *itCurPos == '\n' || untilNextLine))
		{
			if (*itCurPos == '\n')
			{
				itStartLine = itCurPos + 1;
				if (untilNextLine)
					return;
			}
			++itCurPos;
		}
	}

	void appendToStr(std::string& baseStr, std::string newStr, int diffIndex, int lineNum)
	{
		if (baseStr.empty())
			baseStr += "\n";
		baseStr += "[" + std::to_string(diffIndex) + "] === Ligne : " + std::to_string(lineNum) + "\n";
		baseStr += newStr;
		baseStr += "=============\n";
	}
}

noPaddingCppStrVal::noPaddingCppStrVal(std::string newVal, std::string newName, bool newOnlyDiffAfterCmp) : cppStrVal(newVal, newName)
{
	onlyDiffAfterCmp = newOnlyDiffAfterCmp;
}

bool noPaddingCppStrVal::equalsSameType(spAbsVal<std::string> cmpVal)
{
	noPaddingCppStrVal *ptrCmpVal = dynamic_cast<noPaddingCppStrVal*>(cmpVal.get());

	if (ptrCmpVal != nullptr)
	{
		if (onlyDiffAfterCmp)
		{
			std::string newStr1;
			std::string newStr2;
			std::string& str1 = getValRef();
			std::string& str2 = ptrCmpVal->getValRef();
			int nbOfDiffs = 0;

			std::string::iterator str1LineStart = str1.begin();
			std::string::iterator str1CurPos = str1LineStart;
			std::string::iterator str2LineStart = str2.begin();
			std::string::iterator str2CurPos = str2LineStart;

			do
			{
				moveIterators(str1LineStart, str1CurPos, str1);
				moveIterators(str2LineStart, str2CurPos, str2);
				if (str1CurPos != str1.end() && str2CurPos != str2.end())
				{
					if (*str1CurPos != *str2CurPos)
					{
						std::string::iterator oldStr1LineStart = str1LineStart;
						std::string::iterator oldStr2LineStart = str2LineStart;
						moveIterators(str1LineStart, str1CurPos, str1, true);
						moveIterators(str2LineStart, str2CurPos, str2, true);
						appendToStr(newStr1, str1.substr(oldStr1LineStart - str1.begin(), str1LineStart - oldStr1LineStart),
								nbOfDiffs, std::count(str1.begin(), oldStr1LineStart, '\n'));
						appendToStr(newStr2, str2.substr(oldStr2LineStart - str2.begin(), str2LineStart - oldStr2LineStart),
								nbOfDiffs, std::count(str2.begin(), oldStr2LineStart, '\n'));
						++nbOfDiffs;
					}
					++str1CurPos;
					++str2CurPos;
				}
			} while (str1CurPos != str1.end() && str2CurPos != str2.end());
			if (str1CurPos != str1.end() || str2CurPos != str2.end())
			{
				++nbOfDiffs;
			}

			if (newStr1.empty())
				newStr1 = "Pas de differences.";
			if (newStr2.empty())
				newStr2 = "Pas de differences.";

			str1 = newStr1;
			str2 = newStr2;

			return (nbOfDiffs == 0);
		}
		else
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
	}
	else
	{
		return false;
	}
}

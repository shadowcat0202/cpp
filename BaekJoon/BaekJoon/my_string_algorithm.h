#pragma once
#include <vector>
#include <string>
class KMP {
public:
	std::vector<int> getPi(std::string text);
	std::vector<int> kmp(std::string text, std::string findtext);
};
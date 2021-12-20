#include <iostream>
#include "my_string_algorithm.h"

std::vector<int> KMP::getPi(std::string text) {
	int patternSize = text.size();
	std::vector<int> pi(patternSize,0);	//초기화

	int j = 0;	//반복되는 부분을 가르키기 위한 변수
	for (int i = 1; i < patternSize; i++) {	//i = 문자열을 앞에서부터 하나씩 찾아가는것
		//일치 하지 않는 경우
		while (j > 0 && text[i] != text[j]) {
			j = pi[j - 1];	//일치하지 않는 부분의 이전 인덱스의 패턴 번호를 j로
		}
		if (text[i] == text[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

std::vector<int> KMP::kmp(std::string text, std::string pattern) {
	std::vector<int> pi = getPi(pattern);	//패턴 배열을 가지고 온다
	int textSize = text.size();
	int patternSize = pattern.size();
	std::vector<int> result;
	int j = 0;
	for (int i = 0; i < textSize; i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == patternSize - 1) {
				result.push_back(i - patternSize + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return result;
}
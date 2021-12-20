#include <iostream>
#include "my_string_algorithm.h"

std::vector<int> KMP::getPi(std::string text) {
	int patternSize = text.size();
	std::vector<int> pi(patternSize,0);	//�ʱ�ȭ

	int j = 0;	//�ݺ��Ǵ� �κ��� ����Ű�� ���� ����
	for (int i = 1; i < patternSize; i++) {	//i = ���ڿ��� �տ������� �ϳ��� ã�ư��°�
		//��ġ ���� �ʴ� ���
		while (j > 0 && text[i] != text[j]) {
			j = pi[j - 1];	//��ġ���� �ʴ� �κ��� ���� �ε����� ���� ��ȣ�� j��
		}
		if (text[i] == text[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

std::vector<int> KMP::kmp(std::string text, std::string pattern) {
	std::vector<int> pi = getPi(pattern);	//���� �迭�� ������ �´�
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
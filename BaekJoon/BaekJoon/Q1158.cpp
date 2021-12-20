#include <iostream>
#include <sstream>
#include "data_structure.h";

void Q1158::run() {
	std::cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	std::stringstream ss;

	int count = K;
	while (!dq.empty()) {
		if (count == 1) {
			ss << dq.front();
			if (dq.size() > 1) {
				ss << ", ";
			}
			dq.pop_front();
			count = K;
			continue;
		}
		int buf = dq.front();
		dq.push_back(buf);
		dq.pop_front();
		count--;
	}

	std::cout << "<" << ss.str() << ">\n";
	
}
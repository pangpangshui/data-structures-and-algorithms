#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void push(int value) {
		sta.push_back(value);
	}
	void pop() {
		sta.pop_back();
	}
	int top() {
		sta.at(sta.size() - 1);
	}
	int min() {
		int min = 0;
		for (int i = 0; i < sta.size(); i++) {
			if (min > sta.at(i))
				min = sta.at(i);
		}
		return min;
	}
private:
	vector<int> sta;
};


int main() {
	vector<int> test;
	for (int i = 0; i < 10; i++) {
		test.push_back(i);
	}

	for (int j = 0; j < 5; j++) {
		printf_s("%d ", test.at(j));
		test.pop_back();
	}
	return 0;
}
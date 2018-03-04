//现在要求输入一个整数n，请你输出斐波那契数列的第n项。
//n <= 39
//不能用递归，复杂度太大，用栈处理，第一个元素默认是1，要对n=1或0做判断

#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
	int Fibonacci(int n) {
		int temp1 = 0,temp2 = 0;
		if (n == 1 || n == 0)
			return n;
		else {
			if (stack1.empty()) {
				stack1.push(1);
				stack1.push(1);
			}
			for (int i = 2; i < n; i++) {
				temp1 = stack1.top();
				stack1.pop();
				temp2 = stack1.top();
				stack1.push(temp1);
				stack1.push(temp1 + temp2);
			}
			return stack1.top();
		}
	}
private:
	stack<int> stack1;
};


int main() {
	Solution *s = new Solution();
	s->Fibonacci(5);
	return 0;
}
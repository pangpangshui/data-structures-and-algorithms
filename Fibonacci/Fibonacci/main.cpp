//����Ҫ������һ������n���������쳲��������еĵ�n�
//n <= 39
//�����õݹ飬���Ӷ�̫����ջ������һ��Ԫ��Ĭ����1��Ҫ��n=1��0���ж�

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
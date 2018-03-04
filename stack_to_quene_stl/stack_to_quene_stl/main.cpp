//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�������������ʵ����
//��Ҫ����stack1��stack2�Ƿ�Ϊ�����ֱ��жϣ��ſ��γ��Ƚ��ȳ�������

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int temp;
		if (!stack2.empty()) {
			temp = stack2.top();
			stack2.pop();
			return temp;
		}
		else {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}

			temp = stack2.top();
			stack2.pop();
			return temp;
		}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};


int main() {

	Solution *s = new Solution();
	for (int i = 0; i < 10; i++) {
		s->push(i);
	}
	for (int i = 0; i < 10; i++) {
		printf_s("%d ", s->pop());
	}
	return 0;
}
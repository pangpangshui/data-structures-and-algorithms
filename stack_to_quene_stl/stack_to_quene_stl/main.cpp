//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。看起来容易其实不简单
//需要考虑stack1和stack2是否为空来分别判断，才可形成先进先出的现象

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
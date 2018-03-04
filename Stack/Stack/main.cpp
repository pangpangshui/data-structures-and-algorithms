#include <iostream>

using namespace std;


typedef struct Node *pNode;
struct Node {
	char c;
	pNode next;
};

struct Stack
{
	pNode top;
};

typedef struct Stack *pStack;

//������ջ
pStack CreatStack() {
	pStack stacklink = (pStack)malloc(sizeof(struct Stack));
	if (stacklink == NULL) {
		//return stacklink;
		printf_s("������Χ\n");
	}
	else {
		stacklink->top = NULL;
	}
	return stacklink;
}

//�п�
bool isStackNull(pStack stacklink) {
	return (stacklink->top == NULL);
}

//��ջ
void pushStack(pStack stacklink, char c) {
	pNode p = (pNode)malloc(sizeof(struct Node));
	if (p == NULL) {
		//return stacklink;
		printf_s("������Χ\n");
	}
	else {
		p->next = stacklink->top;
		p->c = c;
		stacklink->top = p;
	}
}


//��ջ
void popStack(pStack stacklink) {
	pNode p;
	if (stacklink->top == NULL) {
		cout << "��ջ�����ɳ�ջ" << endl;
	}
	else {
		p = stacklink->top;
		stacklink->top = stacklink->top->next;
		free(p);
	}
}

//ȡջ��Ԫ��
char getTop(pStack stacklink) {
	if (stacklink->top == NULL) {
		cout << "��ջ�����ɳ�ջ" << endl;
		return 0;
	}
	else {
		return stacklink->top->c;
	}
}

//쳲��������еݹ麯��ʵ��
long FibonacciRecursion(int n) {
	long rec = n;
	if (n > 1) {
		rec = FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
	}
	return rec;
}


//쳲��������зǵݹ麯��ʵ��--ջ
long FibonacciNotRecursionStack(int n) {
	long rec = 0;
	long n0 = 0, n1 = 1, n2;
	
	pStack fib = CreatStack();
	if (fib == NULL) {
		return  0;
	}
	else {
		pushStack(fib, n0);
		pushStack(fib, n1);
		while (n > 1) {
			n2 = n0 + n1;
			pushStack(fib, n2);
			n--;
			n0 = n1;
			n1 = n2;
		}
		
		if (!isStackNull(fib)) {
			rec = getTop(fib);
		}
	}
	return rec;
}

//쳲��������зǵݹ麯��ʵ��--����ջ
long FibonacciNotRecursionNotStack(int n) {
	unsigned long n0, n1, n2;
	/*if (n == 0) {
		n2 = 0;
	}
	else if (n == 1) {
		n2 = 1;
	}*/
	n1 = 1;
	n0 = 0;
	
	while (n > 1) {
		n2 = n1 + n0;
		n--;
		n0 = n1;
		n1 = n2;
	}
	return n2;
}

int main() {
	pStack testStack = CreatStack();
	if (isStackNull(testStack)) {
		for (int i = 65; i < 75; i++) {
			pushStack(testStack, i);
			cout << char(i);
		}
	}

	if (!isStackNull(testStack)) {
		for (int i = 0; i < 10; i++) {
			cout << getTop(testStack);
			popStack(testStack);
		}
	}
	cout << endl;
	//cout << getTop(testStack);

	cout << FibonacciRecursion(0) << endl;
	cout << FibonacciNotRecursionNotStack(9) << endl;
	cout << FibonacciNotRecursionStack(8) << endl;
	return 0;
}
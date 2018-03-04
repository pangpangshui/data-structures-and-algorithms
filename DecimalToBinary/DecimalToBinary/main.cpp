#pragma warning(disable:4996) //全部關掉
#include <iostream>

using namespace std;

struct Node;
typedef struct Node *pNode;
struct Node {
	int binary;
	pNode next;
};


struct Stack {
	pNode top;
};
typedef struct Stack *Stacklink;


//创建空栈
Stacklink CreateStack() {
	Stacklink stacklink = (Stacklink)malloc(sizeof(struct Stack));
	if (stacklink == NULL) {
		printf_s("没空间\n");
	}
	else {
		stacklink->top = NULL;
	}
	return stacklink;
}

//判空
bool isStackEmpty(Stacklink stacklink) {
	return (stacklink->top == NULL);
}

//入栈
void pushStack(Stacklink stacklink, int binary) {
	pNode p = (pNode)malloc(sizeof(struct Node));
	if (stacklink == NULL) {
		printf_s("栈超出空间\n");
	}
	else {
		p->binary = binary;
		p->next = stacklink->top;
		//stacklink->top->next = p;
		stacklink->top = p;
	}
}


//出栈
void popStack(Stacklink stacklink) {
	pNode p;
	if (stacklink == NULL) {
		printf_s("栈超出空间\n");
	}
	else {
		p = stacklink->top;
		stacklink->top = stacklink->top->next;
		free(p);
	}
}

//取栈顶元素
int getStackTop(Stacklink stacklink) {
	if (stacklink == NULL) {
		printf_s("栈超出空间\n");
		return NULL;
	}
	else {
		return stacklink->top->binary;
	}
}

void DecimalToBinary(Stacklink stacklink, int decimal) {
	int bina = 0;
	if (decimal < 0) {
		printf_s("请输入非负整数\n");
		exit(0);
	}
	else {
		
		while (decimal != 0) {
			bina = decimal % 2;
			pushStack(stacklink, bina);
			decimal = decimal / 2;
		}
	}
}

int main(){
	int de;
	Stacklink change = CreateStack();
	scanf("%d", &de);
	DecimalToBinary(change, de);
	while (!isStackEmpty(change)) {
		printf_s("%d",getStackTop(change));
		popStack(change);
	}

	return 0;
}
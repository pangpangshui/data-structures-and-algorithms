#pragma warning(disable:4996) //ȫ���P��
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


//������ջ
Stacklink CreateStack() {
	Stacklink stacklink = (Stacklink)malloc(sizeof(struct Stack));
	if (stacklink == NULL) {
		printf_s("û�ռ�\n");
	}
	else {
		stacklink->top = NULL;
	}
	return stacklink;
}

//�п�
bool isStackEmpty(Stacklink stacklink) {
	return (stacklink->top == NULL);
}

//��ջ
void pushStack(Stacklink stacklink, int binary) {
	pNode p = (pNode)malloc(sizeof(struct Node));
	if (stacklink == NULL) {
		printf_s("ջ�����ռ�\n");
	}
	else {
		p->binary = binary;
		p->next = stacklink->top;
		//stacklink->top->next = p;
		stacklink->top = p;
	}
}


//��ջ
void popStack(Stacklink stacklink) {
	pNode p;
	if (stacklink == NULL) {
		printf_s("ջ�����ռ�\n");
	}
	else {
		p = stacklink->top;
		stacklink->top = stacklink->top->next;
		free(p);
	}
}

//ȡջ��Ԫ��
int getStackTop(Stacklink stacklink) {
	if (stacklink == NULL) {
		printf_s("ջ�����ռ�\n");
		return NULL;
	}
	else {
		return stacklink->top->binary;
	}
}

void DecimalToBinary(Stacklink stacklink, int decimal) {
	int bina = 0;
	if (decimal < 0) {
		printf_s("������Ǹ�����\n");
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
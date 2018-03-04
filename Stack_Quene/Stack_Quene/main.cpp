#include <iostream>

using namespace std;

struct StackNode;
typedef struct StackNode *sNode;
struct StackNode {
	int sdata;
	sNode snext;
};

struct Stack {
	sNode top;
};
typedef struct Stack *Stacklink;

struct QueneNode;
typedef struct QueneNode *qNode;
struct QueneNode {
	int qdata;
	qNode qnext;
};

struct Quene {
	qNode front;
	qNode rump;
};
typedef struct Quene *Quenelink;

//������ջ
Stacklink CreateStack() {
	Stacklink stacklink = (Stacklink)malloc(sizeof(struct Stack));
	if (stacklink == NULL) {
		printf_s("������Χ\n");
	}
	else {
		stacklink->top = NULL;
	}
	return stacklink;
}

//�п�--ջ
bool isStackEmpty(Stacklink stacklink) {
	return (stacklink->top == NULL);
}

//��ջ
void pushStack(Stacklink stacklink, int sdata) {
	sNode s = (sNode)malloc(sizeof(struct StackNode));
	if (stacklink == NULL) {
		printf_s("ջû�пռ�\n");
	}
	else {
		s->sdata = sdata;
		s->snext = stacklink->top;
		stacklink->top = s;
	}
}

//��ջ
void popStack(Stacklink stacklink) {
	sNode s;
	if (stacklink == NULL) {
		printf_s("ջû�пռ�\n");
	}
	else {
		s = stacklink->top;
		stacklink->top = stacklink->top->snext;
		free(s);
	}
}


//ȡջ��Ԫ��
int getStackTop(Stacklink stacklink) {
	if (stacklink == NULL) {
		printf_s("ջû�пռ�\n");
	}
	else {
		return stacklink->top->sdata;
	}
}

//�����ն���
Quenelink CreateQuene() {
	Quenelink quenelink = (Quenelink)malloc(sizeof(struct Quene));
	if (quenelink == NULL) {
		printf_s("������Χ\n");
	}
	else {
		quenelink->front = NULL;
		quenelink->rump = NULL;
	}
	return quenelink;
}


//�п�--����
bool isQueneEmpty(Quenelink quenelink) {
	return (quenelink->front == NULL);
}

//���
void enQuene(Quenelink quenelink, int qdata) {
	qNode q = (qNode)malloc(sizeof(struct QueneNode));
	q->qdata = qdata;
	q->qnext = NULL;
	if (quenelink->front == NULL) {
		quenelink->front = q;
		quenelink->rump = q;
	}
	else {
		quenelink->rump->qnext = q;
		quenelink->rump = q;
	}
}


//����
void deQuene(Quenelink quenelink) {
	qNode q;
	if (quenelink->front == NULL) {
		printf_s("����Ϊ��\n");
	}
	else {
		q = quenelink->front;
		quenelink->front = quenelink->front->qnext;
		free(q);
	}
}

//ȡ����Ԫ��
int getQueneTop(Quenelink quenelink) {
	if (quenelink->front == NULL) {
		printf_s("����Ϊ��\n");
	}
	else { 
		return quenelink->front->qdata;
	}
}


//ջ->����
void StackToQuene(Stacklink stacklink, Quenelink quenelink) {
	while (!isStackEmpty(stacklink)) {
		enQuene(quenelink, getStackTop(stacklink));
		popStack(stacklink);
	}
}


//����->ջ
void QueneToStack(Stacklink stacklink, Quenelink quenelink) {
	while (!isQueneEmpty(quenelink)) {
		pushStack(stacklink, getQueneTop(quenelink));
		deQuene(quenelink);
	}
}

int main() {
	//��ʼ������
	Stacklink stest = CreateStack();
	Quenelink qtest = CreateQuene();
	for (int i = 0; i < 10; i++) {
		pushStack(stest, i);
	}

	//ջ->����
	StackToQuene(stest, qtest);
	while (!isQueneEmpty(qtest)) {
		printf_s("%d", getQueneTop(qtest));
		deQuene(qtest);
	}
	
	//����->ջ
	for (int i = 0; i < 10; i++) {
		enQuene(qtest, i);
	}
	QueneToStack(stest, qtest);
	while (!isStackEmpty(stest)) {
		printf_s("%d", getStackTop(stest));
		popStack(stest);
	}
	
	return 0;
}
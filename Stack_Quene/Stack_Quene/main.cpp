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

//创建空栈
Stacklink CreateStack() {
	Stacklink stacklink = (Stacklink)malloc(sizeof(struct Stack));
	if (stacklink == NULL) {
		printf_s("超出范围\n");
	}
	else {
		stacklink->top = NULL;
	}
	return stacklink;
}

//判空--栈
bool isStackEmpty(Stacklink stacklink) {
	return (stacklink->top == NULL);
}

//入栈
void pushStack(Stacklink stacklink, int sdata) {
	sNode s = (sNode)malloc(sizeof(struct StackNode));
	if (stacklink == NULL) {
		printf_s("栈没有空间\n");
	}
	else {
		s->sdata = sdata;
		s->snext = stacklink->top;
		stacklink->top = s;
	}
}

//出栈
void popStack(Stacklink stacklink) {
	sNode s;
	if (stacklink == NULL) {
		printf_s("栈没有空间\n");
	}
	else {
		s = stacklink->top;
		stacklink->top = stacklink->top->snext;
		free(s);
	}
}


//取栈顶元素
int getStackTop(Stacklink stacklink) {
	if (stacklink == NULL) {
		printf_s("栈没有空间\n");
	}
	else {
		return stacklink->top->sdata;
	}
}

//创建空队列
Quenelink CreateQuene() {
	Quenelink quenelink = (Quenelink)malloc(sizeof(struct Quene));
	if (quenelink == NULL) {
		printf_s("超出范围\n");
	}
	else {
		quenelink->front = NULL;
		quenelink->rump = NULL;
	}
	return quenelink;
}


//判空--队列
bool isQueneEmpty(Quenelink quenelink) {
	return (quenelink->front == NULL);
}

//入队
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


//出队
void deQuene(Quenelink quenelink) {
	qNode q;
	if (quenelink->front == NULL) {
		printf_s("队列为空\n");
	}
	else {
		q = quenelink->front;
		quenelink->front = quenelink->front->qnext;
		free(q);
	}
}

//取队首元素
int getQueneTop(Quenelink quenelink) {
	if (quenelink->front == NULL) {
		printf_s("队列为空\n");
	}
	else { 
		return quenelink->front->qdata;
	}
}


//栈->队列
void StackToQuene(Stacklink stacklink, Quenelink quenelink) {
	while (!isStackEmpty(stacklink)) {
		enQuene(quenelink, getStackTop(stacklink));
		popStack(stacklink);
	}
}


//队列->栈
void QueneToStack(Stacklink stacklink, Quenelink quenelink) {
	while (!isQueneEmpty(quenelink)) {
		pushStack(stacklink, getQueneTop(quenelink));
		deQuene(quenelink);
	}
}

int main() {
	//初始化工作
	Stacklink stest = CreateStack();
	Quenelink qtest = CreateQuene();
	for (int i = 0; i < 10; i++) {
		pushStack(stest, i);
	}

	//栈->队列
	StackToQuene(stest, qtest);
	while (!isQueneEmpty(qtest)) {
		printf_s("%d", getQueneTop(qtest));
		deQuene(qtest);
	}
	
	//队列->栈
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
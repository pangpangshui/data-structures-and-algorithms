#include <iostream>

using namespace std;

struct Node;
typedef struct Node *qNode;
struct Node {
	int data;
	qNode Next;
};


struct Quene {
	qNode front;
	qNode rump;
};

typedef Quene *qQuene;

//创建队列
qQuene CreateQuene() {
	//qNode q = (qNode)malloc(sizeof(struct Node));
	qQuene quene = (qQuene)malloc(sizeof(struct Quene));
	//qQuene quene;
	if (quene == NULL) {
		cout << "超出范围" <<endl;
	}
	else {
		quene->front = NULL;
		quene->rump = NULL;
	}
	return quene;
}

//判空
bool isQueneEmpty(qQuene quene) {
	return (quene->front == NULL);
}

//入队,元素插入队尾，操作rump
void enQuene(qQuene quene, int data) {
	qNode q = (qNode)malloc(sizeof(struct Node));
	if (quene == NULL) {
		cout << "超出范围" << endl;
	}
	else {
		q->data = data;
		q->Next = NULL;
		if (quene->front == NULL) {
			quene->front = q;
		}
		else {
			quene->rump->Next = q;
		}
		quene->rump = q;
	}
}

//出队，队首元素出队，操作front
void deQuene(qQuene quene) {
	qNode q;
	if (quene->front == NULL) {
		cout << "队列为空" << endl;
	}
	else {
		q = quene->front;
		quene->front = q->Next;
		free(q);
	}
}


//去队首元素
int getTop(qQuene quene) {
	if (quene == NULL) {
		return NULL;
	}
	else if (quene->front == NULL){
		return NULL;
	}
	else {
		return quene->front->data;
	}
}


int farmer(int location) {
	return (0 != (location & 0x08));
}

int wolf(int location) {
	return (0 != (location & 0x04));
}

int cabbage(int location) {
	return (0 != (location & 0x02));
}

int goat(int location) {
	return (0 != (location & 0x01));
}


bool safe(int location) {
	if (goat(location) == cabbage(location) && goat(location) != farmer(location)) {
		return false;
	}
	if (goat(location) == wolf(location) && goat(location) != farmer(location)) {
		return false;
	}
	return true;
}


void CrossRiver() {
	int location, newlocation, move;
	int route[16];
	qQuene river = CreateQuene();
	enQuene(river, 0x00);
	for (int i = 0; i < 16; i++) {
		route[i] = -1;
	}
	route[0] = 0;
	while (!isQueneEmpty(river) && route[15] == -1) {
		location = getTop(river);
		deQuene(river);


		//不断尝试携带物品的四种可能性，如果发现状态安全，则将其记录在route里面以及入队，入队是用来作为下次四种可能性的判断的初始状态，即以上两个语句
		for (move = 1; move <= 8; move <<= 1) {
			//判断农夫和物品是否在同一个地点
			if ((0 != (location & 0x08)) == (0 != (location & move))) {
				newlocation = location ^ (move | 0x08);//对农夫和携带的物品状态翻转，即表示物品被带过河，以及农夫过河和返回
				if (safe(newlocation) && route[newlocation] == -1) {
					route[newlocation] = location;//记录前驱状态
					enQuene(river, newlocation);
				}
			}
		}
	}

	if (route[15] != -1) {
		//非常巧妙的记录路径和取路径的方法
		for (location = 15; location >= 0; location = route[location]) {
			printf_s("%d ", location);
			if (location == 0)
				exit(0);
		}
	}
	else {
		printf_s("找不到路径");
	}
}

int main() {

	/*qQuene test = CreateQuene();

	for (int i = 0; i < 10; i++) {
		enQuene(test, i);
	}

	for (int i = 0; i < 11; i++) {
		cout << getTop(test) << endl;
		deQuene(test);
	}*/


	CrossRiver();

	return 0;
}
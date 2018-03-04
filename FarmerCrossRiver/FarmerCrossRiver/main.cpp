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

//��������
qQuene CreateQuene() {
	//qNode q = (qNode)malloc(sizeof(struct Node));
	qQuene quene = (qQuene)malloc(sizeof(struct Quene));
	//qQuene quene;
	if (quene == NULL) {
		cout << "������Χ" <<endl;
	}
	else {
		quene->front = NULL;
		quene->rump = NULL;
	}
	return quene;
}

//�п�
bool isQueneEmpty(qQuene quene) {
	return (quene->front == NULL);
}

//���,Ԫ�ز����β������rump
void enQuene(qQuene quene, int data) {
	qNode q = (qNode)malloc(sizeof(struct Node));
	if (quene == NULL) {
		cout << "������Χ" << endl;
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

//���ӣ�����Ԫ�س��ӣ�����front
void deQuene(qQuene quene) {
	qNode q;
	if (quene->front == NULL) {
		cout << "����Ϊ��" << endl;
	}
	else {
		q = quene->front;
		quene->front = q->Next;
		free(q);
	}
}


//ȥ����Ԫ��
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


		//���ϳ���Я����Ʒ�����ֿ����ԣ��������״̬��ȫ�������¼��route�����Լ���ӣ������������Ϊ�´����ֿ����Ե��жϵĳ�ʼ״̬���������������
		for (move = 1; move <= 8; move <<= 1) {
			//�ж�ũ�����Ʒ�Ƿ���ͬһ���ص�
			if ((0 != (location & 0x08)) == (0 != (location & move))) {
				newlocation = location ^ (move | 0x08);//��ũ���Я������Ʒ״̬��ת������ʾ��Ʒ�������ӣ��Լ�ũ����Ӻͷ���
				if (safe(newlocation) && route[newlocation] == -1) {
					route[newlocation] = location;//��¼ǰ��״̬
					enQuene(river, newlocation);
				}
			}
		}
	}

	if (route[15] != -1) {
		//�ǳ�����ļ�¼·����ȡ·���ķ���
		for (location = 15; location >= 0; location = route[location]) {
			printf_s("%d ", location);
			if (location == 0)
				exit(0);
		}
	}
	else {
		printf_s("�Ҳ���·��");
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
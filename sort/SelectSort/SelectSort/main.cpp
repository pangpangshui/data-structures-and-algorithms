//vs�ص�����
#pragma warning(disable:4996) //ȫ���P��
#include <iostream>

using namespace std;

struct SelectNode {
	int key;
	int info;
};

typedef struct SelectNode seNode;

struct SelectList {
	int MAXNUM;
	int n;
	seNode *element;
};
typedef struct SelectList *seList;


seList CreateList(int m) {
	seList selist = (seList)malloc(sizeof(struct SelectList));
	if (selist == NULL) {
		printf_s("�����ռ�\n");
		return NULL;
	}
	else {
		selist->element = (seNode *)malloc(sizeof(seNode));
		if (selist->element == NULL) {
			printf_s("�����ռ�\n");
			return NULL;
		}
		else {
			selist->MAXNUM = m;
			selist->n = 0;
		}
		return selist;
	}
}


void InsertList(seList selist, seNode data) {
	if (selist == NULL) {
		printf_s("�����ռ�\n");
	}
	else {
		if (selist->n > selist->MAXNUM) {
			printf_s("�����ռ�\n");
			return;
		}
		else {
			selist->element[selist->n] = data;
			selist->n = selist->n + 1;
		}
	}
}


void SelectSort(seList selist) {
	int data, k, temp;
	//�Ӱѵ�i����i�����Ԫ������Աȣ����򽻻�
	for (int i = 0; i < selist->n; i++) {
		data = selist->element[i].key;
		k = i;
		for (int j = i + 1; j < selist->n; j++) {
			//��i֮���Ԫ����Ѱ�ұ�iԪ��С�ģ���k��ֵΪ�Ǹ���СԪ�ص��±�
			if (selist->element[j].key < selist->element[k].key) {
				k = j;
			}
		}
		//����СԪ�غ͵�i��Ԫ�ؽ���
		if (k != i) {
			temp = selist->element[i].key;
			selist->element[i].key = selist->element[k].key;
			selist->element[k].key = temp;
		}
	}

	for (int i = 0; i < selist->n; i++) {
		printf_s("%d ", selist->element[i].key);
	}
	printf_s("\n");
}


int main() {
	int data;
	seNode se;
	seList selist = CreateList(100);
	se.info = 0;
	fflush(stdin);
	while (cin >> data) {
		se.key = data;
		InsertList(selist, se);
		if (cin.get() == '\n')
			break;
	}
	SelectSort(selist);
	system("pause");
	return 0;
}
//vs�ص�����
#pragma warning(disable:4996) //ȫ���P��

#include <iostream>

using namespace std;


struct HeapNode {
	int key;
	int info;
};
typedef struct HeapNode heNode;

struct HeapList {
	int MAXNUM;
	int n;
	heNode *element;
};
typedef struct HeapList *HeList;


HeList CreateList(int m) {
	HeList helist = (HeList)malloc(sizeof(struct HeapList));
	if (helist == NULL) {
		printf_s("�����ռ�\n");
		return NULL;
	}
	else {
		helist->element = (heNode *)malloc(sizeof(struct HeapNode));
		if (helist->element == NULL) {
			printf_s("�����ռ�\n");
			return NULL;
		}
		helist->n = 0;
		helist->MAXNUM = m;
		return helist;
	}
}


void InsertList(HeList helist,heNode he) {
	if (helist == NULL) {
		printf_s("�����ռ�\n");
		return;
	}
	else {
		if (helist->n > helist->MAXNUM) {
			printf_s("�����ռ�\n");
			return;
		}
		else {
			helist->element[helist->n] = he;
			helist->n = helist->n + 1;
		}
	}
}

void sift(HeList helist, int size, int p) {
	heNode temp = helist->element[p];
	//childΪ��pΪ���ڵ�����ĺ���
	int child = p * 2 + 1;
	while (child < size) {
		//�����ӽڵ�Ϊ����ʱ����Ƚ����Ӻ��Һ��ӵĴ�С��������ӱ��Һ���С����Ѱ�child��Ϊ�Һ���
		if ((child < size - 1) && helist->element[child].key < helist->element[child + 1].key)
			child++;
		//�����ڵ�ֵ�Ⱥ��ӽڵ�(�������)Сʱ�������ӽڵ�ֵ�����������ڵ㣬ͬʱ���溢�ӽڵ��±굽���ڵ���±�p�������helist->element[p] = temp;�����ɸ��ڵ�ͺ��ӽڵ�ֵ�Ľ���
		if (temp.key < helist->element[child].key) {
			helist->element[p] = helist->element[child];
			p = child;
			child = 2 * p + 1;
		}
		else break;
	}
	//��ԭ�����ڵ�ֵ�������ڵĺ��ӽڵ㣬p������Ǻ��ӽڵ���±�
	helist->element[p] = temp;
}


void HeapSort(HeList helist) {
	int i, n;
	heNode temp;
	n = helist->n;
	//������ʼ�ѣ����ڲ��ڵ�Ϊÿ�������ĸ��ڵ㣬������������д��������
	for (i = n / 2 - 1; i >= 0; i--) {
		sift(helist, n, i);
	}
	//����n-1�˶�����
	for (i = n - 1; i > 0; i--) {
		//��ǰ�Ѷ��Ͷ�������¼����
		temp = helist->element[0];
		helist->element[0] = helist->element[i];
		helist->element[i] = temp;
		//���½��ѣ�i��n-1��ʼ����Ϊ��ʼ��n������Ѿ���ѡ�����ˣ�֮���n-1�����1���ж�����
		//���ڵ��0��ʼ��Ҳ���������������ĸ��ڵ㿪ʼ���½��ж�����ֱ������µĴ����
		sift(helist, i, 0);
	}
	//����γɵļ�¼��element���鱣�����������
	for (int j = 0; j < helist->n; j++) {
		printf_s("%d ", helist->element[j].key);
	}
}


int main() {
	int data;
	heNode he;
	HeList helist = CreateList(100);
	he.info = 0;
	fflush(stdin);
	while (cin >> data) {
		he.key = data;
		InsertList(helist, he);
		if (cin.get() == '\n')
			break;
	}
	HeapSort(helist);
	system("pause");
	return 0;
}
//vs关掉警告
#pragma warning(disable:4996) //全部關掉
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
		printf_s("超出空间\n");
		return NULL;
	}
	else {
		selist->element = (seNode *)malloc(sizeof(seNode));
		if (selist->element == NULL) {
			printf_s("超出空间\n");
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
		printf_s("超出空间\n");
	}
	else {
		if (selist->n > selist->MAXNUM) {
			printf_s("超出空间\n");
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
	//从把第i个与i后面的元素逐个对比，大则交换
	for (int i = 0; i < selist->n; i++) {
		data = selist->element[i].key;
		k = i;
		for (int j = i + 1; j < selist->n; j++) {
			//在i之后的元素中寻找比i元素小的，把k赋值为那个最小元素的下标
			if (selist->element[j].key < selist->element[k].key) {
				k = j;
			}
		}
		//把最小元素和第i个元素交换
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
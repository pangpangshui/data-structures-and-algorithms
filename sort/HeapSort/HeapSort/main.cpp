//vs关掉警告
#pragma warning(disable:4996) //全部關掉

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
		printf_s("超出空间\n");
		return NULL;
	}
	else {
		helist->element = (heNode *)malloc(sizeof(struct HeapNode));
		if (helist->element == NULL) {
			printf_s("超出空间\n");
			return NULL;
		}
		helist->n = 0;
		helist->MAXNUM = m;
		return helist;
	}
}


void InsertList(HeList helist,heNode he) {
	if (helist == NULL) {
		printf_s("超出空间\n");
		return;
	}
	else {
		if (helist->n > helist->MAXNUM) {
			printf_s("超出空间\n");
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
	//child为以p为根节点的树的孩子
	int child = p * 2 + 1;
	while (child < size) {
		//当孩子节点为左孩子时，需比较左孩子和右孩子的大小，如果左孩子比右孩子小，则把把child置为右孩子
		if ((child < size - 1) && helist->element[child].key < helist->element[child + 1].key)
			child++;
		//当根节点值比孩子节点(左或者右)小时，将孩子节点值赋给子树根节点，同时保存孩子节点下标到根节点的下标p，以配合helist->element[p] = temp;语句完成根节点和孩子节点值的交换
		if (temp.key < helist->element[child].key) {
			helist->element[p] = helist->element[child];
			p = child;
			child = 2 * p + 1;
		}
		else break;
	}
	//将原来根节点值赋给现在的孩子节点，p储存的是孩子节点的下标
	helist->element[p] = temp;
}


void HeapSort(HeList helist) {
	int i, n;
	heNode temp;
	n = helist->n;
	//建立初始堆，以内部节点为每颗子树的根节点，对这颗子树进行大根堆排序
	for (i = n / 2 - 1; i >= 0; i--) {
		sift(helist, n, i);
	}
	//进行n-1趟堆排序
	for (i = n - 1; i > 0; i--) {
		//当前堆顶和堆中最后记录互换
		temp = helist->element[0];
		helist->element[0] = helist->element[i];
		helist->element[i] = temp;
		//重新建堆，i从n-1开始，因为初始堆n的情况已经被选出来了，之后对n-1逐个减1进行堆排序
		//根节点从0开始，也就是整个二叉树的根节点开始往下进行堆排序，直至完成新的大根堆
		sift(helist, i, 0);
	}
	//最后形成的记录是element数组保存的升序排列
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
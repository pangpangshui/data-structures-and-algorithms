////vs关掉警告
//#pragma warning(disable:4996) //全部關掉
//
//#include <iostream>
//
//using namespace std;
//
//struct QuickNode {
//	int key;
//	int info;
//};
//typedef struct QuickNode quNode;
//
//struct QuickList {
//	int MAXNUM;
//	int n;
//	quNode *element;
//};
//typedef struct QuickList *quList;
//
//
//quList CreateList(int m) {
//	quList qulist = (quList)malloc(sizeof(struct QuickList));
//	if (qulist == NULL) {
//		printf_s("超出空间\n");
//		return NULL;
//	}
//	else {
//		qulist->n = 0;
//		qulist->MAXNUM = m;
//		qulist->element = (quNode *)malloc(sizeof(struct QuickNode));
//		if (qulist->element == NULL) {
//			printf_s("超出空间\n");
//			return NULL;
//		}
//		return qulist;
//	}
//}
//
//void InsertList(quList qulist, quNode qu) {
//	if (qulist == NULL) {
//		printf_s("超出空间\n");
//	}
//	else {
//		if (qulist->n > qulist->MAXNUM) {
//			printf_s("超出空间\n");
//		}
//		else {
//			qulist->element[qulist->n] = qu;
//			qulist->n = qulist->n + 1;
//		}
//	}
//}
//
//void QuickSort(quList qulist, int l, int r) {
//	quNode temp;
//	int i = l, j = r;
//	if (l >= r)
//		return;
//	temp = qulist->element[i];//放在循环外面，保证存储了分区标准(一般都是第一个元素)
//	//当左右分区标记点不重合就一直循环
//	while (i != j) {
//		//当右分区的值大于分区标准点的值，则一直往左移动右区间的标记点
//		while (i < j && temp.key <= qulist->element[j].key)
//			j--;
//		//跳出循环即表示右分区的某个值小于分区标准点的值，需要将它移动到左区间，移动后需要将左区间标记点往左移动1，即自增1，
//		//因为此时i下标存储的点即为刚刚移动过来的元素，所以不需要再次比较
//		if (i < j) {
//			qulist->element[i] = qulist->element[j];
//			i++;
//		}
//		//当左分区的值小于分区标准点的值，则一直往右移动左区间的标记点
//		while (i < j && temp.key >= qulist->element[i].key)
//			i++;
//		//跳出循环即表示左分区的某个值大于分区标准点的值，需要将它移动到右区间，移动后需要将右区间标记点往右移动1，即自减1，
//		//因为此时j下标存储的点即为刚刚移动过来的元素，所以不需要再次比较
//		if (i < j) { 
//			qulist->element[j] = qulist->element[i];
//			j--;
//		}
//	}
//	//当左右分区标记点重合将分区标准元素赋值到重合点，并且根据分出来的左右区间继续分区间并且递归
//	qulist->element[i] = temp;
//	QuickSort(qulist, l, i - 1);
//	QuickSort(qulist, i + 1, r);
//
//}
//
//
//int main() {
//	int data;
//	quNode qu;
//	quList qulist = CreateList(100);
//	qu.info = 0;
//	fflush(stdin);
//	while (cin >> data) {
//		qu.key = data;
//		InsertList(qulist,qu);
//		if (cin.get() == '\n')
//			break;
//	}
//	QuickSort(qulist, 0, qulist->n - 1);
//	for (int k = 0; k < qulist->n; k++) {
//		printf_s("%d ", qulist->element[k].key);
//	}
//	system("pause");
//	return 0;
//}
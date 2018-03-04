////vs关掉警告
//#pragma warning(disable:4996) //全部關掉
//
//#include <iostream>
//
//using namespace std;
//
//
//struct ShellNode {
//	int key;
//	int info;
//};
//typedef struct ShellNode shNode;
//
//struct ShellList {
//	int MAXUNUM;
//	int n;
//	shNode *element;
//};
//
//typedef struct ShellList *shList;
//
//
//shList CreateshList(int m) {
//	shList shlist = (shList)malloc(sizeof(struct ShellList));
//	if (shlist == NULL) {
//		printf_s("超出空间\n");
//		return shlist;
//	}
//	else {
//		shlist->n = 0;
//		shlist->MAXUNUM = m;
//		shlist->element = (shNode*)malloc(sizeof(ShellNode));
//		if (shlist->element == NULL) {
//			return shlist;
//		}
//		return shlist;
//	}
//}
//
//void InsertList(shList shlist,shNode element) {
//	if (shlist == NULL) {
//		printf_s("超出空间\n");
//	}
//	else {
//		if (shlist->n > shlist->MAXUNUM) {
//			printf_s("超出空间\n");
//		}
//		else {
//			shlist->element[shlist->n] = element;
//			shlist->n = shlist->n + 1;
//		}
//	}
//}
//
//
//
//void ShellSort(shList shlist) {
//	int i, j, inc;
//	shNode temp, *data = shlist->element;
//	//不断缩小增量d，从shlist->n / 2一半一半减
//	for (inc = shlist->n / 2; inc > 0; inc /= 2) {
//		//取增量区间的第一个元素
//		for (i = inc; i < shlist->n; i++) {
//			temp = data[i];
//			//取增量区间第一个元素的对应元素，即i-inc的元素进行比较，如果小于i-inc的元素，则大纪录后移
//			for (j = i - inc; j >= 0 && temp.key < data[j].key; j -= inc) {
//				data[j + inc] = data[j];
//			}
//			//经过上面一个循环后j会减去inc再跳出循环，所以此处应该加回去，再把高位的值赋给低位
//			data[j + inc] = temp;
//		}
//	}
//	
//	for (int k = 0; k < shlist->n; k++) {
//		printf_s("%d ", shlist->element[k].key);
//	}
//}
//
//
//int main() {
//	int data;
//	shNode element;
//	shList shlist = CreateshList(100);
//	element.info = 0;
//	while (cin >> data) {
//		element.key = data;
//		InsertList(shlist, element);
//		if (cin.get() == '\n')
//			break;
//	}
//	ShellSort(shlist);
//	system("pause");
//	return 0;
//}
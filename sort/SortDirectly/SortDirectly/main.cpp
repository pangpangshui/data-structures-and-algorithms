////vs关掉警告
//#pragma warning(disable:4996) //全部關掉
//#include <iostream>
//
//using namespace std;
//
//
//
//struct SortNode;
//typedef struct SortNode sNode;
//struct SortNode {
//	int key;
//	int info;
//};
//
//
//typedef struct SortDirectly {
//	int MAXNUM;
//	int n;
//	sNode *RecordNode;
//}SortObject;
//
//
//SortObject* CreateList(int m) {
//	SortObject *sortobject = (SortObject *)malloc(sizeof(SortObject));
//	if (sortobject == NULL) {
//		printf_s("没有空间\n");
//		return NULL;
//	}
//	else {
//		sortobject->RecordNode = (sNode *)malloc(sizeof(sNode));
//		if (sortobject->RecordNode) {
//			sortobject->MAXNUM = m;
//			sortobject->n = 0;
//			return sortobject;
//		}
//	}
//}
//
////插入顺序表
//void InsertList(SortObject *sortobject, sNode data) {
//	if (sortobject == NULL) {
//		printf_s("没有空间\n");
//	}
//	else {
//		sortobject->RecordNode[sortobject->n] = data;
//		sortobject->n = sortobject->n + 1;
//	}
//}
//
//void insertSort(SortObject *sortobject) {
//	int i, j;
//	sNode *data = sortobject->RecordNode;
//	sNode temp;
//	for (i = 1; i <= sortobject->n; i++) {
//		temp = data[i];
//		for (j = i - 1; temp.key < data[j].key && j >= 0; j--) {
//			data[j + 1] = data[j];
//		}
//		if (j != i - 1) {
//			data[j + 1] = temp;
//		}
//	}
//
//	for (i = 1; i <= sortobject->n; i++) {
//		printf_s("%d ", data[i].key);
//	}
//}
//
//int main() {
//	int data, n = 0;
//	SortObject *sortobject = CreateList(100);
//	sNode s;
//	s.info = 0;
//	while (cin >> data) {
//		s.key = data;
//		InsertList(sortobject, s);
//		if (cin.get() == '\n')
//			break;
//	}
//	
//	insertSort(sortobject);
//	return 0;
//}
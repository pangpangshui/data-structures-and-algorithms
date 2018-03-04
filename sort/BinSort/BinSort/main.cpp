////vs关掉警告
//#pragma warning(disable:4996) //全部關掉
//
//#include <iostream>
//
//using namespace std;
//
//typedef struct SortNode {
//	int key; 
//	int info;
//}sNode;
//
//
//typedef struct BinSortList {
//	int MAXNUM;
//	int n;
//	sNode *snode;
//}binSortList;
//
//
//binSortList* CreatList(int m) {
//	binSortList *binsort = (binSortList*)malloc(sizeof(binSortList));
//	if (binsort == NULL) {
//		printf_s("超出空间\n");
//		return NULL;
//	}
//	else {
//		binsort->snode = (sNode *)malloc(sizeof(sNode));
//		if (binsort->snode == NULL) {
//			printf_s("超出空间\n");
//			return NULL;
//		}
//		else {
//			binsort->MAXNUM = m;
//			binsort->n = 0;
//		}
//	}
//}
//
//
//void InsertList(binSortList *binsort,sNode data) {
//	if (binsort == NULL) {
//		printf_s("超出空间\n");
//	}
//	else {
//		if (binsort->n > binsort->MAXNUM) {
//			printf_s("超出范围\n");
//		}
//		else {
//			binsort->snode[binsort->n] = data;
//			binsort->n = binsort->n + 1;
//		}
//	}
//}
//
//
//void BinSort(binSortList *binsort) {
//	int mid, left, right, i, j;
//	sNode temp;
//	sNode *data = binsort->snode;
//	for (i = 1; i < binsort->n; i++) {
//		temp = data[i];
//		left = 0;
//		right = i - 1;
//		while (left <= right) {
//			mid = (left + right) / 2;
//			//此处通过比较要插入的值和中间位置值的大小关系，来确定left的大小，以确定之后排序码是否往后移位，如果移位移多少位
//			if (temp.key < data[mid].key) {
//				right = mid - 1;//关键的两步，可以缩短一半的比较
//			}
//			else
//				left = mid + 1;//关键的两步，可以缩短一半的比较
//			
//		}
//		//如果j>=left(即要插入的值比中间位置值小)，往后依次移动i-1到left之差的位置
//		for (j = i - 1; j >= left; j--) {
//			data[j + 1] = data[j];
//		}
//		//将要插入的值插在left的位置
//		if (left != i) {
//			data[left] = temp;
//		}
//	}
//
//	for (i = 0; i < binsort->n; i++) {
//		printf_s("%d ", data[i].key);
//	}
//}
//
//
//
//int main() {
//	int data;
//	sNode s;
//	s.info = 0;
//	binSortList *bin = CreatList(100);
//	fflush(stdin);
//	while (cin >> data) {
//		s.key = data;
//		InsertList(bin, s);
//		if (cin.get() == '\n')
//			break;
//	}
//	BinSort(bin);
//	//system("pause");
//	return 0;
//}
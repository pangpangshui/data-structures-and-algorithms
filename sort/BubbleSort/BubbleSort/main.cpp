////vs�ص�����
//#pragma warning(disable:4996) //ȫ���P��
//
//#include <iostream>
//
//using namespace std;
//
//struct BubbleNode {
//	int key;
//	int info;
//};
//typedef struct BubbleNode buNode;
//
//
//struct BubbleList {
//	int MAXNUM;
//	int n;
//	buNode *element;
//};
//
//typedef struct BubbleList *buList;
//
//
//buList CreateList(int m) {
//	buList bulist = (buList)malloc(sizeof(struct BubbleList));
//	if (bulist == NULL) {
//		printf_s("�����ռ�\n");
//		return NULL;
//	}
//	else {
//		bulist->n = 0;
//		bulist->MAXNUM = m;
//		bulist->element = (buNode *)malloc(sizeof(buNode));
//		if (bulist->element == NULL) {
//			printf_s("�����ռ�\n");
//			return NULL;
//		}
//		return bulist;
//	}
//}
//
//
//void InsertList(buList bulist, buNode ele) {
//	if (bulist == NULL) {
//		printf_s("�����ռ�\n");
//	}
//	else {
//		if (bulist->n > bulist->MAXNUM) {
//			printf_s("�����ռ�\n");
//		}
//		else {
//			bulist->element[bulist->n] = ele;
//			bulist->n = bulist->n + 1;
//		}
//	}
//}
//
//void BubbleSort(buList bulist) {
//	buNode temp;
//	bool flag;
//	for (int i = 0; i < bulist->n - 1; i++) {
//		flag = true;//�ô�����Ϊ��ĳһ��ð��û�з�������ʱ��ֱ�ӽ����㷨�����Խ�ʡ�Ƚϴ��������ٸ��Ӷ�(��δ�����е������Ѿ���һ����������м��ɷ�������)
//		for (int j = 0; j < bulist->n - i - 1; j++) {
//			if (bulist->element[j + 1].key < bulist->element[j].key) {
//				temp = bulist->element[j + 1];
//				bulist->element[j + 1] = bulist->element[j];
//				bulist->element[j] = temp;
//				flag = false;
//			}
//		}
//		if (flag == true)
//			break;
//	}
//	for (int k = 0; k < bulist->n; k++) {
//		printf_s("%d ", bulist->element[k].key);
//	}
//}
//
//
//
//int main() {
//	int data;
//	buNode ele;
//	ele.info = 0;
//	buList bulist = CreateList(100);
//	fflush(stdin);
//	while (cin >> data) {
//		ele.key = data;
//		InsertList(bulist, ele);
//		if (cin.get() == '\n')
//			break;
//	}
//	BubbleSort(bulist);
//	system("pause");
//	return 0;
//}
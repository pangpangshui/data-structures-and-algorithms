////vs�ص�����
//#pragma warning(disable:4996) //ȫ���P��
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
//		printf_s("�����ռ�\n");
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
//		printf_s("�����ռ�\n");
//	}
//	else {
//		if (shlist->n > shlist->MAXUNUM) {
//			printf_s("�����ռ�\n");
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
//	//������С����d����shlist->n / 2һ��һ���
//	for (inc = shlist->n / 2; inc > 0; inc /= 2) {
//		//ȡ��������ĵ�һ��Ԫ��
//		for (i = inc; i < shlist->n; i++) {
//			temp = data[i];
//			//ȡ���������һ��Ԫ�صĶ�ӦԪ�أ���i-inc��Ԫ�ؽ��бȽϣ����С��i-inc��Ԫ�أ�����¼����
//			for (j = i - inc; j >= 0 && temp.key < data[j].key; j -= inc) {
//				data[j + inc] = data[j];
//			}
//			//��������һ��ѭ����j���ȥinc������ѭ�������Դ˴�Ӧ�üӻ�ȥ���ٰѸ�λ��ֵ������λ
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
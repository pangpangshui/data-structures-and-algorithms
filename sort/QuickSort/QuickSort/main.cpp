////vs�ص�����
//#pragma warning(disable:4996) //ȫ���P��
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
//		printf_s("�����ռ�\n");
//		return NULL;
//	}
//	else {
//		qulist->n = 0;
//		qulist->MAXNUM = m;
//		qulist->element = (quNode *)malloc(sizeof(struct QuickNode));
//		if (qulist->element == NULL) {
//			printf_s("�����ռ�\n");
//			return NULL;
//		}
//		return qulist;
//	}
//}
//
//void InsertList(quList qulist, quNode qu) {
//	if (qulist == NULL) {
//		printf_s("�����ռ�\n");
//	}
//	else {
//		if (qulist->n > qulist->MAXNUM) {
//			printf_s("�����ռ�\n");
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
//	temp = qulist->element[i];//����ѭ�����棬��֤�洢�˷�����׼(һ�㶼�ǵ�һ��Ԫ��)
//	//�����ҷ�����ǵ㲻�غϾ�һֱѭ��
//	while (i != j) {
//		//���ҷ�����ֵ���ڷ�����׼���ֵ����һֱ�����ƶ�������ı�ǵ�
//		while (i < j && temp.key <= qulist->element[j].key)
//			j--;
//		//����ѭ������ʾ�ҷ�����ĳ��ֵС�ڷ�����׼���ֵ����Ҫ�����ƶ��������䣬�ƶ�����Ҫ���������ǵ������ƶ�1��������1��
//		//��Ϊ��ʱi�±�洢�ĵ㼴Ϊ�ո��ƶ�������Ԫ�أ����Բ���Ҫ�ٴαȽ�
//		if (i < j) {
//			qulist->element[i] = qulist->element[j];
//			i++;
//		}
//		//���������ֵС�ڷ�����׼���ֵ����һֱ�����ƶ�������ı�ǵ�
//		while (i < j && temp.key >= qulist->element[i].key)
//			i++;
//		//����ѭ������ʾ�������ĳ��ֵ���ڷ�����׼���ֵ����Ҫ�����ƶ��������䣬�ƶ�����Ҫ���������ǵ������ƶ�1�����Լ�1��
//		//��Ϊ��ʱj�±�洢�ĵ㼴Ϊ�ո��ƶ�������Ԫ�أ����Բ���Ҫ�ٴαȽ�
//		if (i < j) { 
//			qulist->element[j] = qulist->element[i];
//			j--;
//		}
//	}
//	//�����ҷ�����ǵ��غϽ�������׼Ԫ�ظ�ֵ���غϵ㣬���Ҹ��ݷֳ���������������������䲢�ҵݹ�
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
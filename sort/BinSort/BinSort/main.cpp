////vs�ص�����
//#pragma warning(disable:4996) //ȫ���P��
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
//		printf_s("�����ռ�\n");
//		return NULL;
//	}
//	else {
//		binsort->snode = (sNode *)malloc(sizeof(sNode));
//		if (binsort->snode == NULL) {
//			printf_s("�����ռ�\n");
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
//		printf_s("�����ռ�\n");
//	}
//	else {
//		if (binsort->n > binsort->MAXNUM) {
//			printf_s("������Χ\n");
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
//			//�˴�ͨ���Ƚ�Ҫ�����ֵ���м�λ��ֵ�Ĵ�С��ϵ����ȷ��left�Ĵ�С����ȷ��֮���������Ƿ�������λ�������λ�ƶ���λ
//			if (temp.key < data[mid].key) {
//				right = mid - 1;//�ؼ�����������������һ��ıȽ�
//			}
//			else
//				left = mid + 1;//�ؼ�����������������һ��ıȽ�
//			
//		}
//		//���j>=left(��Ҫ�����ֵ���м�λ��ֵС)�����������ƶ�i-1��left֮���λ��
//		for (j = i - 1; j >= left; j--) {
//			data[j + 1] = data[j];
//		}
//		//��Ҫ�����ֵ����left��λ��
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
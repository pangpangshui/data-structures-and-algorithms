

#include <iostream>


using namespace std;


struct ListNode;
typedef struct ListNode lNode;

struct ListNode {
	int key;
	int info;
	lNode *next;
};
typedef lNode *LinkList;

LinkList CreateLink() {
	LinkList linklist = (LinkList)malloc(sizeof(LinkList));
	if (linklist == NULL) {
		printf_s("û�пռ�\n");
	}
	else {
		linklist->info = 0;
		linklist->key = 0;
		linklist->next = NULL;
	}
	return linklist;
}


void InsertLink(LinkList linklist, int key) {
	lNode *l = (lNode *)malloc(sizeof(lNode));
	//LinkList llist = linklist;
	if (l == NULL) {
		printf_s("û�пռ�\n");
	}
	else {
		l->key = key;
		l->info = 0;
		l->next = NULL;
		while (linklist->next != NULL) {
			linklist = linklist->next;
		}
		linklist->next = l;
	}
}


//�˱��ʵ��������������
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	//	ListNode *p1 = pHead1->next;
	//	ListNode *p2 = pHead2->next;
	//	ListNode *temp1 = p1;
	//	ListNode *temp2;
	//	//if (p1 == NULL || p2 == NULL) {
	//	//    return NULL;
	//	//}
	//	while (p1 != NULL) {
	//		if (p1->key >= p2->key) {
	//			//temp1 = p1;
	//			//p1 = p1->next;
	//			temp2 = p2;
	//			while (p2 != NULL) {
	//				p2 = p2->next;
	//				if (p1->key >= p2->key) {
	//					p1->next = temp2;
	//					p2->next = p1->next->next;
	//				}
	//				else {
	//					temp2->next = p1->next;
	//					p1->next = temp2;
	//					break;
	//				}
	//			}
	//		}
	//		temp1 = p1;
	//		p1 = p1->next;
	//	}
	//	return p1;

		//�˷����൱�����´���һ��������������������һ��ָ����������ͷ��
		ListNode *mergehead = NULL;
		ListNode *current = NULL;
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		while (pHead1 != NULL && pHead2 != NULL) {
			if (pHead1->key <= pHead2->key) {//���phead1��ֵ��phead2��ֵС����phead1��������
				if (mergehead == NULL) {//��һ�βŻ���룬mergeheadָ��currentͷ�������ڷ���
					mergehead = current = pHead1;//��currentҲָ��phead1
				}
				else {//����ǵڶ��ν��룬��current��һ�ڵ�ָ��phead1������currentָ��β��
					current->next = pHead1;
					current = current->next;
				}
				pHead1 = pHead1->next;//phead1������һ���ڵ㣬�ٴ��ж�phead1��ֵ�Ƿ��phead2��ֵС
			}
			else {//���phead1��ֵ��phead2��ֵ����phead2��������
				if (mergehead == NULL) {//��һ�βŻ���룬mergeheadָ��currentͷ�������ڷ���
					mergehead = current = pHead2;//��currentҲָ��phead2
				}
				else {//����ǵڶ��ν��룬��current��һ�ڵ�ָ��phead2������currentָ��β��
					current->next = pHead2;
					current = current->next;
				}
				pHead2 = pHead2->next;//phead2������һ���ڵ㣬�ٴ��ж�phead1��ֵ�Ƿ��phead2��ֵС
			}
		}
		if (pHead1 == NULL)//���phead1���ߵ�β����phead2ʣ�ಿ�����ӵ�currentβ��
			current->next = pHead2;
		if (pHead2 == NULL)//���phead2���ߵ�β����phead1ʣ�ಿ�����ӵ�currentβ��
			current->next = pHead1;
		return mergehead;//����ָ��current������
	}
};


int main() {
	Solution *s = new Solution();
	LinkList list1 = CreateLink();
	LinkList list2 = CreateLink();
	//int data;
	//fflush(stdin);
	/*while (cin >> data) {
		InsertLink(list, data);
		if (cin.get() == '\n')
			break;
	}*/
	for (int i = 0; i < 10; i++) {
		InsertLink(list1, i);
	}
	for (int i = 0; i < 10; i = i + 2) {
		InsertLink(list2, i);
	}
	list1 = s->Merge(list1, list2);
	//fflush(stdin);
	return 0;
}
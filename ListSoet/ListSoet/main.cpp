//vs�ص�����
#pragma warning(disable:4996) //ȫ���P��

//#include <iostream>
//
//using namespace std;
//
//struct ListNode;
//typedef struct ListNode lNode;
//
//struct ListNode {
//	int key;
//	int info;
//	lNode *next;
//};
//typedef lNode *LinkList;
//
//LinkList CreateLink() {
//	LinkList linklist = (LinkList)malloc(sizeof(LinkList));
//	if (linklist == NULL) {
//		printf_s("û�пռ�\n");
//	}
//	else {
//		linklist->info = 0;
//		linklist->key = 0;
//		linklist->next = NULL;
//	}
//	return linklist;
//}
//
//
//void InsertLink(LinkList linklist,int key) {
//	lNode *l = (lNode *)malloc(sizeof(struct ListNode));
//	LinkList llist = linklist;
//	if (linklist == NULL) {
//		printf_s("û�пռ�\n");
//	}
//	else {
//		l->key = key;
//		l->info = 0;
//		l->next = NULL;
//		while (linklist->next != NULL) {
//			linklist = linklist->next;
//		}
//		linklist->next = l;
//	}
//}
//
//
//void printfLink(LinkList linklist) {
//	ListNode *head = linklist;
//	head = head->next;
//	while (head != NULL) {
//		
//		printf_s("%d ", head->key);
//		head = head->next;
//	}
//	printf_s("\n");
//}
//
//
//void ListSort(LinkList linklist) {
//	ListNode *pre, *now, *p, *q, *head;
//	head = linklist;
//	pre = head->next;
//	now = pre->next;
//	if (head == NULL || pre == NULL || now == NULL) {
//		return;
//	}
//	else {
//		while (now != NULL) {
//			q = head;//q��������һֱָ��ͷ��㣬ʹ��ÿ��ѭ��һ��ʼ����ͷ��ʼ�Ƚϣ������ƶ�
//			p = head->next;//p�����ú�q���ƣ�����Ѱ�ұ�δ�ȽϵĽڵ�ֵС�Ľڵ�
//			while (p != now && p->key <= now->key) {
//				q = p;
//				p = p->next;
//			}
//			//�����Ƿ��ҵ���Ҫ�Ľڵ㣬���p��now��λ���ص�������Ҫ��pre��now��λ�������ƣ���������
//			if (p == now) {
//				pre = pre->next;
//				now = pre->next;
//				continue;
//			}
//			//���p��now��λ�ò��ص�����ֱ�ӽ���pre��now�Ľڵ�
//			pre->next = now->next;
//			q->next = now;
//			now->next = p;
//			now = pre->next;
//		}
//	}
//	printfLink(head);
//}




//int main() {
//	int data;
//	LinkList linklist = CreateLink();
//	fflush(stdin);
//	while (cin >> data) {
//		InsertLink(linklist, data);
//		if (cin.get() == '\n')
//			break;
//	}
//
//	ListSort(linklist);
//	system("pause");
//	return 0;
//}
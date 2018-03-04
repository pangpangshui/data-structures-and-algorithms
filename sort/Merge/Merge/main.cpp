

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
		printf_s("没有空间\n");
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
		printf_s("没有空间\n");
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


//此编程实际上是链表排序
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

		//此方法相当于重新创建一个链表用来做排序，另外一个指向该新链表的头部
		ListNode *mergehead = NULL;
		ListNode *current = NULL;
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		while (pHead1 != NULL && pHead2 != NULL) {
			if (pHead1->key <= pHead2->key) {//如果phead1链值比phead2链值小，则将phead1链往下走
				if (mergehead == NULL) {//第一次才会进入，mergehead指向current头部，便于返回
					mergehead = current = pHead1;//将current也指向phead1
				}
				else {//如果是第二次进入，则将current下一节点指向phead1，并且current指向尾部
					current->next = pHead1;
					current = current->next;
				}
				pHead1 = pHead1->next;//phead1往下走一个节点，再次判断phead1链值是否比phead2链值小
			}
			else {//如果phead1链值比phead2链值大，则将phead2链往下走
				if (mergehead == NULL) {//第一次才会进入，mergehead指向current头部，便于返回
					mergehead = current = pHead2;//将current也指向phead2
				}
				else {//如果是第二次进入，则将current下一节点指向phead2，并且current指向尾部
					current->next = pHead2;
					current = current->next;
				}
				pHead2 = pHead2->next;//phead2往下走一个节点，再次判断phead1链值是否比phead2链值小
			}
		}
		if (pHead1 == NULL)//如果phead1先走到尾，则将phead2剩余部分链接到current尾部
			current->next = pHead2;
		if (pHead2 == NULL)//如果phead2先走到尾，则将phead1剩余部分链接到current尾部
			current->next = pHead1;
		return mergehead;//返回指向current的链表
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
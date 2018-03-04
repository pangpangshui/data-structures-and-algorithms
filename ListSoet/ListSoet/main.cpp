//vs关掉警告
#pragma warning(disable:4996) //全部關掉

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
//		printf_s("没有空间\n");
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
//		printf_s("没有空间\n");
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
//			q = head;//q的作用是一直指向头结点，使得每次循环一开始都从头开始比较，但不移动
//			p = head->next;//p的作用和q类似，用于寻找比未比较的节点值小的节点
//			while (p != now && p->key <= now->key) {
//				q = p;
//				p = p->next;
//			}
//			//不管是否找到需要的节点，如果p和now的位置重叠，则需要将pre和now的位置往后移，继续查找
//			if (p == now) {
//				pre = pre->next;
//				now = pre->next;
//				continue;
//			}
//			//如果p和now的位置不重叠，则直接交换pre和now的节点
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
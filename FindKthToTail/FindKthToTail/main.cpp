

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
	lNode *l = (lNode *)malloc(sizeof(struct ListNode));
	LinkList llist = linklist;
	if (linklist == NULL) {
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

class Solution {
public:
	ListNode* FindKthToTail(LinkList pListHead, unsigned int k) {
		LinkList node = pListHead, temp = pListHead;
		int num = 0;
		if (pListHead->next == NULL)
			return pListHead;
		while (temp->next != NULL) {
			temp = temp->next;
			num++;
		}
		if (k > num)
			return NULL;
		for (int i = num - k; i >= 0; i--) {
			node = node->next;
		}
		node->next = NULL;
		return node;
	}
};


int main() {
	Solution *s = new Solution();
	LinkList list = CreateLink();
	int data;
	fflush(stdin);
	while (cin >> data) {
		InsertLink(list, data);
		if (cin.get() == '\n')
			break;
	}
	list = s->FindKthToTail(list, 2);
	fflush(stdin);
	return 0;
}
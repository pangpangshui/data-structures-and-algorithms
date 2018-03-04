#include <iostream>

using namespace std;


typedef struct ListNode {
	int key;
	ListNode *next;
}LinkList;


typedef LinkList *list;


LinkList* CreateList() 
{
	list l = (list)malloc(sizeof(list));

	if (l == NULL)
	{
		printf("没空健");
		return NULL;
	}
	else {
		l->key = 0;
		l->next = NULL;
	}
	return l;
}


void printflist(list l)
{
	if (l == NULL)
		return;
	list head = l;
	head = head->next;
	while (head != NULL)
	{
		printf("%d ", head->key);
		head = head->next;
	}
	printf_s("\n");
}

void InsertList(list l, int data)
{
	list head = l;
	if (l == NULL)
	{
		return;
	}
	else {
		while (head->next != NULL)
		{
			head = head->next;
		}
		list temp = (list)malloc(sizeof(list));
		temp->key = data;
		temp->next = NULL;
		head->next = temp;
	}
	//printflist(head);
}



void ListSort(list l)
{
	list p, q, head, pre, now;
	head = l;
	pre = head->next;
	now = pre->next;
	if (head == NULL || pre == NULL)
	{
		return;
	}
	else {
		while (now != NULL)
		{
			q = head;
			p = head->next;
			while (p != now && p->key <= now->key)
			{
				q = p;
				p = p->next;
			}
			if (p == now)
			{
				now = now->next;
				pre = pre->next;
				continue;
			}
			//位置不重叠说明p->key > now->key, 交换pre和now的位置
			else
			{
				pre->next = now->next;
				q->next = now;
				now->next = p;
				now = pre->next;
			}
		}
		printflist(head);
	}
}




int main()
{
	int data;
	list ll = CreateList();
	while (cin >> data)
	{
		InsertList(ll, data);
		if (cin.get() == '\n')
			break;
	}
	ListSort(ll);
	system("pause");
	return 0;
}
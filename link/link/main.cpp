#include <iostream>

using namespace std;

struct Node;
typedef struct Node *pNode;
struct Node {
	int data;
	pNode next;
};

typedef struct Node *simplenode;

//���������ؿ�����,����ͷ���
simplenode CreatLink() {
	simplenode link = (simplenode)malloc(sizeof(struct Node));
	if (link == NULL) {
		printf_s("�ռ䲻��");
	}
	else {
		link->next = NULL;
	}
	return link;
}

//�ж������Ƿ�Ϊ��
bool isLinkNull(simplenode link) {
	return(link->next == NULL);
}

//����������Ϊx�Ľڵ�,�����ؽڵ�λ��
pNode locate_node(simplenode link, int x) {
	if (link->next == NULL) {
		printf_s("����Ϊ��");
	}
	else {
		pNode tempnode;
		tempnode = link->next;
		while (tempnode->next != NULL && tempnode->data != x) {
			tempnode = tempnode->next;
		}
		if (tempnode->next == NULL) {
			return NULL;
		}
		if (tempnode->data == x) {
			return tempnode;
		}
	}
}

//����p�ڵ��ǰ�����,�����ؽڵ�λ��
pNode locatePre_node(simplenode link, pNode p) {
	if (link->next == NULL) {
		printf_s("����Ϊ��");
	}
	else {
		pNode tempnode;
		tempnode = link;
		while (tempnode != NULL && tempnode->next != p) {
			tempnode = tempnode->next;
		}
		return tempnode;
	}
}

//��p��ָ�ڵ�����ֵΪx���½ڵ㣬�������Ƿ�ɹ�����ı�־
bool InsertPostNode(simplenode link, int x, pNode p) {
	pNode tempnode = (pNode)malloc(sizeof(struct Node));
	tempnode->data = x;
	tempnode->next = NULL;
	if (link == NULL)
		return false;
	else {
		tempnode->next = p->next;
		p->next = tempnode;
		return true;
	}
}

//��p��ָ�ڵ�ǰ����ֵΪx���½ڵ㣬�������Ƿ�ɹ�����ı�־
bool InsertPreNode(simplenode link, int x, pNode p) {
	pNode node = (pNode)malloc(sizeof(struct Node));
	node->data = x;
	if (link->next == NULL)
		return  false;
	locatePre_node(link, p);
	InsertPostNode(link, x, p);
	return true;
}

//ɾ��������Ϊx�Ľڵ�
bool DeleteNode(simplenode link, int x) {
	if (link->next == NULL)
		return  false;
	pNode temp = link;
	pNode q;
	while (temp->next != NULL && temp->next->data != x) {
		temp = temp->next;
	}
	if (temp->next == NULL) {
		printf_s("��������");
	}
	else {
		q = temp->next;
		temp->next = temp->next->next;
		q->next = NULL;
		free(q);
		return true;
	}
}

//ɾ��p��ָ�ڵ�
bool DeletePreNode(simplenode link, pNode p) {
	if (link->next == NULL) {
		return false;
	}
	pNode temp = locatePre_node(link, p);
	if (temp != NULL) {
		pNode q = temp->next;
		temp->next = temp->next->next;
		q->next = NULL;
		free(q);
		return true;
	}
	else
		printf_s("�Ҳ����ڵ�");
	
}

void DeleteRepeatedData(simplenode link) {
	if (link->next == NULL) {
		//return false;
	}
	simplenode link1 = link, link2 = link->next;
	pNode p;
	while (link1->next != NULL) {
		while (link1->next->data != link2->next->data) {
			link2 = link2->next;
		}
		
		if (link1->next->data == link2->next->data) {
			p = link1->next;
			link1->next = link1->next->next;
			p->next = NULL;
			free(p);
			//return true;
			link = link1;
			link2 = link->next;
		}
		else if(link2->next == NULL) {
			link1 = link1->next;			
		}
	}
}


//Ѱ�Ҵ�iλ�ÿ�ʼȡ����j���ַ����ɵ��Ӵ�
simplenode subLink(simplenode link, int i, int j) {
	simplenode l, temp, temp2;
	

	l = CreatLink();//���������ڴ洢Ѱ�ҵ����Ӵ������û�ҵ����������������������Ӵ�Ϊ��
	if (l == NULL) {
		printf_s("���벻���ռ�");
		return l;
	}

	if (i < 1 || j < 1) {
		return l;
	}
	temp = link;
	for (int k = 0; k < i; k++) {
		if (temp != NULL)
			temp = temp->next;
		else
			return l;
	}
	temp = temp->next;

	temp2 = l;
	for (int k = 1; k <= j; k++) {
		pNode p = (pNode)malloc(sizeof(struct Node));
		if (p == NULL) {
			printf_s("���벻�ɹ�");
		}
		else {
			p->data = temp->data;
			p->next = NULL;
			temp2->next = p;
			temp2 = p;
			temp = temp->next;
		}

	}
	temp2->next = NULL;
	return l;
}

int main()
{
	pNode p = (pNode)malloc(sizeof(struct Node));
	simplenode test = CreatLink();
	test->data = 0;
	test->next = NULL;
	
	p->data = 10;
	p->next = NULL;
	if (isLinkNull(test)) {
		//InsertPostNode(test, 0, test);
		for (int i = 0; i < 10; i++) {
			if (InsertPostNode(test, i, test)) {
				printf_s("����%d�ɹ�\n",i);
			}
			else
				printf_s("����%dʧ��\n", i);
		}
	}

	for (int i = 10; i < 20; i++) {
		if (InsertPreNode(test, i, test)) {
			printf_s("����%d�ɹ�\n", i);
		}
		else
			printf_s("����%dʧ��\n", i);
	}

	if (DeleteNode(test, 10)) {
		printf_s("ɾ���ɹ�\n");
	}
	subLink(test, 2, 10);

	DeletePreNode(test, p);
	//p->data = 11;
	InsertPostNode(test, 11, test);
	DeleteRepeatedData(test);
	
	return 0;
}
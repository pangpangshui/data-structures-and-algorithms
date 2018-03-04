//#include "stdafx.h"
#pragma warning (disable : 4996)

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct Stack
{
	int arr[MAXSIZE];
	int top;
}Stack;
Stack stack, stack2;
int pop(Stack *stack)
{
	int ret;
	if (stack->top <= -1)
		return -1;
	else
	{
		ret = stack->arr[stack->top]; stack->top--;
	}
	return ret;
}
int topVal(Stack *stack)
{
	return stack->arr[stack->top];
}


int position(Stack *stack)
{
	return stack->top;
}
int isEmpty(Stack *stack)
{
	if (stack->top>-1) return 0;
	else return 1;
}
void push(int num, Stack *stack)
{
	if (stack->top >= MAXSIZE)
		return;
	else
	{
		stack->top++;
		(stack->arr[stack->top] = num);
	}
}
typedef struct Node
{
	union
	{
		char exp;
		int a;
	} data;
	struct Node *next;
}Node;


int isExpression(int tmpExp) {
	if (tmpExp == '+' || tmpExp == '-' || tmpExp == '/' || tmpExp == '*' || tmpExp == '(' || tmpExp == ')')
		return 1;
	else
		return 0;
}
int isSuperior(int tmpExp, int tmpExp2) {


	if (tmpExp2 == '(' || (tmpExp == '/' || tmpExp == '*') && (tmpExp2 == '+' || tmpExp2 == '-'))  // �����������ȼ���͵ģ��ڶ�ջ���
		return 1;
	else return 0;


}
void printNode(Node* node)
{
	if (node)
	{
		char tmpExp = node->data.exp;
		if (isExpression(tmpExp))
			printf("%c", node->data.exp);
		else
			printf("%d", node->data.a);
		if (node)
			printNode(node->next);
	}
}


//ת��Ϊ��׺���ʽ
Node * head = NULL;
Node *  surfixExpCalculate(Node* node)
{
	Node * newnode = (Node*)malloc(sizeof(Node));
	Node * tmpNode;
	head = tmpNode = newnode;
	head->data.exp = ' ';
	head->data.a = 0;
	while (node = node->next)
	{


		if (!(isExpression(node->data.exp)))                //�ο��������������ǰ���ֱֵ�ӱ��浽��׺���ʽ�������stack��ջֻ����������ʽ
		{
			newnode = (Node*)malloc(sizeof(Node));
			newnode->next = 0;
			newnode->data.a = node->data.a;
			tmpNode->next = newnode;
			tmpNode = newnode;
		}
		else
		{
			char tmpExp = node->data.exp;
			if (tmpExp == '(')         //������ֱ����ջ��
			{
				push(tmpExp, &stack);

			}
			else if (tmpExp == ')') //���������ţ��Ѷ�ջ��ı��ʽȫ��������ֱ������������
			{
				while (!isEmpty(&stack) && topVal(&stack) != '(')
				{
					newnode = (Node*)malloc(sizeof(Node));
					newnode->next = 0;
					newnode->data.exp = pop(&stack);

					tmpNode->next = newnode;
					tmpNode = newnode;
				}
				pop(&stack);   // //�����ŵ���ջ��
			}
			else
			{
				if (isEmpty(&stack) || isSuperior(tmpExp, topVal(&stack)))  //��ջ�ջ��߱��ʽ��ջ���ߣ���ջ
				{
					push(tmpExp, &stack);
				}
				else
				{
					while (!isEmpty(&stack) && !isSuperior(tmpExp, topVal(&stack))) //��ջ�ǿջ��߱��ʽ���ȼ���ջ���ף����׳�ջ��������ʽ��֪��������ջ�����ȸ�Ϊֹ
					{
						newnode = (Node*)malloc(sizeof(Node));
						newnode->next = 0;
						newnode->data.exp = pop(&stack);

						tmpNode->next = newnode;
						tmpNode = newnode;

					};

					push(tmpExp, &stack);
				}
			}


		}


	}
	while (!isEmpty(&stack))
	{
		newnode = (Node*)malloc(sizeof(Node));
		newnode->next = 0;
		newnode->data.a = pop(&stack);

		tmpNode->next = newnode;
		tmpNode = newnode;
	}


	return head;


}

typedef struct Stack2                       //Ϊ�����¼����׺���ʽ��ֵ�����¶����˺�double���ͳ�Ա��stack2
{
	double arr[MAXSIZE];
	int top;
}Stack2;
void push(double num, Stack2 *stack)
{
	if (stack->top >= MAXSIZE)
		return;
	else
	{
		stack->top++;
		(stack->arr[stack->top] = num);
	}
}


double pop(Stack2 *stack)
{
	double ret;
	if (stack->top <= -1)
		return -1;
	else
	{
		ret = stack->arr[stack->top]; stack->top--;
	}
	return ret;
}
// ��׺���ʽ��ֵ����
double postFixEval(Node * head)
{
	double val = 0;
	Node * node = head->next;
	Stack2 stack2;  //�õ�another��ջ�������׺���ʽ���
	stack2.top = -1;
	while (node)
	{
		if (!isExpression(node->data.exp))
		{
			push(node->data.a, &stack2);
		}
		else
		{
			double op1 = pop(&stack2);
			double op2 = pop(&stack2);


			switch (node->data.exp)
			{
			case '+':
				val = op1 + op2;
				break;
			case '-':
				val = op2 - op1;
				break;
			case '*':
				val = op1 * op2;
				break;
			case '/':
				val = op2 / op1;
				break;
			}
			push(val, &stack2);
		}
		node = node->next;


	}


	return val = pop(&stack2);
}


int main(int argc, char* argv[])
{
	stack.top = -1;
	stack2.top = -1;
	Node * head;
	int i = 0, length = 0;
	char buf[1024];
	char* tmpExp, sep[] = " ";
	char *p = NULL;
	head = (Node*)malloc(sizeof(Node));
	head->data.exp = ' ';
	head->data.a = 0;
	head->next = 0;


	gets_s(buf);
	tmpExp = buf;
	Node* tmpExpNode = head;
	while (p = strtok(tmpExp, sep))
	{


		Node * node = (Node*)malloc(sizeof(Node));
		node->next = 0;
		// printf("%s",p); p is a point to  string (not a point to a char)
		if (strcmp(p, "+") == 0 || strcmp(p, "+") == 0 || strcmp(p, "-") == 0 || strcmp(p, "*") == 0 || strcmp(p, "/") == 0 || strcmp(p, "(") == 0 || strcmp(p, ")") == 0)
			sscanf(p, "%c", &node->data.exp);
		else
			sscanf(p, "%d", &node->data.a);

		tmpExpNode->next = node;
		tmpExpNode = node;
		tmpExp = 0;
	}
	head = surfixExpCalculate(head);
	head = surfixExpCalculate(head);
	//printNode(head->next);

	postFixEval(head);
	return 0;
}
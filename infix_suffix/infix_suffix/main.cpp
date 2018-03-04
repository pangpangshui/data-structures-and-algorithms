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


	if (tmpExp2 == '(' || (tmpExp == '/' || tmpExp == '*') && (tmpExp2 == '+' || tmpExp2 == '-'))  // 左括号是优先级最低的（在堆栈里），
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


//转换为后缀表达式
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


		if (!(isExpression(node->data.exp)))                //参考文章有误，这里是把数值直接保存到后缀表达式链表里，而stack堆栈只用来保存表达式
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
			if (tmpExp == '(')         //左括号直接入栈，
			{
				push(tmpExp, &stack);

			}
			else if (tmpExp == ')') //碰到右括号，把堆栈里的表达式全部弹出，直到遇到左括号
			{
				while (!isEmpty(&stack) && topVal(&stack) != '(')
				{
					newnode = (Node*)malloc(sizeof(Node));
					newnode->next = 0;
					newnode->data.exp = pop(&stack);

					tmpNode->next = newnode;
					tmpNode = newnode;
				}
				pop(&stack);   // //左括号弹出栈，
			}
			else
			{
				if (isEmpty(&stack) || isSuperior(tmpExp, topVal(&stack)))  //堆栈空或者表达式比栈顶高，入栈
				{
					push(tmpExp, &stack);
				}
				else
				{
					while (!isEmpty(&stack) && !isSuperior(tmpExp, topVal(&stack))) //堆栈非空或者表达式优先级比栈顶底，顶底出栈，计算表达式，知道遇到比栈顶优先高为止
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

typedef struct Stack2                       //为了重新计算后缀表达式数值，重新定义了含double类型成员的stack2
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
// 后缀表达式求值程序
double postFixEval(Node * head)
{
	double val = 0;
	Node * node = head->next;
	Stack2 stack2;  //用到another堆栈，计算后缀表达式结果
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
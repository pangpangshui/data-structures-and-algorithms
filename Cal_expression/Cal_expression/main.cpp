#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


struct Node;
typedef struct Node *pNode;

struct Node {
	char c;
	pNode next;
};

struct pStack
{
	pNode top;
};

typedef struct pStack *Stacklink;

//创建空栈
Stacklink CreateStack() {
	Stacklink stacklink = (Stacklink)malloc(sizeof(struct pStack));
	if (stacklink == NULL) {
		printf_s("没空间\n");
	}
	else {
		stacklink->top = NULL;
	}
	return stacklink;
}


//判空
bool isStackEmpty(Stacklink stacklink) {
	if (stacklink->top == NULL)
		return true;
	else
		return false;
}


//入栈
void pushStack(Stacklink stacklink, char c) {
	pNode node = (pNode)malloc(sizeof(struct Node));
	if (stacklink == NULL) {
		printf_s("没空间\n");
	}
	else {
		node->next = stacklink->top;
		node->c = c;
		stacklink->top = node;
	}
}

//出栈
void popStack(Stacklink stacklink) {
	pNode p;
	if (stacklink == NULL) {
		printf_s("没空间\n");
	}
	else {
		p = stacklink->top;
		stacklink->top = stacklink->top->next;
		free(p);
	}
}


//取得栈顶元素
char getTop(Stacklink stacklink) {
	if (stacklink->top == NULL) {
		return NULL;
		printf_s("没空间\n");
	}
	else {
		return stacklink->top->c;
	}
}


char* infixTosuffix(Stacklink stacklink, char *infix) {
	string out;
	for (int i = 0; i < strlen(infix); i++) {
		if (infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/' && infix[i] != '(' && infix[i] != ')') {
			out += infix[i];
		}
		else {
			
			if (infix[i] == '*' || infix[i] == '/') {
				pushStack(stacklink, infix[i]);
			}
			else if (infix[i] == '+' || infix[i] == '-') {
				if (getTop(stacklink) == '*' || getTop(stacklink) == '/') {
					//out += " ";
					out += getTop(stacklink);
					popStack(stacklink);
					pushStack(stacklink, infix[i]);
				}
				else {
					pushStack(stacklink, infix[i]);
				}
			}
			else if (infix[i] == '(') {
				pushStack(stacklink, infix[i]);
				while (infix[i++] != ')') {
					if (infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/' && infix[i] != '(' && infix[i] != ')') {
						
						out += infix[i];
					}
					else {
						out += " ";
						pushStack(stacklink, infix[i]);
					}						
				}
				i--;
				popStack(stacklink);
				while (getTop(stacklink) != '(') {
					if (getTop(stacklink) != '(') {
						//out += " ";
						out += getTop(stacklink);
						popStack(stacklink);
					}
				}
				popStack(stacklink);
			}
			out += " ";
		}
	}
	while (!isStackEmpty(stacklink)) {
		//out += " ";
		out += getTop(stacklink);
		popStack(stacklink);
	}
	//cout << out;
	char suffix[1000] = "";
	strcpy_s(suffix, out.c_str());
	return suffix;
}

void CalExpression(char *suffix) {
	string s1 = "", s2 = "";
	int temp1, temp2;
	long sum = 0;
	
	char c[50];
	Stacklink ps = CreateStack();
	for (int i = 0; i < strlen(suffix); i++) {
		if (suffix[i] != '+' && suffix[i] != '-' && suffix[i] != '*' && suffix[i] != '/') {
			pushStack(ps, suffix[i]);
		}
		else {
			int j = 0;
			while (j < 1) {
				if (getTop(ps) == ' ') {
					popStack(ps);
				}
				s1 += getTop(ps);
				popStack(ps);
				if (getTop(ps) == ' ') {
					popStack(ps);
					do {
						s2 += getTop(ps);
						popStack(ps);
					} while (getTop(ps) != ' ' && !isStackEmpty(ps));
					j++;
				}
			}
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			stringstream ss1;
			stringstream ss2;
			ss1 << s1;
			ss2 << s2;
			ss1 >> temp1;
			ss2 >> temp2;
			if (suffix[i] == '-') 
				sum = temp2 - temp1;
			if (suffix[i] == '+')
				sum = temp2 + temp1;
			if (suffix[i] == '*')
				sum = temp2 * temp1;
			if (suffix[i] == '/')
				sum = temp2 / temp1;
			//sscanf_s(c, "%ld", &sum);
			_itoa_s(sum, c, 10);
			for (int k = 0; k < strlen(c); k++) {
				pushStack(ps, c[k]);
			}
			s1 = "", s2 = "";
			//pushStack(ps, (char)sum / (long)sum);
		}
	}
	cout << c;
}

int main() {
	Stacklink expression = CreateStack();
	/*for (int i = 65; i < 75; i++) {
		pushStack(expression, i);
	}

	for (int i = 0; i < 10; i++) {
		cout << getTop(expression);
		popStack(expression);
	}*/

	char infix[1000] = "",suffix_in[1000] = "";
	cin >> infix;
	char *suffix = infixTosuffix(expression, infix);
	cout << suffix;

	for (int i = 0; i < strlen(suffix); i++) {
		suffix_in[i] = suffix[i];
	}

	cout << endl;
	CalExpression(suffix_in);
	//cout << suff << endl;;

	return 0;
}
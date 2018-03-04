#include <iostream>

using namespace std;

#define M 8
#define N 11
int maze[M][N] = { { 1,1,1,1,1,1,1,1,1,1,1 },
{ 1,0,1,0,0,1,1,1,0,0,1 },
{ 1,0,0,0,0,0,1,0,0,1,1 },
{ 1,0,1,1,1,0,0,0,1,1,1 },
{ 1,0,0,0,1,0,1,1,0,1,1 },
{ 1,1,0,0,1,0,1,1,0,0,1 },
{ 1,1,1,0,0,0,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1 } };
int direction[4][4] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };


typedef struct {
	int x, y, d;
}DataType;

struct Stack;
typedef struct Stack *Stacklink;
struct Stack {
	int MAXNUM;
	int t;//ջ��λ��
	DataType *da;
};


//������ջ
Stacklink CreateStack(int m) {
	Stacklink stacklink = (Stacklink)malloc(sizeof(struct Stack));
	if (stacklink == NULL) {
		printf_s("������Χ1\n");
		return NULL;
	}
	else {
		stacklink->da = (DataType *)malloc(sizeof(DataType) * m);
		if (stacklink->da) {
			stacklink->MAXNUM = m;
			stacklink->t = -1;//ջ��
			return stacklink;
		}
		else
			free(stacklink);
	}
}

//�п�--ջ
bool isStackEmpty(Stacklink stacklink) {
	if (stacklink->t == -1) {
		return true;
	}
	else
		return false;
}

//��ջ
void pushStack(Stacklink stacklink, DataType sdata) {
	if (stacklink->t > stacklink->MAXNUM - 1) {
		printf_s("������Χ2\n");
	}
	else {
		stacklink->t = stacklink->t + 1;
		stacklink->da[stacklink->t] = sdata;
	}
}

//��ջ
void popStack(Stacklink stacklink) {
	if (stacklink->t == -1) {
		printf_s("������Χ3\n");
	}
	else {
		stacklink->t = stacklink->t - 1;
	}
}


//ȡջ��Ԫ��
DataType getStackTop(Stacklink stacklink) {
	if (stacklink->t == -1) {
		printf_s("������Χ4\n");
		//return stacklink->da[stacklink->t];
	}
	else {
		return stacklink->da[stacklink->t];
	}
}

void mazepath(int(*maze)[N], int(*direction)[4], int x1, int y1, int x2, int y2, int m, int n) {
	int i, j, k;
	int g, h;
	Stacklink st;
	DataType element;
	st = CreateStack(m * n);
	maze[x1][y1] = 2;
	element.x = x1;
	element.y = y1;
	element.d = -1;
	pushStack(st, element);
	while (!isStackEmpty(st)) {   //�˲������ڻ���
		element = getStackTop(st);
		popStack(st);
		i = element.x;
		j = element.y;
		k = element.d + 1;
		while (k <= 3) {
			g = i + direction[k][0];
			h = j + direction[k][1];

			if (maze[g][h] == 0) {
				maze[g][h] = 2;
				element.x = i;
				element.y = j;
				element.d = k;
				pushStack(st, element);
				i = g;
				j = h;
				k = -1;
				if (g == x2 && h == y2) {   //���ڵ�
					printf_s("·��:\n");
					element.x = x2;
					element.y = y2;
					element.d = -1;
					pushStack(st, element);
					while (!isStackEmpty(st)) {
						element = getStackTop(st);
						popStack(st);
						printf_s("%d,%d\n", element.x, element.y);
					}
					return;
				}
			}
			k = k + 1;
		}
	}
	printf_s("�Ҳ���·��");
}


int main() {
	/*for (int i = 0; i < 10; i++) {
	for (int j = 0; j < 10; j++) {
	maze[i][j] = 1;
	}
	}
	maze[1][1] = 0, maze[1][3] = 0, maze[1][4] = 0,*/
	mazepath(maze, direction, 1, 1, M - 2, N - 2, M, N);

	return 0;
}
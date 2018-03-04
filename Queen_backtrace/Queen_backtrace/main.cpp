#pragma warning(disable:4996) //全部關掉
#include <iostream>

using namespace std;


bool place(int *xx, int k) {
	//前k-1行
	for (int j = 0; j < k; j++) {
		//判断前k-1行是否有某行的皇后和第k行的皇后是否在同一列或者同一斜线
		if ((xx[j] == xx[k]) || (abs(j - k) == abs(xx[j] - xx[k]))) {
			return false;
		}
	}
	return true;
}


void Queens(int *x, int n) {
	int count = 0;
	int k = 1;//当前行
	x[k] = 0;//当前列
	while (k > 0) {
		x[k]++;//第一次执行时，代表第一行第一列

		//判断前k-1行是否有某行的皇后和第k行的皇后是否在同一列或者同一斜线
		while (x[k] <= n && !place(x, k)) {
			x[k]++;//在行不变的情况下不断增加列数，查看是否有皇后不相互攻击的；大于n列或者发现有符合情况的退出循环
		}

		//当列数小于等于n则继续判断
		if (x[k] <= n) {
			//行数等于n时可以输出问题的解了
			if (k == n) {
				for (int m = 1; m <= n; m++) {
					printf_s("%d ", x[m]);
				}
				printf_s("%d", count++);
				printf_s("\n");
			}
			//如果行数小于n则继续增加行数到下一行，并且将列数归0，以便下一次进行
			else {
				k++;
				x[k] = 0;
			}
		}
		//如果列数大于n还没找到结果，则需要回溯，回溯方法为将行数减1，即退到上一行，同时x[k]也产生变化，
		//由于x[k]储存了之前符合条件的列数，k减1的同时，也取出上一行的x[k]列的下一列，此处类似于栈的出栈，x即为栈
		else
			k--;
	}
}


int main() {
	int n;
	scanf("%d", &n);
	int *x;
	x = (int*)malloc(sizeof(int) * (n + 1));
	Queens(x, n);
	return 0;
}
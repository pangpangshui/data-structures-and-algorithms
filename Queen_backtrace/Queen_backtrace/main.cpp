#pragma warning(disable:4996) //ȫ���P��
#include <iostream>

using namespace std;


bool place(int *xx, int k) {
	//ǰk-1��
	for (int j = 0; j < k; j++) {
		//�ж�ǰk-1���Ƿ���ĳ�еĻʺ�͵�k�еĻʺ��Ƿ���ͬһ�л���ͬһб��
		if ((xx[j] == xx[k]) || (abs(j - k) == abs(xx[j] - xx[k]))) {
			return false;
		}
	}
	return true;
}


void Queens(int *x, int n) {
	int count = 0;
	int k = 1;//��ǰ��
	x[k] = 0;//��ǰ��
	while (k > 0) {
		x[k]++;//��һ��ִ��ʱ�������һ�е�һ��

		//�ж�ǰk-1���Ƿ���ĳ�еĻʺ�͵�k�еĻʺ��Ƿ���ͬһ�л���ͬһб��
		while (x[k] <= n && !place(x, k)) {
			x[k]++;//���в��������²��������������鿴�Ƿ��лʺ��໥�����ģ�����n�л��߷����з���������˳�ѭ��
		}

		//������С�ڵ���n������ж�
		if (x[k] <= n) {
			//��������nʱ�����������Ľ���
			if (k == n) {
				for (int m = 1; m <= n; m++) {
					printf_s("%d ", x[m]);
				}
				printf_s("%d", count++);
				printf_s("\n");
			}
			//�������С��n�����������������һ�У����ҽ�������0���Ա���һ�ν���
			else {
				k++;
				x[k] = 0;
			}
		}
		//�����������n��û�ҵ����������Ҫ���ݣ����ݷ���Ϊ��������1�����˵���һ�У�ͬʱx[k]Ҳ�����仯��
		//����x[k]������֮ǰ����������������k��1��ͬʱ��Ҳȡ����һ�е�x[k]�е���һ�У��˴�������ջ�ĳ�ջ��x��Ϊջ
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
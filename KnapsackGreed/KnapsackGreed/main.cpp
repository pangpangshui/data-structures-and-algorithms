#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

struct Good {
	float p;//价值
	float w;//重量
	float x;//价值/重量
	float load;//分数
};
typedef struct Good good;

//struct AllGoods {
//	int num;
//	good *g;
//};
//typedef struct AllGoods *allGoods;


int cmp(good const g1, good const g2) {
	if (g1.x < g2.x)
		return 0;
	else
		return 1;
}


float Knapsack(good *g, float m, int n) {
	int i = 0;
	float s = 0;
	while (i < n && g[i].w < m) {
		m = m - g[i].w;
		s += g[i].p;
		g[i].x = 1;
		i++;
	}
	if (i < n) {
		s += g[i].p * m / g[i].w;
		g[i].x = m / g[i].w;
		i++;
	}
	for (; i < n; i++) {
		g[i].x = 0;
	}
	return s;
}


int main() {
	float p[20];
	float w[20];
	float x[20] = {0};
	int num = 0;
	sqrt(0);
	while (cin >> p[num]) {
		num++;
		if (cin.get() == '\n' || num >= 20)
			break;
	}
	num = 0;
	while (cin >> w[num]) {
		num++;
		if (cin.get() == '\n' || num >= 20)
			break;
	}
	good g[20];
	for (int i = 0; i < num; i++) {
		g[i].p = p[i];
		g[i].w = w[i];
		g[i].x = g[i].p / g[i].w;
		g[i].load = 0;
	}

	sort(g, g + num + 1, cmp);

	Knapsack(g, 20, num);
	system("pause");
	return 0;
}
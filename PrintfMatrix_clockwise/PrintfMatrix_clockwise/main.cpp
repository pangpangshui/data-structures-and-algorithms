//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
//例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.


//思路:从左到右，从上到下，从右到左，从下到上一次扫描并扫入新的vector。循环次数为圈数
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int i = 0, j = 0, k = 0, m = 0;
		int n = matrix.size();
		int q = matrix[0].size();
		int circle = ((n < q ? n : q) - 1) / 2 + 1;//圈数
		vector<int> newlist;
		for (int p = 0; p < circle; p++) {
			for (j = p; j < q - p; j++) {
				newlist.push_back(matrix[p][j]);
			}
			for (i = p + 1; i < n - p; i++) {
				newlist.push_back(matrix[i][q - p - 1]);
			}
			for (k = q - 2 - p; (k >= p) && (n - p - 1 != p); k--) {
				newlist.push_back(matrix[n - 1 - p][k]);
			}
			for (m = n - 2 - p; (m >= p + 1) && (q - p - 1 != p); m--) {
				newlist.push_back(matrix[m][p]);
			}
		}
		return newlist;
	}
};


int main() {
	vector<vector<int> > matrix(2);
	vector<vector<int> > matrix2(5);
	Solution *s = new Solution();
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].resize(2);
	}
	for (int p = 0; p < 2; p++) {
		for (int j = 0; j < 2; j++) {
			matrix[p][j] = p * 2 + j + 1;
		}
	}

	for (int i = 0; i < matrix2.size(); i++) {
		matrix2[i].resize(1);
	}
	/*for (int p = 0; p < 1; p++) {
		for (int j = 0; j < 1; j++) {
			matrix2[p][j] = 1;
		}
	}*/
	matrix2[0][0] = 1;
	matrix2[1][0] = 2;
	matrix2[2][0] = 3;
	matrix2[3][0] = 4;
	matrix2[4][0] = 5;

	vector<int> list = s->printMatrix(matrix2);
	for (int i = 0; i < list.size(); i++) {
		printf_s("%d ", list[i]);
	}
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		//	//通过，但是运行时间大于1s
		//	int rowlength = array.size();
		//	int left = 0, right = rowlength - 1;
		//	int mid = (left + right) / 2;
		//	while (left < right) {
		//		if (target < array[mid][mid]) {
		//			for (int i = 0; i < mid; i++) {
		//				if (target == array[mid][i] || target == array[i][mid])
		//					return true;
		//				right = mid;
		//			}
		//		}
		//		else if (target > array[mid][mid]) {
		//			for (int i = 0; i < mid; i++) {
		//				if (target == array[mid][i] || target == array[i][mid])
		//					return true;
		//				left = mid;
		//			}
		//		}
		//		mid = (left + right) / 2;
		//	}
		//	return false;
		//}

		//运行时间10ms，i >= 0&&j < collen，此处应用&&连接
		int rowlen = array.size();
		int collen = array[0].size();
		//去左下角元素作为开始起点
		int i, j;
		for (i = rowlen - 1, j = 0; i >= 0 && j < collen;) {
			if (target == array[i][j]) {
				return true;
			}
			if (target > array[i][j]) {
				j++;
				continue;
			}
			if (target < array[i][j]) {
				i--;
				continue;
			}
		}
		return false;
	}
};



void main() {
	int n, data, target;
	vector<int> temp;
	vector<vector<int> > array;
	Solution *sl = new Solution();
	cin >> n;
	//array.resize(n);
	for (int i = 0; i < n; i++) {
		temp.clear();
		for (int j = 0; j < n; j++) {
			cin >> data;
			temp.push_back(data);
		}
		array.push_back(temp);
	}
	cin >> target;
	sl->Find(target, array);
}
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
//并保证奇数和奇数，偶数和偶数之间的相对位置不变。

//根据题意，此题是排序，而且要求算法稳定，我选用的是直接插入排序

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int temp, oddindex = 0, evenindex, k;
		for (int i = 0; i < array.size(); i++) {
			temp = array[i];
			for (k = i - 1; temp % 2 == 1 && k >= 0; k--) {
				if (array[k] % 2 == 1)
					break;
				array[k + 1] = array[k];
			}
			if (k != i - 1) {
				array[k + 1] = temp;
			}
		}
	}
};


int main() {
	vector<int> array = { 2,4,6,1,3,5,7 };
	Solution *s = new Solution();
	s->reOrderArray(array);
	return 0;
}
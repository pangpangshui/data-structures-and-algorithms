//����һ���������飬ʵ��һ�����������������������ֵ�˳��
//ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�
//����֤������������ż����ż��֮������λ�ò��䡣

//�������⣬���������򣬶���Ҫ���㷨�ȶ�����ѡ�õ���ֱ�Ӳ�������

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
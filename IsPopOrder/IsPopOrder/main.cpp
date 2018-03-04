//输入两个整数序列，第一个序列表示栈的压入顺序，
//请判断第二个序列是否为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。
//例如序列1, 2, 3, 4, 5是某栈的压入顺序，
//序列4，5, 3, 2, 1是该压栈序列对应的一个弹出序列，
//但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

//使用一个辅助栈，依次将压栈序列的元素入栈，同时判断出栈序列的元素与栈顶元素是否相等。
//此处使用vector作为栈

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		bool flag = false;
		vector<int> temp;
		for (int i = 0; i < pushV.size(); i++) {
			temp.push_back(pushV[i]);
			while (temp.at(temp.size() - 1) == popV[0]) {
				temp.pop_back();
				popV.erase(popV.begin());
				if (temp.empty() && popV.empty()) {
					flag = true;
					break;
				}
			}
			
		}
		return flag;

		//int i = 0, j = 0;
		//bool flag = false;
		//for (vector<int>::iterator iter = pushV.begin(); iter != pushV.end(); iter++) {
		//	if (popV.at(0) == pushV.at(i)) {
		//		pushV.erase(iter);
		//		popV.erase(popV.begin());
		//		i--;
		//		if (pushV.at(i) == popV.at(0)) {
		//			pushV.erase(iter--);
		//			popV.erase(popV.begin());
		//			i--;
		//		}
		//		else if (pushV.at(i - 1) == popV.at(0)) {
		//			pushV.erase(iter - 2);
		//			popV.erase(popV.begin());
		//			i--;
		//		}
		//		else if (i + 1 < pushV.size()) {
		//			if (pushV.at(i + 1) == popV.at(0)) {
		//				pushV.erase(iter);
		//				popV.erase(popV.begin());
		//				i--;
		//			}
		//		}
		//		if (pushV.empty() && popV.empty())
		//			flag = true;
		//		/*for (int j = 0; j < popV.size(); j++) {
		//			pushV
		//		}*/
		//	}
		//	i++;
		//}
		//return flag;
	}
};

int main() {
	Solution *s = new Solution();
	vector<int> pushv = { 1,2,3,4,5 };
	vector<int> popv = { 4,5,3,2,1 };
	s->IsPopOrder(pushv, popv);
}
//���������������У���һ�����б�ʾջ��ѹ��˳��
//���жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ�
//��������1, 2, 3, 4, 5��ĳջ��ѹ��˳��
//����4��5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
//��4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

//ʹ��һ������ջ�����ν�ѹջ���е�Ԫ����ջ��ͬʱ�жϳ�ջ���е�Ԫ����ջ��Ԫ���Ƿ���ȡ�
//�˴�ʹ��vector��Ϊջ

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
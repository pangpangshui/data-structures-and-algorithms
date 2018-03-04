#include <iostream>
#include <vector>

using namespace std;
//ţ��������ͨ��
//��Ŀ:����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> va, result;
		if (head == NULL)
			return va;
		else {
			ListNode *list = head;
			while (list != NULL) {
				va.push_back(list->val);
				list = list->next;
			}
			for (int i = va.size() - 1; i >= 0; i--) {
				result.push_back(va.at(i));
			}
			return result;
		}
	}
};


//��һ�ֽⷨ������vector��insert��ָ��λ�ò���
//class Solution {
//public:
//	vector<int> printListFromTailToHead(struct ListNode* head) {
//		vector<int> value;
//		if (head != NULL)
//		{
//			value.insert(value.begin(), head->val);
//			while (head->next != NULL)
//			{
//				value.insert(value.begin(), head->next->val);
//				head = head->next;
//			}
//
//		}
//		return value;
//	}
//};
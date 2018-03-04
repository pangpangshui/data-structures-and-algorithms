#include <iostream>
#include <vector>

using namespace std;
//牛客网测试通过
//题目:输入一个链表，从尾到头打印链表每个节点的值。

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


//另一种解法：调用vector的insert，指定位置插入
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
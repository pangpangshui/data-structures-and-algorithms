#include <iostream>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};

//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
//������õݹ飬��Ҫ�ֱ��A����B���ֱ�ݹ�
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		bool result = false;//����flag��¼�Ƿ�ƥ��ɹ�
		if (pRoot1 != NULL && pRoot2 != NULL) {
			if (pRoot1->val == pRoot2->val) {
				result = DoesTreeAhasTreeA(pRoot1, pRoot2);//������ڵ���ȣ�������������������еݹ��ж�
			}

			if (result == false)
				result = HasSubtree(pRoot1->left, pRoot2);//������ڵ㲻�����result����Ϊtrue����ݹ�A��������B������ƥ��
			if (result == false)
				result = HasSubtree(pRoot1->right, pRoot2);//������ڵ㲻�����result����Ϊtrue����ݹ�A��������B������ƥ��

		}
		return result;
	}

	//�����ݹ��ж��Ƿ����ӽṹ
	bool DoesTreeAhasTreeA(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == NULL)//�ݹ���ֹ����
			return true;

		if (pRoot1 == NULL && pRoot2 != NULL)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return (DoesTreeAhasTreeA(pRoot1->left, pRoot2->left) && DoesTreeAhasTreeA(pRoot1->right, pRoot2->right));

	}
};
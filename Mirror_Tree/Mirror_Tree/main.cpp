//���������Ķ�����������任ΪԴ�������ľ���

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};


class Solution {
public:
	//�ݹ�ķ���
	void Mirror(TreeNode *pRoot) {
		if (pRoot != NULL) {
			ChangeChildPos(pRoot);
			//�ݹ���ڵ��������������������λ��
			Mirror(pRoot->left);
			Mirror(pRoot->right);
		}
	}

	//�����������ĸ��ڵ����������
	void ChangeChildPos(TreeNode *pRoot) {
		TreeNode *temp;
		temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		//return pRoot;
	}



	//�ǵݹ�ķ���
	void Mirror_nonrecursive(TreeNode *pRoot) {
		if (pRoot == NULL)
			return;
		stack<TreeNode*> sTree;
		sTree.push(pRoot);
		//���ڵ���ջ֮��ȡ������������������֮���������������Ϊ������������Ҳ��ջ��Ϊ��һ�����ڵ�
		while (!sTree.empty()) {
			TreeNode *tr = sTree.top();
			sTree.pop();
			if (tr->left != NULL || tr->right != NULL) {
				TreeNode *temp = tr->left;
				tr->left = tr->right;
				tr->right = temp;
			}
			if (tr->left)
				sTree.push(tr->left);
			if (tr->right) 
				sTree.push(tr->right);
		}
	}

};
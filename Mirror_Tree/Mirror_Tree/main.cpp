//操作给定的二叉树，将其变换为源二叉树的镜像。

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
	//递归的方法
	void Mirror(TreeNode *pRoot) {
		if (pRoot != NULL) {
			ChangeChildPos(pRoot);
			//递归根节点的左右子树，继续交换位置
			Mirror(pRoot->left);
			Mirror(pRoot->right);
		}
	}

	//交换传过来的根节点的左右子树
	void ChangeChildPos(TreeNode *pRoot) {
		TreeNode *temp;
		temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		//return pRoot;
	}



	//非递归的方法
	void Mirror_nonrecursive(TreeNode *pRoot) {
		if (pRoot == NULL)
			return;
		stack<TreeNode*> sTree;
		sTree.push(pRoot);
		//根节点入栈之后取出来交换左右子树，之后如果左右子树不为空则将左右子树也入栈作为下一个根节点
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
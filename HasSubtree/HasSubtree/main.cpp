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

//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//此题采用递归，需要分别对A树和B树分别递归
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		bool result = false;//设置flag记录是否匹配成功
		if (pRoot1 != NULL && pRoot2 != NULL) {
			if (pRoot1->val == pRoot2->val) {
				result = DoesTreeAhasTreeA(pRoot1, pRoot2);//如果根节点相等，则对两颗树的子树进行递归判断
			}

			if (result == false)
				result = HasSubtree(pRoot1->left, pRoot2);//如果根节点不相等且result还不为true，则递归A左子树与B树继续匹配
			if (result == false)
				result = HasSubtree(pRoot1->right, pRoot2);//如果根节点不相等且result还不为true，则递归A右子树与B树继续匹配

		}
		return result;
	}

	//子树递归判断是否是子结构
	bool DoesTreeAhasTreeA(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == NULL)//递归终止条件
			return true;

		if (pRoot1 == NULL && pRoot2 != NULL)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return (DoesTreeAhasTreeA(pRoot1->left, pRoot2->left) && DoesTreeAhasTreeA(pRoot1->right, pRoot2->right));

	}
};
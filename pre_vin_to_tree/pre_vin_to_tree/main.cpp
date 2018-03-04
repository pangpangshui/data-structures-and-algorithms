//重建二叉树：直到前序和中序，重建二叉树

#include <iostream>
#include <vector>

using namespace std;


 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

 //这是第一种方法，不断利用前序找根节点和子树根节点，根据根节点位置找到该节点的左子树和右子树序列，
 //把得到的前序和后序的左子树序列递归得到root的左子树，把前序和后序的右子树序列递归得到root的右子树，
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		//递归的终点
		if (pre.size() == 0)
			return NULL;
		vector<int> pre_left, pre_right, vin_left, vin_right;
		TreeNode *root = new TreeNode(pre.at(0));
		//tree->val = pre.at(0);
		int i, pre_index = 1;
		for (i = 0; i < vin.size(); i++) {
			if (vin.at(i) == pre.at(0))
				break;
		}
		for (int j = 0; j < vin.size(); j++) {
			if (j < i) {
				vin_left.push_back(vin.at(j));
				pre_left.push_back(pre.at(pre_index));
				pre_index++;
			}
			if (j > i) {
				vin_right.push_back(vin.at(j));
				pre_right.push_back(pre.at(pre_index));
				pre_index++;
			}
		}
		
		root->left = reConstructBinaryTree(pre_left, vin_left);
		root->right = reConstructBinaryTree(pre_right, vin_right);
		return root;
	}
};

 //通过率16%
//class Solution {
//public:
//	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
//		TreeNode *root = reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
//		return root;
//	}
//private:
//	TreeNode* reConstructBinaryTree(vector<int> pre, int startpre, int endpre, vector<int> vin, int startvin, int endvin) {
//		if (startpre > endpre || startvin > endvin) {
//			return NULL;
//		}
//		else {
//			TreeNode *sroot = new TreeNode(pre[startpre]);
//			for (int i = startvin; i < endvin; i++) {
//				if (vin[i] == pre[startpre]) {
//					sroot->left = reConstructBinaryTree(pre, startpre + 1, startpre + i - startvin, vin, startvin, i - 1);
//					sroot->right = reConstructBinaryTree(pre, i - startvin + startpre + 1, endpre, vin, i + 1, endvin); 
//				}
//			}
//			return sroot;
//		}
//	}
//
//};


int main() {
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> vin = { 4,7,2,1,5,3,8,6 };
	Solution *s = new Solution();
	TreeNode *t  = s->reConstructBinaryTree(pre, vin);
	return 0;
}
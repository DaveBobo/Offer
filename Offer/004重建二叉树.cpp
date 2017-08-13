#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		//先通过前序遍历找到根节点
		//再通过根节点把中序遍历的结果分为左子树tree_left和右子树tree_right
		//tree_left在前序遍历中的第一个节点就是根节点的左孩子
		//tree_right在前序遍历中的第一个节点就是根节点的右孩子
		if (pre.empty() || vin.empty() || pre.size() != vin.size())
			return NULL;
		TreeNode* root = new TreeNode(pre[0]); //前序遍历的第一个节点就是根节点
		if (pre.size() == 1) return root;

		vector<int> in_left, in_right;//中序遍历中的左子树和右子树
		vector<int> pre_left, pre_right;//前序遍历中的左子树和右子树
		int num_left = 0, num_right = 0; //分别存储左子树和右子树的个数
		int cur = pre[0]; //存储前序遍历中的第一个值，根据这个值再将中序遍历分为左子树和右子树

		int pos = 0;//中序遍历中cur的位置

		for (int i = 0; i < vin.size(); i++)//计算中序遍历的左子树和右子树
		{
			if (vin[i] == cur)
				pos = i;
		}
		for (int i = 0; i < vin.size(); i++)
		{
			if (i < pos)
			{
				in_left.push_back(vin[i]);
				num_left++;
			}

			if (i > pos)
			{
				in_right.push_back(vin[i]);
				num_right++;
			}
		}

		for (int i = 1; i < pre.size(); i++) //计算前序遍历的左子树和右子树
		{
			if (num_left)
			{
				pre_left.push_back(pre[i]);
				--num_left;
			}
			else if (num_right)
			{
				pre_right.push_back(pre[i]);
				--num_right;
			}
			else
			{

			}
		}

		root->left = reConstructBinaryTree(pre_left, in_left);
		root->right = reConstructBinaryTree(pre_right, in_right);
		return root;
	}
};

//前序遍历  
void PreOrderTraverse(TreeNode *pNode)
{
	if (pNode){
		printf("%d ", pNode->val);
		PreOrderTraverse(pNode->left);
		PreOrderTraverse(pNode->right);
	}
}

//中序遍历  
void InOrderTraverse(TreeNode *pNode)
{
	if (pNode){
		InOrderTraverse(pNode->left);
		printf("%d ", pNode->val);
		InOrderTraverse(pNode->right);
	}
}

//后序遍历  
void PostOrderTraverse(TreeNode *pNode)
{
	if (pNode){
		PostOrderTraverse(pNode->left);
		PostOrderTraverse(pNode->right);
		printf("%d ", pNode->val);
	}
}

int main004(){

	vector<int> pre;
	vector<int> vin;

	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(4);
	pre.push_back(7);
	pre.push_back(3);
	pre.push_back(5);
	pre.push_back(6);
	pre.push_back(8);

	vin.push_back(4);
	vin.push_back(7);
	vin.push_back(2);
	vin.push_back(1);
	vin.push_back(5);
	vin.push_back(3);
	vin.push_back(8);
	vin.push_back(6);

	Solution sln;
	TreeNode* rNode;
	rNode = sln.reConstructBinaryTree(pre, vin);
	cout << "前序遍历序列" << endl;
	PreOrderTraverse(rNode);
	cout << endl;
	cout << "中序遍历序列" << endl;
	InOrderTraverse(rNode);
	system("pause");
	return 0;
}
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
		//��ͨ��ǰ������ҵ����ڵ�
		//��ͨ�����ڵ����������Ľ����Ϊ������tree_left��������tree_right
		//tree_left��ǰ������еĵ�һ���ڵ���Ǹ��ڵ������
		//tree_right��ǰ������еĵ�һ���ڵ���Ǹ��ڵ���Һ���
		if (pre.empty() || vin.empty() || pre.size() != vin.size())
			return NULL;
		TreeNode* root = new TreeNode(pre[0]); //ǰ������ĵ�һ���ڵ���Ǹ��ڵ�
		if (pre.size() == 1) return root;

		vector<int> in_left, in_right;//��������е���������������
		vector<int> pre_left, pre_right;//ǰ������е���������������
		int num_left = 0, num_right = 0; //�ֱ�洢���������������ĸ���
		int cur = pre[0]; //�洢ǰ������еĵ�һ��ֵ���������ֵ�ٽ����������Ϊ��������������

		int pos = 0;//���������cur��λ��

		for (int i = 0; i < vin.size(); i++)//���������������������������
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

		for (int i = 1; i < pre.size(); i++) //����ǰ���������������������
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

//ǰ�����  
void PreOrderTraverse(TreeNode *pNode)
{
	if (pNode){
		printf("%d ", pNode->val);
		PreOrderTraverse(pNode->left);
		PreOrderTraverse(pNode->right);
	}
}

//�������  
void InOrderTraverse(TreeNode *pNode)
{
	if (pNode){
		InOrderTraverse(pNode->left);
		printf("%d ", pNode->val);
		InOrderTraverse(pNode->right);
	}
}

//�������  
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
	cout << "ǰ���������" << endl;
	PreOrderTraverse(rNode);
	cout << endl;
	cout << "�����������" << endl;
	InOrderTraverse(rNode);
	system("pause");
	return 0;
}
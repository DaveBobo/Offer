#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {

		stack<ListNode*> sln;
		ListNode* pNode = head;
		vector<int> ival;
		while (pNode != NULL)
		{
			sln.push(pNode);
			pNode = pNode->next;
		}

		while (!sln.empty())
		{
			pNode = sln.top();
			ival.push_back(pNode->val);
			sln.pop();
		}
		return ival;
	}
};

int main003(){

	struct ListNode *head, *pt, *p;
	vector<int> res;
	head = pt = (struct ListNode *)malloc(sizeof(ListNode));
	p = NULL;
	scanf("%d", &pt->val);
	while (pt->val != 0){
		p = pt;
		pt = (struct ListNode *)malloc(sizeof(ListNode));
		scanf("%d", &pt->val);
		p->next = pt;
	}
	p->next = NULL;
	p = head;
	printf("打印链表的值：\n");
	while (p->next != NULL){
		printf("%d ", p->val);
		p = p->next;
	}
	printf("%d ", p->val);

	Solution sln;
	res = sln.printListFromTailToHead(head);
	printf("\n从尾到头打印链表\n");
	for (vector<int>::iterator iter = res.begin(); iter != res.end(); ++iter)
	{
		cout << *iter <<' ';
	}
	system("pause");
	return 0;
}
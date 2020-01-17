/*
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/

#include "iostream"
#include <vector>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

vector<int> printListFromTailToHead(ListNode* head)
{
    vector<int> result;
    stack<int> s;
    ListNode* pHead = head;
    while(pHead != NULL)
    {
        s.push(pHead->val);
        pHead = pHead->next;
    }
    while(!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);

    l1->next = l2;
    l2->next = l3;
	vector<int> result = printListFromTailToHead(l1);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    delete l3;
    l3 = NULL;
    delete l2;
    l2 = NULL;
    delete l1;
    l1 = NULL;

	return 0;
}

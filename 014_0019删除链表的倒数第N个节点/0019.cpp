/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 由于至少一个节点，不考虑空链表
        // 虚拟头结点并绑定
        ListNode *dummyNode = new ListNode(0, head);
        // 设置快慢指针
        ListNode *slow = dummyNode;
        ListNode *fast = dummyNode;
        // 推进快指针
        for (int i = 0; i < n + 1; ++i)
        {
            fast = fast->next;
        }
        // 同时推进快慢指针
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 删除节点
        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return dummyNode->next;
    }
};
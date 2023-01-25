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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(0, head); // 虚拟头结点
        ListNode *curr = dummyHead;
        while (curr->next != nullptr && curr->next->next != nullptr)
        {
            ListNode *left = curr->next;
            ListNode *right = curr->next->next;
            ListNode *temp = curr->next->next->next;
            curr->next = right;
            right->next = left;
            left->next = temp;

            curr = curr->next->next; // 实际就是left
        }
        return dummyHead->next;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr) // fast快，只要判断fast有没有nullptr就可以：1.判断有无环 2.帮助slow判断同样的东西
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) // 快慢指针相遇
            {
                ListNode *index1 = fast;
                ListNode *index2 = head;
                while (index1 != index2) // 探测指针不相遇
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1; // 探测指针相遇 或index2
            }
        }
        return nullptr; // 链表无环
    }
};
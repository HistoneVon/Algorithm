#include <iostream>
using namespace std;

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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr) // 排除空链表
        {
            return nullptr;
        }
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = head->next;
        while (next != nullptr)
        {
            // 考虑头指针新指向为nullptr
            if (curr == head)
            {
                curr->next = nullptr;
            }
            // 移动指针
            prev = curr;
            curr = next;
            next = next->next;
            // 换向
            curr->next = prev;
        }
        return curr;
    }
};
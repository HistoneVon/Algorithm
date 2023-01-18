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
        ListNode *prev = nullptr;
        if (head==nullptr)//排除空链表
        {
            return nullptr;
        }
        ListNode *next = head->next;
        ListNode *curr = head;
        while (next != nullptr)//如果未到最后一个
        {
            //移动指针
            prev = curr;
            curr = next;
            next = curr->next;
            //指向前一个
            curr->next = prev;
            if (prev==head)
            {
                prev->next=nullptr;
            }
        }
        return curr;
    }
};
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);
        int longLen, shortLen;
        ListNode *longList, *shortList;
        if (lenA > lenB) // A长
        {
            longLen = lenA;
            shortLen = lenB;
            longList = headA;
            shortList = headB;
        }
        else // B长
        {
            longLen = lenB;
            shortLen = lenA;
            longList = headB;
            shortList = headA;
        }
        int gap = longLen - shortLen;
        while (gap--) // 移动指针，排除超出的长度
        {
            longList = longList->next;
        }
        while (shortList != nullptr) // 遍历其余的链表，如果相同则退出返回
        {
            if (shortList == longList)
            {
                return shortList;
            }
            shortList = shortList->next;
            longList = longList->next;
        }
        return nullptr;
    }

private:
    int getListLength(ListNode *start) // 获得当前节点到链表末尾的节点数（包括start）
    {
        ListNode *temp = start;
        int len = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            ++len;
        }
        return len;
    }
};
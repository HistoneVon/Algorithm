// Definition for singly-linked list.
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *newHead = new ListNode(); // 声明头结点
        newHead->next = head;               // 加头结点
        ListNode *curr = head;
        ListNode *next = head ? head->next : nullptr;
        ListNode *prev = newHead;
        while (curr != nullptr)
        {
            if (curr->val == val)
            {
                ListNode *temp = curr;
                prev->next = next;
                curr = next;
                delete temp;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
            next = next ? next->next : nullptr; // 无论如何next永远是next->next
        }
        head = newHead->next;
        delete newHead;
        return head;
    }
};
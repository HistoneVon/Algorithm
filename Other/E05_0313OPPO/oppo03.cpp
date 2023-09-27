// 反转链表 100%
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * #例如
     * #输入 {1.2,3,4,5}
     * #输出 {5,4,3,2,1}
     * @param head ListNode类 链表的头节点
     * @return ListNode类
     */
    ListNode* reverseList(ListNode* head) {
        // 排除空链表
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = head->next;
        while (nxt != nullptr) {
            // 考虑头结点
            if (cur == head) {
                cur->next = nullptr;
            }
            // 移动指针
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
            // 换向
            cur->next = pre;
        }
        return cur;
        // if (head == nullptr) {
        //     return nullptr;
        // }
        // ListNode* pre = nullptr;
        // ListNode* cur = head;
        // ListNode* nxt = head->next;
        // while (cur != nullptr) {
        //     cur->next = pre;
        //     pre = cur;
        //     cur = nxt;
        //     if (nxt != nullptr) {
        //         nxt = nxt->next;
        //     }

        // }
        // return cur;
    }
};
// 016 LeetCode.142
// 用于尝试输入输出，链表建立和销毁
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int n): val(n), next(nullptr) {}
};

ListNode* create(vector<int>& nums) {
    ListNode* p, * head, * pre;
    head = new ListNode(0);
    pre = head;
    for (int i = 0; i < nums.size(); ++i) {
        p = new ListNode(nums[i]);
        pre->next = p;
        pre = p;
    }
    return head->next;
}

bool fresh(ListNode* head) {
    try {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* cur;
        while (dummyHead->next != nullptr) {
            cur = dummyHead->next;
            dummyHead->next = dummyHead->next->next;
            delete cur;
        }
        delete dummyHead;
        return true;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}

ListNode* detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            ListNode* index1 = fast;
            ListNode* index2 = head;
            while (index1 != index2) {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
    }
    return nullptr;
}

int main() {
    int n, pos;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
        if (cin.get() == '\n') {
            cin >> pos;
            ListNode* l = create(nums);
            // l = l->next; // 排除头结点
            ListNode* end = l;
            while (end->next != nullptr) {
                end = end->next;
            }
            if (pos != -1) {
                ListNode* p = l;
                for (int i = 0; i < pos; ++i) {
                    p = p->next;
                }
                end->next = p;
            }
            ListNode* res = detectCycle(l);
            if (res != nullptr) {
                cout << res->val << endl;
            } else {
                cout << "null" << endl;
            }
            // fresh(l);                 // 清空链表：此处会出现Double free，不适用此题
            vector<int>().swap(nums); // 清空vector
        }
    }
    return 0;
}
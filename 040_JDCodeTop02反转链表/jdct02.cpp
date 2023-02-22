#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int n): val(n), next(nullptr) {}
    ListNode(int n, ListNode* next): val(n), next(next) {}
};

ListNode* create(vector<int>& nums) {
    ListNode* head = new ListNode(0);
    ListNode* p;
    ListNode* pre = head;
    for (int i = 0; i < nums.size(); i++) {
        p = new ListNode(nums[i]);
        pre->next = p;
        pre = pre->next;
    }
    return head->next;
}

bool fresh(ListNode* head) {
    try {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* curr;
        while (dummyHead->next != nullptr) {
            curr = dummyHead->next;
            dummyHead->next = dummyHead->next->next;
            delete curr;
        }
        delete dummyHead;
        return true;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
}

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = head->next;
    while (next != nullptr) {
        if (curr == head) {
            curr->next = nullptr;
        }
        prev = curr;
        curr = next;
        next = next->next;
        curr->next = prev;
    }
    return curr;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
        if (cin.get() == '\n') {
            ListNode* l = create(nums);
            l = reverseList(l);
            ListNode* p = l;
            while (p != nullptr) {
                cout << p->val << " ";
                p = p->next;
            }
            cout << endl;
            vector<int>().swap(nums);
            fresh(l);
        }
    }
    return 0;
}
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

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummyHead = new ListNode(-1, head);
    ListNode* fast = dummyHead;
    ListNode* slow = dummyHead;
    for (int i = 0; i < n + 1; ++i) {
        fast = fast->next;
    }
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* temp = slow->next;
    slow->next = temp->next;
    delete temp;
    return dummyHead->next;
}

void printListNode(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void freeListNode(ListNode* head) {
    while (head->next != nullptr) {
        ListNode* temp = head->next;
        head->next = temp->next;
        delete temp;
    }
    if (head != nullptr) {
        delete head;
    }
}

int main() {
    int a; // node临时变量
    ListNode* dummyHead = new ListNode(-1);
    ListNode* currentPtr = dummyHead;
    int n; // 要删除的节点
    while (cin >> a) {
        ListNode* node = new ListNode(a);
        currentPtr->next = node;
        currentPtr = currentPtr->next;
        if (cin.get() == '\n') {
            // printListNode(dummyHead->next);
            cin >> n;
            ListNode* resNode = removeNthFromEnd(dummyHead->next, n);
            // printListNode(dummyHead->next); 有问题
            printListNode(resNode);
            // freeListNode(dummyHead->next); 有问题
            currentPtr = dummyHead;
        }
    }
    return 0;
}
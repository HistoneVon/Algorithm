#include <iostream>
using namespace std;

// 插入
// 删除
// 获取大小
// 查询元素是否存在

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() {};
    ListNode(int v) {
        val = v;
        next = nullptr;
    };
    ListNode(int v, ListNode* n) {
        val = v;
        next = n;
    }
};

class myList {
public:
    ListNode* head;
    unsigned int listSize;
    myList(ListNode* h) {
        head = h;
        listSize = 1;
    };
    bool insertNode(ListNode* node, int pos) {
        if (pos > listSize) {
            return false;
        }
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        pos += 1;
        // 有虚拟头结点，所以+1
        while (pos--) {
            temp = temp->next;
        }
        // 在pos位置添加节点
        node->next = temp->next;
        temp->next = node;
        ++listSize;
        head = dummyHead->next;
        delete dummyHead;
        return true;
    }

    bool deleteNode(int pos) {
        if (pos > listSize) {
            return false;
        }
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        // temp指向要删除的上一个节点
        while (pos--) {
            temp = temp->next;
        }
        // 拿到pos位置的节点并释放
        ListNode* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        --listSize;
        head = dummyHead->next;
        delete dummyHead;
        return true;
    }

    void printList() {
        ListNode* cur = head;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    myList* A = new myList(head);
    for (int i = 2; i < 10; ++i) {
        ListNode* temp = new ListNode(i);
        A->insertNode(temp, i - 2);
    }
    A->printList();
    A->deleteNode(5);
    A->printList();
    return 0;
}
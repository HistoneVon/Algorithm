class MyLinkedList
{
public:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList()
    {
        _dummyNode = new LinkedNode(0);
        _size = 0;
    }

    int get(int index)
    {
        if (index > (_size - 1) || index < 0)
        {
            return -1;
        }
        LinkedNode *ptr = _dummyNode;
        for (int i = 0; i <= index; ++i) // 这里有等号，循环停止时是被查询节点
        {
            ptr = ptr->next; // 每一轮循环结束后，i是下标
        }
        return ptr->val;
    }

    void addAtHead(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = _dummyNode->next;
        _dummyNode->next = newNode;
        ++_size;
    }

    void addAtTail(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *ptr = _dummyNode;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        ++_size;
    }

    void addAtIndex(int index, int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *curr = _dummyNode;
        if (index > _size) // 如果index大于长度，则不插入
        {
            return;
        }
        if (index <= 0) // 如果index小于等于0，则在头结点插入
        {
            index = 0;
        }
        for (int i = 0; i < index; ++i) // 这里没有等号，循环停止时是被插入节点的上一节点
        {
            curr = curr->next; // 每一轮循环结束后，i是下标
        }
        newNode->next = curr->next;
        curr->next = newNode;
        ++_size;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > (_size - 1)) // 索引无效
        {
            return;
        }
        LinkedNode *curr = _dummyNode;
        for (int i = 0; i < index; ++i) // 这里没有等号，循环停止时是被删除节点的上一节点
        {
            curr = curr->next; // 每一轮循环结束后，i是下标
        }
        LinkedNode *temp = curr->next;
        curr->next = temp->next;
        delete temp;
        --_size;
    }

private:
    int _size;              // 链表长度
    LinkedNode *_dummyNode; // 虚拟头结点
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
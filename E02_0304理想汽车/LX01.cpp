// 理想汽车
// 二叉查找，自定义比较方式

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
int BSearch(vector<T>& arr, T key, bool (*fpLess)(T, T), bool (*fpGreater)(T, T)) {
    int len = arr.size();
    if (len == 0) {
        return -1;
    }
    int low = 0;
    int high = len - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((*fpLess)(arr[mid], key)) {
            low = mid + 1;
        } else if ((*fpGreater)(arr[mid], key)) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}


bool isLessInt(int a, int b) {
    return a < b;
}

bool isGreaterInt(int a, int b) {
    return a > b;
}

struct Creature {
    int legs;
    string name;
};

bool isLessStruct(struct Creature a, struct Creature b) {
    return a.legs < b.legs;
}

bool isGreaterStruct(struct Creature a, struct Creature b) {
    return a.legs > b.legs;
}

int main() {
    vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }
    cout << BSearch(vec, 7, isLessInt, isGreaterInt) << endl;

    vector<struct Creature> vec_s;
    for (int i = 0;i < 10; ++i) {
        struct Creature temp;
        temp.legs = i + 10;
        temp.name = to_string(i);
        vec_s.push_back(temp);
    }
    struct Creature n = { 15, "aaa" };
    cout << BSearch(vec_s, n, isLessStruct, isGreaterStruct) << endl;

    return 0;
}
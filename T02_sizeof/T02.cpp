// 优稳自动化
// 数组和结构体在内存中所占的字节数

#include <iostream>
using namespace std;

struct ST_U {
    union {
        char cu;
        short su;
    };
    double dbl;
};

int main() {
    float fa[] = { 0.0f, 0.0f,0.0f,0.0f,0.0f, };
    cout << sizeof(fa) << endl;
    ST_U st;
    cout << sizeof(st) << endl;
    return 0;
}
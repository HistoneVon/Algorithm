// 100%
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

void printVector(vector<string>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void stringSplit(string s, char split, vector<string>& res) {
    istringstream in(s);
    string record; // 接收缓冲区，即每一条等式条目
    while (getline(in, record, split)) {
        res.push_back(record);
    }
}

void record2umap(vector<string>& record, unordered_map<string, string>& umap) {
    for (int i = 0; i < record.size(); ++i) {
        size_t pos = record[i].find('=');
        string key = record[i].substr(0, pos);
        string value = record[i].substr(pos + 1, record[i].size());
        // cout << key << " " << value << endl;
        umap[key] = value;
    }
}

int main() {
    string s;
    cin >> s;
    vector<string> record; // 记录导出的等式条目
    stringSplit(s, ';', record);
    // printVector(record);
    unordered_map<string, string> umap; // 记录导出条目
    record2umap(record, umap);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string qs; // 询问字符串
        cin >> qs;
        if (umap[qs] != "") { // 如果存在该字符串
            cout << umap[qs] << endl;
        } else { // 不存在输出EMPTY
            cout << "EMPTY" << endl;
        }
    }
    return 0;
}
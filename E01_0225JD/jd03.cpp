// ac: 0.1

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void printVector(vector<string>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int comp(int n) {
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return n * comp(n - 1);
    }
}

unsigned long long calculateSort(vector<string>& v) {
    unsigned long long res = 1;
    unordered_map<string, int> umap;
    unordered_map<int, int> umap_arr;
    for (int i = 0; i < v.size(); ++i) {
        umap[v[i]]++;
        umap_arr[v[i].size()]++;
    }
    for (auto a : umap_arr) {
        res = res * comp(a.second) % (10 ^ 9 + 7);
        for (auto c : umap) {
            if (c.first.size() == a.first && c.second > 1) {
                res = res / comp(c.second) % (10 ^ 9 + 7);
            }
        }
    }
    return res;
}

int main() {
    int n;
    string in;
    vector<string> s;
    while (cin >> n) {
        for (int i = 0; i < n;++i) {
            cin >> in;
            s.push_back(in);
        }
        sort(s.begin(), s.end());
        // printVector(s);
        cout << calculateSort(s) << endl;
        vector<string>().swap(s);
    }
}
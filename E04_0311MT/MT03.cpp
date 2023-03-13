#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

unordered_map<int, int> getStar(vector<int>& start, vector<int>& end, int n) {
    unordered_map<int, int> umap;
    for (int i = 0; i < n; ++i) {
        int s = start[i];
        int e = end[i];
        for (int j = s; j <= e; ++j) {
            if (!umap[j]) {
                umap[j] = 1;
            } else {
                ++umap[j];
            }
        }
    }
    return umap;
}

void printMap(unordered_map<int, int>& umap) {
    for (auto n : umap) {
        cout << n.first << " " << n.second << endl;
    }
}

int getMost(unordered_map<int, int>& umap) {
    int max = 0;
    for (auto n : umap) {
        max = max > n.second ? max : n.second;
    }
    return max;
}

int getTimes(unordered_map<int, int>& umap, int max) {
    int times = 0;
    for (auto n : umap) {
        if (n.second == max) {
            times++;
        }
    }
    return times;
}

int main() {
    int n;
    cin >> n;
    vector<int> start;
    vector<int> end;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        start.push_back(t);
    }
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        end.push_back(t);
    }
    unordered_map<int, int> umap = getStar(start, end, n);
    // printMap(umap);
    int max = getMost(umap);
    int times = getTimes(umap, max);
    cout << max << " " << times << endl;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void printVector(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool checkLink(vector<vector<int> >& vv, int i, int j) {
    if (vv[i][j]) {
        return true;
    } else {
        return false;
    }
}

int main() {
    vector<int> color; // 颜色
    unordered_map<int, vector<int> > umap_color; // 颜色：节点
    vector<vector<int> > neighbor_matrix; // 领接矩阵
    int n; // 节点数
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        color.push_back(temp);
        umap_color[temp].push_back(i);
    }

    // cout << endl << "color" << endl;
    // printVector(color);
    // cout << "umap" << endl;
    // for (auto u : umap_color) {
    //     printVector(u.second);
    // }

    for (int i = 0; i < n; ++i) {
        vector<int> temp_vec;
        for (int j = 0; j < n; ++j) {
            int temp;
            cin >> temp;
            temp_vec.push_back(temp);
        }
        neighbor_matrix.push_back(temp_vec);
        vector<int>().swap(temp_vec);
    }

    // cout << endl << "matrix" << endl;
    // for (int i = 0; i < n; ++i) {
    //     printVector(neighbor_matrix[i]);
    // }

    // 以下乱了
    int m = 0;
    int m_temp = 0;
    for (auto u : umap_color) {
        sort(u.second.begin(), u.second.end());
        for (int i = 1; i < u.second.size(); ++i) {
            if (checkLink(neighbor_matrix, i, i - 1)) { // 寻找最大连通子图
                m_temp++;
            } else {
                m_temp = 0;
            }
        }
        m = m > m_temp ? m : m_temp;
    }

    int m_temp_check = 0;
    int min = n + 1;
    vector<int> linked_node;
    for (auto u : umap_color) {
        sort(u.second.begin(), u.second.end());
        for (int i = 1; i < u.second.size(); ++i) {
            if (i == 1) linked_node.push_back(u.second[0]);
            if (checkLink(neighbor_matrix, i, i - 1)) { // 寻找最大连通子图
                m_temp_check++;
                linked_node.push_back(u.second[i]);
            } else {
                m_temp_check = 0;
                vector<int>().swap(linked_node);
            }
        }
        if (m_temp_check == m) {
            min = min < u.first ? min : u.first;
        }
    }

    cout << m << endl; // 最大连通子图的节点数
    // 输出连通的节点，每行一个
}
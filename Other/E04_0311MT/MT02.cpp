#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printVectorLine(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> parseStringToInt(string& s, int m) {
    // cout << s << endl;
    vector<int> res;
    for (int i = 0; i < m; ++i) {
        int temp = 1; // Red
        if (s[i] == 'B') {
            temp = 2; // Blue
        }
        res.push_back(temp);
    }
    // printVectorLine(res);
    return res;
}

void printVector(vector<vector<int> >& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int getCoin(vector<vector<int> >& color, vector<vector<int> >& coin, int n, int m, int k) {
    int c = 0; // coin
    int i = 0; // n
    int j = 0; // m
    for (int x = 0; x < m + n - 2; ++x) {
        int cur = color[i][j];
        cout << cur << endl;
        // if (i == 0 && j == 0) {
        //     if (cur != color[i + 1][j] && cur != color[i][j + 1]) {
        //         break;
        //     }
        // }
    }
    return c;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > vec_color;
    vector<vector<int> > vec_coin;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        vector<int> temp = parseStringToInt(s, m);
        vec_color.push_back(temp);
    }
    // printVector(vec_color);
    int coin;
    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        for (int j = 0; j < m; ++j) {
            cin >> coin;
            temp.push_back(coin);
        }
        vec_coin.push_back(temp);
    }
    // printVector(vec_coin);
    cout << getCoin(vec_color, vec_coin, n, m, k) << endl;
    return 0;
}
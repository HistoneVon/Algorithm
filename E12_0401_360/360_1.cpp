// 100%
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec_score;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec_score.push_back(temp);
    }
    long res = 0;
    for (int i = 0; i < n; ++i) {
        res += vec_score[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            res += (vec_score[i] | vec_score[j]);
        }
    }
    cout << res << endl;
    return 0;
}
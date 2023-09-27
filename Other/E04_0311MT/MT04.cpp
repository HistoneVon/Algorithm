#include<iostream>
#include<vector>
#include<string>
using namespace std;

pair<int, int> getNext(pair<int, int>& init, string op, string& state) {
    pair<int, int> next = init;
    switch (op[0]) {
    case 'U':
        state = "U";
        next.first--;
        break;
    case 'D':
        state = "D";
        next.first++;
        break;
    case 'L':
        state = "L";
        next.second--;
        break;
    case 'R':
        state = "R";
        next.second++;
        break;
    case 'F':
        break;
    default:
        break;
    }
    return next;
}

void getAns(string& win, int& times,
    string& sd, string& sw,
    string& state_d, string& state_w,
    pair<int, int>& pos_d, pair<int, int>& pos_w) {
    bool flag = true; // win-win
    int i;
    for (i = 0; i < 256; ++i) {
        pos_d = getNext(pos_d, to_string(sd[i]), state_d);
        pos_w = getNext(pos_w, to_string(sw[i]), state_w);
        times++;
        if (pos_d == pos_w) {
            flag = false;
            win = "P";
        }
    }
}

int main() {
    string sd;
    string sw;
    cin >> sd;
    cin >> sw;
    string state_d = "R";
    string state_w = "L";
    pair<int, int> pos_d;
    pos_d.first = 0;
    pos_d.second = 0;
    pair<int, int> pos_w;
    pos_w.first = 15;
    pos_w.second = 15;
    string win;
    int times = 0;;
    getAns(win, times, sd, sw, state_d, state_w, pos_d, pos_w);
    cout << times << " " << win << endl;
    return 0;
}
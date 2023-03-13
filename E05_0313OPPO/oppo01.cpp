// 0.8
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 输入参数是每个应用持有WakeLock的起始时间及结束时间，函数返回值是每个应用对总WakeLock时长的贡献值，返回值vector里面的每个元素的数值累加即为手机总的持有WakeLock的时长。
     * @param wakeLock int整型vector<vector<>> vector<vector<int>>的每个元素代表某个应用的持有WakeLock的信息，内部的vector<int>，元素按照奇偶排列，偶数元素代表拿WakeLock的起始时间点，奇数代表释放WakeLock的时间点
     * @return int整型vector
     */
    vector<int> getWakeLockContrib(vector<vector<int> >& wakeLock) {
        // write code here
        // 统计有多少个时间点有wakelock，每个时间点有多少个应用
        unordered_map<int, int> umap_time;
        getTimes(umap_time, wakeLock);
        printMap(umap_time);
        // 统计每个应用有多少贡献时间
        vector<int> vec_contrib;
        getContrib(vec_contrib, umap_time, wakeLock);
        return vec_contrib;
    }
    void getTimes(unordered_map<int, int>& umap_time, vector<vector<int> >& wakeLock) {
        int count_app = wakeLock.size();
        for (int i = 0; i < count_app; ++i) {
            int count_times = wakeLock[i].size();
            for (int j = 0; j < count_times; j += 2) {
                int time_start = wakeLock[i][j];
                int time_end = wakeLock[i][j + 1];
                for (int k = time_start; k < time_end; ++k) {
                    if (!umap_time[k]) {
                        umap_time[k] = 1;
                    } else {
                        ++umap_time[k];
                    }
                }
            }
        }
    }
    void getContrib(vector<int>& vec_contrib, unordered_map<int, int>& umap_time, vector<vector<int> >& wakeLock) {
        int count_app = wakeLock.size();
        for (int i = 0; i < count_app; ++i) {
            int count_times = wakeLock[i].size();
            double contrib = 0; // 贡献时间，初始为0
            for (int j = 0; j < count_times; j += 2) {
                int time_start = wakeLock[i][j];
                int time_end = wakeLock[i][j + 1];
                for (int k = time_start; k < time_end; ++k) {
                    contrib += 1.0 / umap_time[k];
                }
            }
            vec_contrib.push_back((int)contrib);
        }
    }
    void printMap(unordered_map<int, int>& m) {
        for (auto n : m) {
            cout << n.first << " " << n.second << endl;
        }
    }
};
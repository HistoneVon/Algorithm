#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    // 小顶堆
    class customComparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
            // 个人认为是新进入堆的元素要比之前进入的元素（父节点）大
            // 所以才这么写
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1.要统计元素出现频率
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            ++umap[nums[i]];
        }
        // 2.对频率排序
        // 定义小顶堆（优先级队列），大小为k（即最终vector容量）
        priority_queue<pair<int, int>, vector<pair<int, int>>, customComparison> pq;
        // 用固定大小为k的小顶堆扫描所有频率的数值
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            pq.push(*it);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        // 3.找出前K个高频元素
        vector<int> freq(k);
        // 因为是小顶堆，所以逆序存入freq
        for (int i = k - 1; i >= 0; --i) {
            freq[i] = pq.top().first;
            pq.pop();
        }
        return freq;
    }
};
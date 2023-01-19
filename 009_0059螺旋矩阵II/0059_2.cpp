// 经过阅读后的第三次提交 模拟无算法
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector(n, -1));
        int startx = 0, starty = 0; // 每一圈的起始位置
        int mid = n / 2;            // 中心位置，如果是奇数边长需要单独考虑中心数字
        int offset = 1;             // 用于控制每一边遍历的长度（边长-1开区间），每圈循环-1
        int loop = n / 2;           // 循环数
        int m = 1;                  // 填入的数字
        int i, j;                   // 循环变量，i是一维，j是二维
        while (loop--)
        {
            i = startx; // 初始化循环变量
            j = starty;
            for (; j < n - offset; ++j)
            {
                ans[i][j] = m++;
            }
            for (; i < n - offset; ++i)
            {
                ans[i][j] = m++;
            }
            for (; j > starty; --j)
            {
                ans[i][j] = m++;
            }
            for (; i > startx; --i)
            {
                ans[i][j] = m++;
            }
            startx++;
            starty++; // 相当于左侧向右移动一个位置
            offset++; // 相当于右侧向右移动一个位置 实际效果就是左右各缩水一个位置 实现下一次循环在内圈
        }
        if (n % 2) // 奇数边长，实际如果是边长为1，在此处也会解决
        {
            ans[mid][mid] = m;
        }
        return ans;
    }
};
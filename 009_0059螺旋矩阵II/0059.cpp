// 烂尾

#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int m = n * n;
        vector<vector<int>> ans;
        int base = n - 1;             // 每一轮递增的基数，第一轮从n-1开始
        int counter = 0;              // 计数器，用于计算是否是大于base了（判断每一轮结束）
        int direct = 1;               // 1-right 2-down 3-left 4-up 初始right
        int dimen_1 = 0, dimen_2 = 0; // 一维下标和二维下标的初值均为0
        for (int i = 1; i <= m; ++i)
        {
            ans[dimen_1][dimen_2] = i; // 填充内容，初始填充ans[0][0]
            switch (direct)            // 根据方向判断下一步下标
            {
            case 1:        // right
                dimen_2++; // 计算下一下标
                counter++;
                if (counter == base) // 计数器自增后等于base，立即换向，清零counter
                {
                    direct = 2; // 换向，right->down
                    counter = 0;
                }
                break;
            case 2: // down
                dimen_1++;
                counter++;
                if (counter == base)
                {
                    direct = 3;
                    counter = 0;
                }
                break;
            case 3: // left
                dimen_2--;
                counter++;
                if (counter == base)
                {
                    direct = 4;
                    counter = 0;
                    //base--;
                }
                break;
            case 4: // up
                break;
            default:
            }
        }
    }
};
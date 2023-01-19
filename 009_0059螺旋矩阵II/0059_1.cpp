// 自己想的另外一个方法 尝试失败
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int m = n * n;
        vector<vector<int>> ans(n, vector(n, -1));
        int base = n - 1;             // 每一轮递增的基数，第一轮从n-1开始
        int direct = 1;               // 1-right 2-down 3-left 4-up 初始right
        int dimen_1 = 0, dimen_2 = 0; // 一维下标和二维下标的初值均为0
        for (int i = 1; i <= m; ++i)
        {
            ans[dimen_1][dimen_2] = i; // 填充内容，初始填充ans[0][0]
            switch (direct)            // 根据方向判断下一步下标
            {
            case 1: // right
                dimen_2++;
                break;
            case 2: // down
                dimen_1++;
                break;
            case 3: // left
                dimen_2--;
                break;
            case 4: // up
                dimen_1--;
                break;
            }
            if (dimen_1 == 0 && dimen_2 == 4)
            {                                // 边界右上角
                dimen_2--;                   // 超出的下标回退
                direct = nextDirect(direct); // 换向
                dimen_1++;                   // 正确的下标前进
            }
            else if (dimen_1 == 4 && dimen_2 == 3)
            {                                // 边界右下角
                dimen_1--;                   // 超出的下标回退
                direct = nextDirect(direct); // 换向
                dimen_2--;                   // 正确的下标前进
            }
            else if (dimen_1 == 3 && dimen_2 == -1)
            {                                // 边界左下角
                dimen_2++;                   // 超出的下标回退
                direct = nextDirect(direct); // 换向
                dimen_1--;                   // 正确的下标前进
            }
            else if (ans[dimen_1][dimen_2 != -1]) // 如果是已经填过的位置，就一定要换向了
            {
                switch (direct) // 根据原方向回退正确的坐标
                {
                case 1: // right
                    dimen_2--;
                    break;
                case 2: // down
                    dimen_1--;
                    break;
                case 3: // left
                    dimen_2++;
                    break;
                case 4: // up
                    dimen_1++;
                    break;
                }
                direct = nextDirect(direct); // 换向
                switch (direct)              // 根据新方向判断下一步下标
                {
                case 1: // right
                    dimen_2++;
                    break;
                case 2: // down
                    dimen_1++;
                    break;
                case 3: // left
                    dimen_2--;
                    break;
                case 4: // up
                    dimen_1--;
                    break;
                }
            }
        }
        return ans;
    }

private:
    int nextDirect(int d) // 求下一个方向
    {
        int a;
        switch (d)
        {
        case 1:
            a = 2; // right->down
        case 2:
            a = 3; // down->left
        case 3:
            a = 4; // left->up
        case 4:
            a = 1; // up->right
        }
        return a;
    }
};
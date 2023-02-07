#include <unordered_set>
using namespace std;

class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        unordered_set<int> check;
        while (true)
        {
            int sum = getSum(n);
            if (sum == 1)
            {
                return true; // 如果得到了1则退出，说明是快乐数
            }
            if (check.find(sum) == check.end())
            {
                check.insert(sum); // 如果没出现过则将sum插入set
                n = sum;           // 更新新的n
            }
            else
            {
                return false; // 如果出现过了，则说明出现了循环，则直接返回false，不是快乐数
            }
        }
    }
};
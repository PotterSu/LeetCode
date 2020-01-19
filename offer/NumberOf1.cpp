/*
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

#include "iostream"
#include <vector>

using namespace std;

class Solution {
public:
    int NumberOf1(int n)
    {
        int result = 0;
        while(n != 0)
        {
            result++;
            n &= (n - 1);
        }

        return result;
    }
};

int main()
{
    Solution solution;
    int number = 8;
    int result = solution.NumberOf1(number);

    cout << result << endl;

	return 0;
}

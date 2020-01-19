/*
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

#include "iostream"
#include <vector>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent)
    {
        double result = 1.0;
        if(exponent == 0)
            return result;
        if(base == 0)
            return 0.0;

        if(exponent > 0)
        {
            for(int i = 0; i < exponent; i++)
            {
                result *= base;
            }
        }
        else if(exponent < 0)
        {
            for(int i = 0; i < -exponent; i++)
            {
                result /= base;
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    double base = 2.0;
    int exponent = -3;
    double result = solution.Power(base, exponent);

    cout << result << endl;

	return 0;
}

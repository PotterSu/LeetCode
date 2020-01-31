/*
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为k[0],k[1],...,k[m]。
请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*/

#include "iostream"
#include <vector>

using namespace std;

int cutRope(int number)
{
    if(number < 2)
        return 0;
    if(number == 2)
        return 1;
    if(number == 3)
        return 2;
    int a[number + 1];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    for(int i = 4; i <= number; i++)
    {
        int max = 0;
        for(int j = 0; j <= i / 2; j++)
        {
            if(a[j] * a[i-j] >= max)
            {
                max = a[j] * a[i-j];
                a[i] = max;
            }
        }
    }
    return a[number];
}

int main()
{
    int result = cutRope(8);
    cout << result << endl;

	return 0;
}

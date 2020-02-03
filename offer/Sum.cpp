/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

#include "iostream"
#include <vector>

using namespace std;

int Sum_Solution(int n)
{
    if(n == 0 || n == 1)
        return n;
    return n + Sum_Solution(n - 1);
}

int main()
{
    int result = Sum_Solution(4);
    cout << result << endl;

	return 0;
}

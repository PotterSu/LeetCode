/*
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。
习惯上我们把1当做是第一个丑数。
求按从小到大的顺序的第N个丑数。
*/

#include "iostream"
#include <vector>

using namespace std;

int GetUglyNumber_Solution(int index)
{
    if(index == 0)
        return 0;
    int p2 = 0;
    int p3 = 0;
    int p5 = 0;;
    vector<int> result(index);
    result[0] = 1;
    for(int i = 1; i < index; i++)
    {
        result[i] = min(min(2 * result[p2], 3 * result[p3]), 5 * result[p5]);
        if(result[i] % 2 == 0)
            p2 += 1;
        if(result[i] % 3 == 0)
            p3 += 1;
        if(result[i] % 5 == 0)
            p5 += 1;
    }
    return result[index - 1];
}

int main()
{
    int result = GetUglyNumber_Solution(11);
    cout << result << endl;

	return 0;
}

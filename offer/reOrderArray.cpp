/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include "iostream"
#include <vector>

using namespace std;

void reOrderArray(vector<int> &array)
{
    if(array.size() <= 1)
        return;
    int odd = 0;
    int even = 0;
    while(odd < array.size() && even < array.size())
    {
        //如果是偶数
        if(array[odd] % 2 == 0)
        {
            if(array[even] % 2 == 1 && even > odd)
            {
                int temp = array[even];
                for(int j = even; j > odd; j--)
                {
                    array[j] = array[j - 1];
                }
                array[odd] = temp;
                odd++;
                even = odd + 1;
            }
            else
            {
                even++;
            }
        }
        //如果是奇数
        else
        {
            odd++;
        }
    }
}

int main()
{
    vector<int> a(9);
    a = {3, 6, 1, 2, 4, 3, 4, 1, 3};

	reOrderArray(a);
    for(int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }

	return 0;
}

/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include "iostream"
#include <vector>

using namespace std;

bool Find(int target, vector<vector<int> > array)
{
    bool result = false;
    int m = array.size();
    if(m == 0)
        return result;
    int n = array[0].size();
    for(int i = 0; i < m; i++)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            if(array[i][j] == target)
                return true;
            else if(array[i][j] > target)
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> a(3);
    for(int i = 0; i < 3; i++)
    {
        a[i].resize(4);
    }
    a[0] = {1, 2, 3, 4};
    a[1] = {5, 6, 7, 8};
    a[2] = {10, 11, 12, 13};
	bool result = Find(9, a);
	cout << result << endl;

	return 0;
}

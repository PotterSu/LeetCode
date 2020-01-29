/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，
使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
对应每个测试案例，输出两个数，小的先输出。
*/

#include "iostream"
#include <vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum)
{
    vector<int> result;
    if(array.size() <= 1)
        return result;
    int product = 999999999;
    for(int i = 0; i < array.size() - 2; i++)
    {
        int start = i;
        int end = array.size() - 1;
        while(start < end)
        {
            if((array[start] + array[end]) == sum && (array[start] * array[end]) < product)
            {
                result.clear();
                result.push_back(array[start]);
                result.push_back(array[end]);
                product = array[start] * array[end];
                break;
            }
            else if((array[start] + array[end]) < sum)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> array{1, 3, 3, 5, 8, 10, 11};
	vector<int> result = FindNumbersWithSum(array, 6);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

	return 0;
}

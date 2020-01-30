/*
统计一个数字在排序数组中出现的次数。
*/

#include "iostream"
#include <vector>

using namespace std;

int GetFirstK(vector<int> data, int k, int left, int right)
{
    if(right == 0)
        return right;
    else if(data[right - 1] != k)
    {
        return right;
    }
    else
    {
        int mid = (left + right) / 2;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(data[mid] < k)
            {
                left = mid + 1;
            }
            else if(data[mid - 1] != k)
                return mid;
            else
                right = mid - 1;
        }
        return mid;
    }
}

int GetLastK(vector<int> data, int k, int left, int right)
{
    if(left == data.size() - 1)
        return left;
    else if(data[left + 1] > data[left])
        return left;
    else
    {
        int mid = (left + right) / 2;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(data[mid] > k)
                right = mid - 1;
            else if(data[mid + 1] != k)
                return mid;
            else
                left = mid + 1;
        }
        return mid;
    }
}

int GetNumberOfK(vector<int> data ,int k)
{
    if(data.size() == 0)
        return 0;
    int left = 0;
    int right = data.size() - 1;
    int first = 0;
    int last = -1;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(data[mid] < k)
        {
            left = mid + 1;
            continue;
        }
        else if(data[mid] > k)
        {
            right = mid - 1;
            continue;
        }
        else
        {
            first = GetFirstK(data, k, 0, mid);
            last = GetLastK(data, k ,mid, data.size() - 1);
            break;
        }
    }
    return last - first + 1;
}

int main()
{
    vector<int> data{3, 3, 3, 3, 4, 5};
    //vector<int> data{2};
	int result = GetNumberOfK(data, 3);
    cout << result << endl;

	return 0;
}

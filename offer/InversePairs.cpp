/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
1,2,3,4,5,6,7,0
7
*/

#include "iostream"
#include <vector>

using namespace std;

void Merge(vector<int>& data, int start, int mid, int end, int& count)
{
    int i = start;
    int j = mid + 1;
    vector<int> t;
    while(i <= mid && j <= end)
    {
        if(data[i] > data[j])
        {
            t.push_back(data[j++]);
            count = (count + (mid - i + 1)) % 1000000007;
        }
        else
        {
            t.push_back(data[i++]);
        }
    }
    while(i <= mid)
    {
        t.push_back(data[i++]);
    }
    while(j <= end)
    {
        t.push_back(data[j++]);
    }
    for(int i = 0; i < t.size(); i++)
    {
        data[start+i] = t[i];
    }
}

void MergeSort(vector<int>& data, int start, int end, int& count)
{
    if(start < end)
    {
        int mid = (start + end) >> 1;
        MergeSort(data, start, mid, count);
        MergeSort(data, mid + 1, end, count);
        Merge(data, start, mid, end, count);
    }
}

int InversePairs(vector<int> data)
{
    if(data.size() == 0)
    {
        return 0;
    }
    int count = 0;
    MergeSort(data, 0, data.size()-1, count);
    return count;
}

int main()
{
    vector<int> data{1, 2, 3, 4, 5, 6, 7, 0};
    int result = InversePairs(data);
    cout << result << endl;

	return 0;
}

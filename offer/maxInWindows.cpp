/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
*/

#include "iostream"
#include <vector>
#include <deque>

using namespace std;


vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> result;
    if(num.size() < size || size <= 0)
        return result;
    deque<int> dq;
    for(int i = 0; i < size; i++)
    {
        while(!dq.empty() && num[i] > num[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    result.push_back(num[dq.front()]);
    for(int i = size; i < num.size(); i++)
    {
        while(!dq.empty() && num[i] > num[dq.back()])
        {
            dq.pop_back();
        }
        if(!dq.empty() && (i - dq.front() + 1) > size)
        {
            dq.pop_front();
        }
        dq.push_back(i);
        result.push_back(num[dq.front()]);
    }
    return result;
}

int main()
{
    vector<int> num{2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> result = maxInWindows(num, 3);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

	return 0;
}

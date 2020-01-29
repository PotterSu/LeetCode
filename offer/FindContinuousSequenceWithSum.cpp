/*
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
*/

#include "iostream"
#include <vector>

using namespace std;

vector<vector<int>> FindContinuousSequence(int sum)
{
    vector<vector<int>> result;
    if(sum < 2)
        return result;
    for(int i = 1; i < sum - 1; i++)
    {
        int start = i;
        int end = sum - 1;
        while(start < end)
        {
            int currentSum = (start + end) * (end - start + 1) / 2;
            //如果相等
            if(currentSum == sum)
            {
                vector<int> temp;
                for(int j = start; j <= end; j++)
                {
                    temp.push_back(j);
                }
                result.push_back(temp);
                break;
            }
            //如果大
            else if(currentSum > sum)
            {
                end--;
                continue;
            }
            //如果小的话直接跳出
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
	vector<vector<int>> result = FindContinuousSequence(100);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}

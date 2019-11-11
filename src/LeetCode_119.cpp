/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]

*/
#include "iostream"
#include "string"
#include "algorithm"
#include "vector"

using namespace std;

vector<int> getRow(int rowIndex)
{
	vector<int> result;
	if(rowIndex == 0)
	{
		result.push_back(1);
		return result;
	}
	if(rowIndex == 1)
	{
		result.push_back(1);
		result.push_back(1);
		return result;
	}
	result.push_back(1);
	result.push_back(1);
	for(int nRow = 2; nRow < rowIndex + 1; nRow++)
	{
		vector<int> lastRow(result);
		result.clear();
		result.push_back(1);
		for(int nCol = 1; nCol < nRow; nCol++)
		{
			result.push_back(lastRow[nCol - 1] + lastRow[nCol]);
		}
		result.push_back(1);
	}
	return result;
}

int main()
{
	int nRow = 4;
	vector<int> result = getRow(nRow);
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}

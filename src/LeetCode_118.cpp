/*
118. Pascal's Triangle

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
*/
#include "iostream"
#include "string"
#include "algorithm"
#include "vector"

using namespace std;

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> result;
	if(numRows == 0)
	{
		return result;
	}
	//first row
	vector<int> tmp;
	tmp.push_back(1);
	result.push_back(tmp);
	if(numRows == 1)
	{
		return result;
	}
	//second row
	tmp.clear();
	tmp.push_back(1);
	tmp.push_back(1);
	result.push_back(tmp);
	if(numRows == 2)
	{
		return result;
	}
	//third row begin
	tmp.clear();
	for(int nRow = 2; nRow < numRows; nRow++)
	{
		tmp.push_back(1);
		for(int nCol = 1; nCol < nRow; nCol++)
		{
			tmp.push_back(result[nRow - 1][nCol - 1] + result[nRow - 1][nCol]);
		}
		tmp.push_back(1);
		result.push_back(tmp);
		tmp.clear();
	}
	return result;
}

int main()
{
	int numRows;
	while(1)
	{
		cin >> numRows;
		vector<vector<int>> result = generate(numRows);
		for (int i = 0; i < result.size(); i++)
		{
			cout << endl;
			for (int j = 0; j < result[i].size(); j++)
				cout << result[i][j] << " ";
		}
	}
	return 0;
}

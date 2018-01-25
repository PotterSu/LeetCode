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

解题思路： 首先存第一行 1
               和第二行 1 1
			   然后第三行开始，result[i][j] = result[i - 1][j - 1] + result[i - 1][j]
			                   其中i表示第i行，j表示第i行的第2个数到倒数第2个数
*/

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> result;
	if (numRows == 0)
		return result;
	vector<int> temp1;
	temp1.push_back(1);
	result.push_back(temp1);
	if (numRows == 1)
	{
		return result;
	}
	vector<int> temp2;
	temp2.push_back(1);
	temp2.push_back(1);
	result.push_back(temp2);
	for (int i = 2; i < numRows; i++)
	{
		vector<int> temp;
		temp.push_back(1);
		for (int j = 1; j <= i - 1; j++)
		{
			temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
		}
		temp.push_back(1);
		result.push_back(temp);
	}
	return result;
}

int main()
{
	int numRows;
	cin >> numRows;
	vector<vector<int>> result = generate(numRows);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
	}
	while (1);
	return 0;
}


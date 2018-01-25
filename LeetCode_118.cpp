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

����˼·�� ���ȴ��һ�� 1
               �͵ڶ��� 1 1
			   Ȼ������п�ʼ��result[i][j] = result[i - 1][j - 1] + result[i - 1][j]
			                   ����i��ʾ��i�У�j��ʾ��i�еĵ�2������������2����
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


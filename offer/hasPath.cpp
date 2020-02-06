/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

#include "iostream"
#include <vector>

using namespace std;

bool search(char* matrix, char* str, int rows, int cols, int row, int col, vector<vector<int>> m, int depth)
{
	if(str[depth] == '\0')
		return true;
	if(row >= 0 && row < rows && col >= 0 && col < cols &&
	   matrix[row * cols + col] == str[depth] && m[row][col] == 0)
	{
		m[row][col] = 1;

		bool top = search(matrix, str, rows, cols, row-1, col, m, depth+1);
		bool bottom = search(matrix, str, rows, cols, row+1, col, m, depth+1);
		bool left = search(matrix, str, rows, cols, row, col-1, m, depth+1);
		bool right = search(matrix, str, rows, cols, row, col+1, m, depth+1);

		return top || bottom || left || right;
	}
	return false;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if(matrix == NULL || str == NULL || rows < 1 || cols < 1)
	{
		return false;
	}
	vector<vector<int>> m(rows);
	for(int i = 0; i < rows; i++)
	{
		m[i].resize(cols);
	}
	int depth = 0;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			if(search(matrix, str, rows, cols, i, j, m, depth))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	char* matrix = "abcesfcsadee";
	char* str = "bcced";
	bool result = hasPath(matrix, 3, 4, str);
	cout << result << endl;

	return 0;
}

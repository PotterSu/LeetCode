/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵：
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
则依次打印出数字
1,2,3,4,
8,12,16,15,
14,13,9,5,
6,7,11,10.
*/

#include "iostream"
#include <vector>

using namespace std;

vector<int> printMatrix(vector<vector<int>> matrix)
{
    vector<int> result;
    if(matrix.size() == 0)
        return result;
    int left = 0;
    int top = 0;
    int bottom = matrix.size() - 1;
    int right = matrix[0].size() - 1;
    while(true)
    {
        //从左往右
        for(int j = left; j <= right; j++)
        {
            result.push_back(matrix[top][j]);
        }
        top++;
        if(top > bottom)
            break;
        //从上往下
        for(int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;
        if(right < left)
            break;
        //从右往左
        for(int j = right; j >= left; j--)
        {
            result.push_back(matrix[bottom][j]);
        }
        bottom--;
        if(top > bottom)
            break;
        //从下往上
        for(int i = bottom; i >= top; i--)
        {
            result.push_back(matrix[i][left]);
        }
        left++;
        if(right < left)
            break;
    }
    return result;
}

int main()
{
    vector<vector<int>> a(4);
    for(int i = 0; i < a.size(); i++)
    {
        a[i].resize(4);
    }
    a[0] = {1, 2, 3, 4};
    a[1] = {5, 6, 7, 8};
    a[2] = {9, 10, 11, 12};
    a[3] = {13, 14, 15, 16};

	vector<int> result = printMatrix(a);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

	return 0;
}

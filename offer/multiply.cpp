/*
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

#include "iostream"
#include <vector>

using namespace std;

vector<int> multiply(const vector<int>& A)
{
    vector<int> C(A.size());
    C[0] = 1;
    for(int i = 1; i < A.size(); i++)
    {
        C[i] = C[i-1] * A[i-1];
    }
    vector<int> D(A.size());
    D[A.size() - 1] = 1;
    for(int i = A.size() - 2; i >= 0; i--)
    {
        D[i] = D[i+1] * A[i+1];
    }
    vector<int> B(A.size());
    for(int i = 0; i < A.size(); i++)
    {
        B[i] = C[i] * D[i];
    }
    return B;
}

int main()
{
    vector<int> A{1, 2, 3, 4, 5};
    vector<int> result = multiply(A);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

	return 0;
}

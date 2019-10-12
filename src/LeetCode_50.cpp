/*
50.Pow(x, n)

Implement pow(x, n)

����˼·�����n = 0,ֱ�ӷ���1
          ��Ϊn���ܴܺ�����Ҫ��һ��long long���͵�p��n
		  ���p<0��x=1/x��p = -p;
		  ������ÿ����n/2��������������
		  ���շ��ؽ��
Ҫ����n<0��n�ܴ�,�Լ�O(n)��ʱ�����⣬�����ö�������
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

double myPow(double x, int n) {
	if (n == 0)
		return 1;
	long long p = n;
	if (p < 0)
	{
		x = 1 / x;
		p = -p;
	}
	int half = p / 2;
	double result;
	if (p % 2 == 0)
	{
		result = myPow(x*x, half);
	}
	if (p % 2 != 0)
	{
		result = myPow(x*x, half);
		result = x*result;
	}

	return result;
}


int main()
{
	double x;
	int n;
	cin >> x;
	cin >> n;
	double result = myPow(x, n);
	cout << result << endl;
	while (1);
	return 0;
}


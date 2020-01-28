/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
*/

#include "iostream"
#include <vector>

using namespace std;


void FindNumsAppearOnce(vector<int> data,int* num1,int *num2)
{
    int a = 0;
    for(int i = 0; i < data.size(); i++)
    {
        a ^= data[i];
    }
    int index = 1;
    //如果a的某位不为1,进1,直到找到某位相同
    while((index & a) == 0)
    {
        index = index << 1;
    }
    for(int i = 0; i < data.size(); i++)
    {
        if((data[i] & index) == 0)
        {
            num1[0] ^= data[i];
        }
        else
        {
            num2[0] ^= data[i];
        }
    }
}

int main()
{
    vector<int> data{2,2,1,3,3,4,4,5};
    int* num1 = new int[1];
    int* num2 = new int[1];

    FindNumsAppearOnce(data, num1, num2);

    cout << num1[0] << endl;
    cout << num2[0] << endl;

    delete []num1;
    delete []num2;
	return 0;
}

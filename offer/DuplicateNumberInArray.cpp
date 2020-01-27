/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内。
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。
请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2,3,1,6,2,5,3}，那么对应的输出是第一个重复的数字2。
*/

#include "iostream"
#include <vector>

using namespace std;

// Parameters:
// numbers:     an array of integers
// length:      the length of array numbers
// duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false
//1 3 2 6 2 5 3
//3 1 2 6 2 5 3
//6 1 2 3 2 5 3
//
bool duplicate(int numbers[], int length, int* duplication)
{
    for(int i = 0; i < length; i++)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                duplication[0] = numbers[i];
                return true;
            }
            else
            {
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
    }
    return false;
}

int main()
{
    int numbers[] = {2,3,1,6,2,5,3};
    int* result = new int[1];
	bool flag = duplicate(numbers, 7, result);
	cout << result[0] << endl;
    cout << flag << endl;

    delete []result;
    result = NULL;

	return 0;
}

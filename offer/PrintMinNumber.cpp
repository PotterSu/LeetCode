/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

#include "iostream"
#include <vector>

using namespace std;

string PrintMinNumber(vector<int> numbers)
{
    string result = "";
    for(int i = 0; i < numbers.size(); i++)
    {
        for(int j = i + 1; j < numbers.size(); j++)
        {
            string a = to_string(numbers[i]);
            string b = to_string(numbers[j]);
            if((a + b) >= (b + a))
            {
                int temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = temp;
            }
        }
        result += to_string(numbers[i]);
    }
    return result;
}

int main()
{
    vector<int> numbers{3, 32, 321};
    string result = PrintMinNumber(numbers);
    cout << result << endl;

	return 0;
}

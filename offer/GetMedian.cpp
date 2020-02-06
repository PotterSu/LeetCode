/*
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/
#include "iostream"
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> minHeap;//大数 小顶堆
vector<int> maxHeap;//小数 大顶堆

void Insert(int num)
{
	int size = minHeap.size() + maxHeap.size();
	//当前偶数
	if((size & 1) == 0)
	{
		if(maxHeap.size() > 0 && num < maxHeap[0])
		{
			maxHeap.push_back(num);
			push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
			num = maxHeap[0];
			//将堆顶放到最后
			pop_heap(maxHeap.begin(), maxHeap.end(), less<int>());
			maxHeap.pop_back();
		}
		minHeap.push_back(num);
		push_heap(minHeap.begin(), minHeap.end(), greater<int>());
	}
	else
	{
		if(minHeap.size() > 0 && num > minHeap[0])
		{
			minHeap.push_back(num);
			push_heap(minHeap.begin(), minHeap.end(), greater<int>());
			num = minHeap[0];
			pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
			minHeap.pop_back();
		}
		maxHeap.push_back(num);
		push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
	}
}

double GetMedian()
{
	int size = minHeap.size() + maxHeap.size();
	if(size == 0)
		return 0;
	if((size & 1) == 0)
	{
		return (maxHeap[0] + minHeap[0]) / 2.0;
	}
	else
	{
		return minHeap[0];
	}
}

int main()
{
	Insert(3);
	Insert(1);
	Insert(2);
	Insert(4);
	Insert(5);
	double result = GetMedian();
	cout << result << endl;

	return 0;
}

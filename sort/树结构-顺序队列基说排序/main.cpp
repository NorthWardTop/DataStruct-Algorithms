#include "sort.h"

int main()
{
	int arr[LEN] = {};
	//获得系统的毫秒级时间, 从开机到现在经过的时间
	srand(timeGetTime());
	for (int i = 0; i < LEN; ++i)
	{
		arr[i] = rand();
	}
	printArr(arr,LEN);
	radixSort(arr, LEN);
	printArr(arr, LEN);

	system("pause");
	return 0;
	
}
#include "sort.h"

int main()
{
	int arr[LEN] = {};
	//���ϵͳ�ĺ��뼶ʱ��, �ӿ��������ھ�����ʱ��
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
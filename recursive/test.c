/*
 * @Author: northward
 * @Github: https://github.com/northwardtop
 * @Date: 2019-07-06 11:13:05
 * @LastEditors: northward
 * @LastEditTime: 2019-07-06 11:44:58
 * @Description: 测试例子, 概述
 */
#include <stdio.h>
#include <stdlib.h>


//递归打印一个数字的每一位
void print_out(int n)
{
	if (n >= 10)
		print_out(n/10); //递归句
	printf("%d\n", n%10);
}



int main()
{
	print_out(76234);
	return 0;
}


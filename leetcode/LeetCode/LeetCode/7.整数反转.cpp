#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;


class Solution {
public:
	int reverse(int x) {
		int y = 0;
		//int level = 10;
		vector<short> stk;

		if (x < -(pow(2, 31)) || x > (pow(2, 31) - 1))
			return y;
		int copyX = abs(x);
		int tmp = 0;
		while (copyX)
		{
			tmp = copyX % 10;
			stk.push_back(tmp);
			copyX /= 10;
			//level *= 10;
			//cout << tmp;
		}
		__int64 level = 1;
		for (int size = stk.size() - 1; size >= 0; --size)
		{
			/*tmp = stk.front();
			stk.pop_();*/
			//cout <<'t'<< stk.at(size) * level;
			y += stk.at(size) * level;
			level *= 10;
			
		}
		if (x < -(pow(2, 31)) || x >(pow(2, 31) - 1))
			return y;
		if (x < 0)
			y = -y;
		

		return y;
	}
};


int main()
{
	Solution sln;
	
	cout << sln.reverse(1534236469) << endl;
	int i = 0;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << pow(2, 31)-1;
	system("pause");
	return 0;
}

//
////����I���������
////[ע��]������int,�޷��Żᵼ��--i�쳣
////ͨ������ListCtrl�б�������ɾ��(���������Ӻ���ǰɾ��)
//int nSize = (int)vecInt.size();
//for (int i = (nSize - 1); i >= 0; --i)
//{
//	cout << vecInt.at(i) << endl;
//}
//
////����II����ͨ�������������
//vector<int>::iterator iter = vecInt.end();
//for (; iter != vecInt.begin(); ++iter)
//{
//	cout << *(--iter) << endl;
//}
//
////����III��������������
//vector<int>::reverse_iterator iter = vecInt.rbegin();
//for (; iter != vecInt.rend(); ++iter)
//{
//	cout << *iter << endl;
//}
//-------------------- -
//���ߣ�jiangqin115
//��Դ��CSDN
//ԭ�ģ�https ://blog.csdn.net/jiangqin115/article/details/43699615 
//��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
//
//

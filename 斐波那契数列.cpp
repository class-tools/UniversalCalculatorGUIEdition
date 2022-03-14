#include <iostream>
#include <unistd.h>
using namespace std;
long long fbnq(long long x)
{
	if(x==1||x==2)
	{
		return 1;
	}
	return fbnq(x-1)+fbnq(x-2);
}
int main()
{
	cout << "斐波那契数列计算器：输入一个数n，输出斐波那契数列的第n项。" << endl;
	a:long long u;
	cin >> u;
	cout << fbnq(u) << endl;
	goto a;
	return 0;
}

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
	cout << "쳲��������м�����������һ����n�����쳲��������еĵ�n�" << endl;
	a:long long u;
	cin >> u;
	cout << fbnq(u) << endl;
	goto a;
	return 0;
}

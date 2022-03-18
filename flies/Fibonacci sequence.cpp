#include <iostream>
#include <unistd.h>
using namespace std;
long long k[3];
int main()
{
	cout << "斐波那契数列计算器：输入一个数n，输出斐波那契数列的第n项。" << endl;
	a:long long u;
	cin >> u;
	k[0]=k[1]=1;
	for(int i=2;i<u;i++)
	{
		k[i%3]=k[(i-1)%3]+k[(i-2)%3];
	}
	cout << k[(u-1)%3] << endl;
	goto a;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
char a[999999999];
int main()
{
	cout << "2进制转10进制" << endl;
	cout << "使用说明：输入一个二进制数，按Enter键即可输出对应十进制的值。" << endl;
	for(long long z=0;z<1;z--)
	{
		char b;
		long long c,d=0,e=0;
			gets(a);
			c=strlen(a);
			for(long long f=0;f<c/2;f++)
			{
				b=a[f];
				a[f]=a[c-f-1];
				a[c-f-1]=b;
			}
			for(long long g=0;g<=c-1;g++)
			{
				if(a[g]=='1')
				{
					e=pow(2,g);
					d+=e;
				}
			}
			cout << d << endl;
	}
}

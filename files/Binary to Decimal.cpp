#include <bits/stdc++.h>
using namespace std;
char a[999999999];
int main()
{
	cout << "2����ת10����" << endl;
	cout << "ʹ��˵��������һ��������������Enter�����������Ӧʮ���Ƶ�ֵ��" << endl;
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

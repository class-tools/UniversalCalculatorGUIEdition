#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	cout << "�ַ����ָ�����������Ҫ�ָ���ַ�����������ָ������ַ����ͷָ���һ��һ��������Enter��������������" << endl;
	x:string a,b[100];
	char f; 
	long long d=0,c=0,e=0;
	getline(cin,a);
	f=getchar();
	for(long long i=0;i<a.size();i++)
	{
		if(a[i]==f)
		{
			b[c]=a.substr(d,e);
			c++;
			d=i+1;
			e=0;
			continue;
		}
		e++;
		if(a.size()-i==1)
		{
			b[c]=a.substr(d,e);
		}
	}
	for(long long i=0;i<=c;i++)
	{
		cout << b[i] << endl;
	}
	goto x;
}

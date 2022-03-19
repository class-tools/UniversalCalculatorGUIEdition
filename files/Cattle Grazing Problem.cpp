#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c,d,e,f,g,h,i,l,m;
	char n,o;
	cout << "牛吃草问题" << endl;
	cout << "使用说明：" << endl;
	cout << "1、本程序支持草增长、减少求牛数、天数。" << endl;
	cout << "2、输入5个数（前4个是条件，几头牛吃几天），再输入符号+/-（草增长/减少）、d/n（求天数/牛数），按下Enter键即可求出结果。" << endl;
	for(long long x=1;x<=1;x--)
	{
		cin >> a >> b >> c >> d >> e >> n >> o;
		if(n=='+')
		{
		    if(o=='d')
		    {
		        f=a*b;
		        g=c*d;
		        h=abs(f-g);
		        i=abs(b-d);
		        l=h/i;
		        m=l*b;
		        cout << (f-m)/(e-l) << endl;
		    }
		    if(o=='n')
		    {
		        f=a*b;
		        g=c*d;
		        h=abs(f-g);
		        i=abs(b-d);
		        l=h/i;
		        m=(a-l)*b/e;
		        cout << m+l << endl;
		    }
		    if(o!='d'&&o!='n')
		    {
		    	cout << "" << endl;
		    }
		}
		if(n=='-')
		{
			cin >> c >> d >> e >> n >> o;
		    if(o=='d')
		    {
		        f=a*b;
		        g=c*d;
		        h=abs(f-g);
		        i=abs(b-d);
		        l=h/i;
		        m=f+b*l;
		        cout << m/(l+e) << endl;
		    }
		    if(o=='n')
		    {
		        f=a*b;
		        g=c*d;
		        h=abs(f-g);
		        i=abs(b-d);
		        l=h/i;
		        m=f+b*l;
		        cout << (m-e*l)/30 << endl;
		    }
		    if(o=='n'&&o!='d')
		    {
		    	cout << "" << endl;
		    }
		}
	}
	return 0;
}

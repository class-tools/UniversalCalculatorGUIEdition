#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c,d,e,f,g,h,i,l,m;
	char n,o;
	cout << "ţ�Բ�����" << endl;
	cout << "ʹ��˵����" << endl;
	cout << "1��������֧�ֲ�������������ţ����������" << endl;
	cout << "2������5������ǰ4������������ͷţ�Լ��죩�����������+/-��������/���٣���d/n��������/ţ����������Enter��������������" << endl;
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

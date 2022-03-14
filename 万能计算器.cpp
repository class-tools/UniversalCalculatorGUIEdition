#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
double b,c,h,m,hs;//b��c��d��h��m�������룬���ɵ��á�
long long e,f=2,g,k[10005][10005],l,x[42][42],j,bug;
char d;
bool prime(long long a)//�ж�������aΪ���жϵ�����
{
	if(a<2)
	{
		return 0;
	}
	for(long long i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			return 0;
		}
	}
	return 1;
}
long long axy(long long a,long long b)//���������㣬aΪ�½Ǳ꣬bΪ�ϽǱꡣ
{
	if(a<b||a<0||b<0)
	{
		return -1;
	}
	long long c=1;
	for(long long i=1;i<=b;i++)
	{
		c*=a;
		a--;
	}
	return c;
}
long long yhsjzhqh(double a)//�������������ͣ�a��ʾ��͵��ǵڼ��С�
{
	if(a!=(int)a||a<=0)
	{
		return 0;
	}
	return pow(2,a-1);
}
long long yhsjqx(double a,double b)//����������a��ʾ�У�b��ʾ�С�
{
	if(a<b||a!=(int)a||b!=(int)b)
	{
		return 0;
	}
	if(b==1||b==a)
	{
		return 1;
	}
	return axy(a-1,b-1)/axy(b-1,b-1);
}
void huanfang(long long a)//�����׻÷���a��ʾ�÷�������
{
	if(a%2==0)
	{
		cout << "ֻ�������������ף�" << endl;
		return;
	}
	for(short i=0;i<a;i++)
	{
	    for(short j=0;j<a;j++)
	    {
	        k[i][j]=0;
	        x[i][j]=0;
	    }
	}
	l=0;
	e=a/2;
	k[l][e]=1;
	x[l][e]=1;
	while(f<=pow(a,2))
	{
	    if(l-1<0||e+1>a-1)
	    {
	        if(l-1>=0&&e+1>a-1)
	        {
	            k[l-1][0]=f;
	            x[l-1][0]=1;
	            l--;
	            e=0;
	            f++;
	        }
	        else if(l-1<0&&e+1<=a-1)
	        {
	            k[a-1][e+1]=f;
	            x[a-1][e+1]=1;
	            l=a-1;
	            e++;
	            f++;
	        }
	        else if(l==0&&e==a-1)
	        {
	            k[l+1][a-1]=f;
	            x[l+1][a-1]=1;
	            l++;
	            f++;
	        }
	    }
	    else if(k[l][e]!=0&&x[l-1][e+1]==1)
	    {
	        k[l+1][e]=f;
	        x[l+1][e]=1;
	        l++;
	        f++;
	    }
	    else if(l-1>=0&&e+1<=a-1)
	    {
	        k[l-1][e+1]=f;
	        x[l-1][e+1]=1;
	        l--;
	        e++;
	        f++;
	    }
	}
	for(short i=0;i<a;i++)
	{
	    for(short j=0;j<a;j++)
	    {
	        cout << k[i][j] << " ";
	    }
	    cout << endl;
	}
}
long long gcd(long long a,long long b)//��a��b�����������
{
	if(a%b==0)
	{
		return b;
	}
	return gcd(b,a%b);
}
long long jttl(double a,double b,double c,double d)//����ͬ����a��ʾͷ����b��ʾ������c��ʾ��������d��ʾ�ý�����
{
	if(a!=(int)a||b!=(int)b||c!=(int)c||d!=(int)d||a<0||b<0||c<0||d<0)
	{
		return -1;
	}
	return (b-a*c)/d-c;
}
long long dsgcd(double a)//���������a��ʾ��������������ĸ�����
{
	if(a<1||a!=(int)a)
	{
		return 0;
	}
	for(short i=0;i<a;i++)
	{
		if(k[0][i]<1)
		{
			return 0;
		}
	}
	for(short i=1;i<a;i++)
	{
		if(i==1)
		{
			j=gcd(k[0][i-1],k[0][i]);
			continue;
		}
		j=gcd(j,k[0][i]);
	}
	return j;
}
long long dslcm(double a)//��С��������a��ʾ�����¹����������ĸ�����
{
	if(a<1||a!=(int)a)
	{
		return 0;
	}
	for(short i=0;i<a;i++)
	{
		if(k[0][i]<1)
		{
			return 0;
		}
	}
	for(short i=1;i<a;i++)
	{
		if(i==1)
		{
			j=k[0][i-1]/gcd(k[0][i-1],k[0][i])*k[0][i];
			continue;
		}
		j=j/gcd(j,k[0][i])*k[0][i];
	}
	return j;
}
void random(long long a,long long b,long long c)//��������ɣ�����c��[a,b]��Χ�ڵ��������
{
	srand(time(0));
	for(long long i=0;i<c;i++)
	{
		cout << rand()%(b-a+1)+a << " ";
	}
	cout << endl;
}
int main()
{
	cout << "���ܼ�����" << endl;
	cout << "ʹ��˵����" << endl;
	cout << "ÿ�ֹ��ܾ�����������������ʾ��" << endl;
	cout << "�ӷ������������+����һ����������Enter����������" << endl;
	cout << "��������������-�ͼ���������Enter����������" << endl;
	cout << "�˷���������*����һ����������Enter����������" << endl;
	cout << "��������������/�ͳ�������Enter����������" << endl;
	cout << "�˷���������d��ָ������Enter����������" << endl;
	cout << "�����������С�e���У���Enter����������" << endl;
	cout << "���������㣺�½Ǳꡢa���ϽǱ꣬��Enter����������" << endl;
	cout << "��������㣺�½Ǳꡢc���ϽǱ꣬��Enter����������" << endl;
	cout << "��ƽ��������������g����Enter����������" << endl;
	cout << "�ж����������ж�����p����Enter����������" << endl;
	cout << "�������������ͣ�������b����Enter����������" << endl;
	cout << "�����׻÷���������h����Enter����������" << endl;
	cout << "������������ĸ�����С���ţ�Ӣ�ģ���n�����ĸ������������������������Enter����������" << endl;
	cout << "��С�����������ĸ����������ţ�Ӣ�ģ���n�����ĸ�����������С��������������Enter����������" << endl;
	cout << "����ͬ����ͷ����f�����������������ý��������������ý���������Enter����������" << endl;
	cout << "��������ɣ��������Χ��һ����~��һ������ǰ��С�ڵ��ں��ߣ���Χ�������������������ɵĸ�����" << endl;
	cout << "ע�����ÿ������һ����������һ���ո���������ź�һ�������롣�뾡����Ҫ�������ķ��ţ�����Ӱ���������顣" << endl;
	cout << "������Ӣ�����뷨��ʹ�á�" << endl;
	while(1)
	{
		cin >> b >> d;
		if(d!='g'&&d!='G'//��ƽ����
		&&d!='p'&&d!='P'//�ж�������
		&&d!='b'&&d!='B'//�������������͡�
		&&d!='h'&&d!='H'//�����׻÷���
		&&d!='('&&d!=')'//���������
		&&d!='['&&d!=']'//��С��������
		&&d!='+'&&d!='-'//�ӷ���������
		&&d!='*'&&d!='/'//�˷���������
		&&d!='d'&&d!='D'//�˷���
		&&d!='e'&&d!='E'//����������
		&&d!='f'&&d!='F'//����ͬ����
		&&d!='a'&&d!='A'//���������㡣
		&&d!='c'&&d!='C'//��������㡣
		&&d!='~')//��������ɡ�
		{
			if(bug>0)
			{
				cout << "����bug���Զ���������" << endl;
				return 0;
			}
			cout << "�޴˷��ţ�" << endl;
			bug++;
			continue;
		}
		bug=0;
		if(d=='g'||d=='G')
		{
			cout << sqrt(b) << endl;
			continue;
		}
		else if(d=='p'||d=='P')
		{
			g=b;
			if(prime(g)==0||b!=g)
			{
				cout << b << "����������" << endl;
				continue;
			}
			cout << b << "��������" << endl;
			continue;
		}
		else if(d=='b'||d=='B')
		{
			hs=yhsjzhqh(b);
			if(hs==0)
			{
				cout << "��������������" << endl;
				continue;
			}	
			cout << hs << endl;
			continue;
		}
		else if(d=='h'||d=='H')
		{
			huanfang(b);
			continue;
		}
		else if(d=='('||d==')')
		{
			for(short i=0;i<b;i++)
			{
				cin >> k[0][i];
			}
			hs=dsgcd(b);
			if(hs==0)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		else if(d=='['||d==']')
		{
			for(short i=0;i<b;i++)
			{
				cin >> k[0][i];
			}
			hs=dslcm(b);
			if(hs==0)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		cin >> c;
		if(d=='+')
		{
			cout << b+c << endl;
			continue;
		}
		else if(d=='-')
		{
			cout << b-c << endl;
			continue;
		}
		else if(d=='*')
		{
			cout << b*c << endl;
			continue;
		}
		else if(d=='/')
		{
			if(c==0)
			{
				cout << "0������������" << endl;
				continue;
			}
			cout << b/c << endl;
			continue;
		}
		else if(d=='d'||d=='D')
		{
			cout << pow(b,c) << endl;
			continue;
		}
		else if(d=='e'||d=='E')
		{
			hs=yhsjqx(b,c);
			if(hs==0)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		else if(d=='a'||d=='A')
		{
			hs=axy(b,c);
			if(hs==-1)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		else if(d=='c'||d=='C')
		{
			hs=axy(b,c)/axy(c,c);
			if(axy(b,c)==-1||axy(c,c)==-1)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		cin >> h;
		if(d=='~')
		{
			if(b!=(int)b||c!=(int)c||h!=(int)h||b<0||c<0||d<0||h<0||b>c)
			{
				cout << "�������" << endl;
				continue;
			}
			random(b,c,h);
			continue;
		}
		cin >> m;
		if(d=='f'||d=='F')
		{
			g=jttl(b,c,h,m);
			if(g==-1)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << "����" << b-g << "ֻ���ã�" << g << "ֻ��" << endl;
		}

	}
}

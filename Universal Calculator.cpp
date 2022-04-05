#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
string s;
double in1,in3,in4,in5,hs;//in1��in2��in3��in4��in5�������룬���ɵ��á��������Ϊ���������
long long e,f,g,k[10005][10005],l,x[10005][10005],j,bug;
char in2;
bool prime(long long p)//�ж�������pΪ���жϵ�����
{
	if(p<2)
	{
		return 0;
	}
	for(long long i=2;i<=sqrt(p);i++)
	{
		if(p%i==0)
		{
			return 0;
		}
	}
	return 1;
}
long long gcd(long long a,long long b)//��a��b�����������
{
	if(a%b==0)
	{
		return b;
	}
	return gcd(b,a%b);
}
long long dsgcd(double n)//���������n��ʾ��������������ĸ�����
{
	if(n<2||n!=(int)n)
	{
		return 0;
	}
	for(short i=0;i<n;i++)
	{
		if(k[0][i]<1)
		{
			return 0;
		}
	}
	for(short i=1;i<n;i++)
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
long long dslcm(double n)//��С��������n��ʾ�����¹����������ĸ�����
{
	if(n<1||n!=(int)n)
	{
		return 0;
	}
	for(short i=0;i<n;i++)
	{
		if(k[0][i]<1)
		{
			return 0;
		}
	}
	for(short i=1;i<n;i++)
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
long long fbnqqx(double n)//쳲������������n��ʾ����ǵ�n�
{
	if(n!=(int)n||n<1)
	{
		return 0;
	}
	k[0][0]=k[0][1]=1;
	for(long long i=2;i<n;i++)
	{
		k[0][i%3]=k[0][(i-1)%3]+k[0][(i-2)%3];
	}
	return k[0][(int)(n-1)%3];
}
long long yhsjzhqh(double n)//�������������ͣ�n��ʾ��͵��ǵ�n�С�
{
	if(n!=(int)n||n<=0)
	{
		return 0;
	}
	return pow(2,n-1); 
}
void huanfang(long long n)//�����׻÷���n��ʾ�÷�������
{
	if(n%2==0)
	{
		cout << "ֻ�������������ף�" << endl;
		return;
	}
	for(short i=0;i<n;i++)
	{
	    for(short j=0;j<n;j++)
	    {
	        k[i][j]=x[i][j]=0;
	    }
	}
	l=0;
	f=2;
	e=n/2;
	k[l][e]=x[l][e]=1;
	while(f<=pow(n,2))
	{
	    if(l-1<0||e+1>n-1)
	    {
	        if(l-1>=0&&e+1>n-1)
	        {
	            k[l-1][0]=f;
	            x[l-1][0]=1;
	            l--;
	            e=0;
	            f++;
	        }
	        else if(l-1<0&&e+1<=n-1)
	        {
	            k[n-1][e+1]=f;
	            x[n-1][e+1]=1;
	            l=n-1;
	            e++;
	            f++;
	        }
	        else if(l==0&&e==n-1)
	        {
	            k[l+1][n-1]=f;
	            x[l+1][n-1]=1;
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
	    else if(l-1>=0&&e+1<=n-1)
	    {
	        k[l-1][e+1]=f;
	        x[l-1][e+1]=1;
	        l--;
	        e++;
	        f++;
	    }
	}
	for(short i=0;i<n;i++)
	{
	    for(short j=0;j<n;j++)
	    {
	        cout << k[i][j] << " ";
	    }
	    cout << endl;
	}
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
long long yhsjqx(double x,double y)//����������x��ʾ�У�y��ʾ�С�
{
	if(x<y||x!=(int)x||y!=(int)y)
	{
		return 0;
	}
	if(y==1||y==x)
	{
		return 1;
	}
	return axy(x-1,y-1)/axy(y-1,y-1);
}
void jzzh(short m,string s,short n)//����ת������������m��ʾ��ת�����Ľ��ƣ�s��ʾ��ת��������n��ʾת����Ľ��ơ�
{
	g=s.size();
	for(long long i=0;i<g;i++)
	{
		if(s[i]<='9')
		{
			k[0][i]=s[i]-48;
		}
		if(s[i]>='A')
		{
			k[0][i]=s[i]-55;
		}
	}
	for(long long i=g-1;i>=0;i--)
	{
		e+=k[0][i]*pow(m,f);
		f++;
	}
	j=0;
	while(e!=0)
	{
		x[0][j]=e%n;
		e/=n;
		j++;
	}
	for(long long i=j-1;i>=0;i--)
	{
		if(x[0][i]<=9)
		{
			cout << x[0][i];
		}
		if(x[0][i]>=10)
		{
			cout << (char)(x[0][i]+55);
		}
	}
	cout << endl;
}
long long ksm(long long a,long long b,long long n)//�˷��������ݣ���ksm(a,b,n)��ʾa��b�η�ģn��
{
	if(b==0)
	{
		return 1%n;
	}
	if(b==1)
	{
		return a%n;
	}
	e=ksm(a,b/2,n);
	if(b%2==0)
	{
		return e%n*e%n;
	}
	else
	{
		return e%n*e%n*a%n;
	}
}
void random(long long a,long long b,long long n)//��������ɣ�����n��[a,b]��Χ�ڵ��������
{
	srand(time(0));
	for(long long i=0;i<n;i++)
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
	cout << "��������������-�ͼ�������Enter����������" << endl;
	cout << "�˷���������*����һ����������Enter����������" << endl;
	cout << "��������������/�ͳ�������Enter����������" << endl;
	cout << "�˷���������d��ָ���Լ����Ҫģ�����������Ҫȡģ����1������Enter����������" << endl;
	cout << "��ƽ��������������g����Enter����������" << endl;
	cout << "�ж����������ж�����p����Enter����������" << endl;
	cout << "���������㣺�½Ǳꡢa���ϽǱ꣬��Enter����������" << endl;
	cout << "��������㣺�½Ǳꡢc���ϽǱ꣬��Enter����������" << endl;
	cout << "������������ĸ�����С���ţ�Ӣ�ģ���n�����ĸ������������������������Enter����������" << endl;
	cout << "��С�����������ĸ����������ţ�Ӣ�ģ���n�����ĸ�����������С��������������Enter����������" << endl;
	cout << "�Ȳ�������ĩ���һ�s���ڶ������������Enter����������" << endl;  
	cout << "쳲�������������ڼ����f����Enter����������" << endl;
	cout << "�������������ͣ�������b����Enter����������" << endl;
	cout << "�����������С�e���У���Enter����������" << endl;
	cout << "ţ�Բ����⣺5������ǰ4������������ͷţ�Լ��죬�ڵ�һ�����͵ڶ�����֮������n�������������+/-��������/���٣���d/n��������/ţ��������Enter����������" << endl;
	cout << "����ͬ����ͷ����j�����������������ý��������������ý���������Enter����������" << endl;
	cout << "�����׻÷���������h����Enter����������" << endl;
	cout << "����ת��������������ת�����Ľ��ƣ�16���Ƽ����ڣ���:����ת������ת����Ľ��ƣ�16���Ƽ����ڣ�����Enter����������" << endl;
	cout << "��������ɣ��������Χ��һ����~��һ������ǰ��С�ڵ��ں��ߣ���Χ�������������������ɵĸ�����" << endl;
	cout << "ע�����ÿ������һ����������һ���ո���������ź�һ�������롣�뾡����Ҫ�������ķ��ţ�����Ӱ���������顣" << endl;
	cout << "������Ӣ�����뷨��ʹ�á�" << endl;
	while(1)
	{
		cin >> in1 >> in2;
		if(in2!='+'&&in2!='-'//�ӷ���������
		&&in2!='*'&&in2!='/'//�˷���������
		&&in2!='d'&&in2!='D'//�˷���
		&&in2!='g'&&in2!='G'//��ƽ����
		&&in2!='p'&&in2!='P'//�ж�������
		&&in2!='a'&&in2!='A'//���������㡣
		&&in2!='c'&&in2!='C'//��������㡣
		&&in2!='('&&in2!=')'//���������
		&&in2!='['&&in2!=']'//��С��������
		&&in2!='s'&&in2!='S'//�Ȳ�������ĩ�
		&&in2!='f'&&in2!='F'//쳲������������
		&&in2!='b'&&in2!='B'//�������������͡�
		&&in2!='e'&&in2!='E'//����������
		&&in2!='j'&&in2!='J'//����ͬ����
		&&in2!='n'&&in2!='N'//ţ�Բ����⡣
		&&in2!='h'&&in2!='H'//�����׻÷���
		&&in2!=':'&&in2!='~')//����ת��������������������ɡ�
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
		if(in2=='g'||in2=='G')//��ƽ����
		{
			cout << sqrt(in1) << endl;
			continue;
		}
		if(in2=='p'||in2=='P')//�ж�������
		{
			g=in1;
			if(prime(g)==0||in1!=g)
			{
				cout << in1 << "����������" << endl;
				continue;
			}
			cout << in1 << "��������" << endl;
			continue;
		}
		if(in2=='('||in2==')')//���������
		{
			for(short i=0;i<in1;i++)
			{
				cin >> k[0][i];
			}
			hs=dsgcd(in1);
			if(hs==0)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		if(in2=='['||in2==']')//��С��������
		{
			for(short i=0;i<in1;i++)
			{
				cin >> k[0][i];
			}
			hs=dslcm(in1);
			if(hs==0)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		if(in2=='f'||in2=='F')//쳲������������
		{
			hs=fbnqqx(in1);
			if(hs==0)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		if(in2=='b'||in2=='B')//�������������͡�
		{
			hs=yhsjzhqh(in1);
			if(hs==0)
			{
				cout << "��������������" << endl;
				continue;
			}	
			cout << hs << endl;
			continue;
		}
		if(in2=='h'||in2=='H')//�����׻÷���
		{
			huanfang(in1);
			continue;
		}
		if(in2==':')//����ת������������
		{
			cin >> s >> in3;
			if(in1!=(int)in1||in3!=(int)in3||in1<2||in3<2)
			{
				cout << "�������" << endl;
				continue;
			}
			if(s.find(".")==1)
			{
				cout << "�ݲ�֧��С����" << endl;
				continue;
			}
			jzzh(in1,s,in3);
			continue;
		}
		cin >> in3;
		if(in2=='+')//�ӷ���
		{
			cout << in1+in3 << endl;
			continue;
		}
		if(in2=='-')//������
		{
			cout << in1-in3 << endl;
			continue;
		}
		if(in2=='*')//�˷���
		{
			cout << in1*in3 << endl;
			continue;
		}
		if(in2=='/')//������
		{
			if(in3==0)
			{
				cout << "0������������" << endl;
				continue;
			}
			cout << in1/in3 << endl;
			continue;
		}
		if(in2=='a'||in2=='A')//���������㡣
		{
			hs=axy(in1,in3);
			if(hs==-1)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		if(in2=='c'||in2=='C')//��������㡣
		{
			hs=axy(in1,in3)/axy(in3,in3);
			if(axy(in1,in3)==-1||axy(in3,in3)==-1)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		if(in2=='e'||in2=='E')//����������
		{
			hs=yhsjqx(in1,in3);
			if(hs==0)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		cin >> in4;
		if(in2=='d'||in2=='D')//�˷���
		{
			if(in1!=(int)in1||in3!=(int)in3||in4!=(int)in4)
			{
				cout << "�������" << endl;
				continue;
			}
			if(in4==0)
			{
				cout << "0������������" << endl;
				continue;
			}
			cout << ksm(in1,in3,in4) << endl;
			continue;
		}
		if(in2=='s'||in2=='S')//�Ȳ�������ĩ�
		{
			if(in1!=(int)in1||in3!=(int)in3||in4!=(int)in4||in1<0||in3<0||in4<0)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << (in4-1)*(in3-in1)+in1 << endl;
			continue;
		}
		if(in2=='~')//��������ɡ�
		{
			if(in1!=(int)in1||in3!=(int)in3||in4!=(int)in4||in1<0||in3<0||in4<0||in1>in3)
			{
				cout << "�������" << endl;
				continue;
			}
			random(in1,in3,in4);
			continue;
		}
		cin >> in5;
		if(in2=='j'||in2=='J')//����ͬ����
		{
			if(in1!=(int)in1||in3!=(int)in3||in4!=(int)in4||in5!=(int)in5||in1<0||in3<0||in4<0||in5<0||in4>in5)
			{
				cout << "�������" << endl;
				continue;
			}
			g=(in3-in1*in4)/(in5-in4);
			cout << "����" << in1-g << "ֻ���ã�" << g << "ֻ��" << endl;
		}
	}
}

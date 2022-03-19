#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
double in1,in3,in4,in5,hs;//in1��in2��in3��in4��in5�������룬���ɵ��á��������Ϊ���������
long long e,f=2,g,k[10005][10005],l,x[42][42],j,bug;
char in2;
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
long long gcd(long long a,long long b)//��a��b�����������
{
	if(a%b==0)
	{
		return b;
	}
	return gcd(b,a%b);
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
long long yhsjzhqh(double a)//�������������ͣ�a��ʾ��͵��ǵ�a�С�
{
	if(a!=(int)a||a<=0)
	{
		return 0;
	}
	return pow(2,a-1); 
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
	        k[i][j]=x[i][j]=0;
	    }
	}
	l=0;
	e=a/2;
	k[l][e]=x[l][e]=1;
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
void random(long long a,long long b,long long c)//��������ɣ�����c��[a,b]��Χ�ڵ��������
{
	srand(time(0));
	for(long long i=0;i<c;i++)
	{
		cout << rand()%(b-a+1)+a << " ";
	}
	cout << endl;
}
long long jttl(double a,double b,double c,double d)//����ͬ����a��ʾͷ����b��ʾ������c��ʾ��������d��ʾ�ý�����
{
	if(a!=(int)a||b!=(int)b||c!=(int)c||d!=(int)d||a<0||b<0||c<0||d<0)
	{
		return -1;
	}
	return (b-a*c)/d-c;
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
	cout << "��ƽ��������������g����Enter����������" << endl;
	cout << "�ж����������ж�����p����Enter����������" << endl;
	cout << "���������㣺�½Ǳꡢa���ϽǱ꣬��Enter����������" << endl;
	cout << "��������㣺�½Ǳꡢc���ϽǱ꣬��Enter����������" << endl;
	cout << "������������ĸ�����С���ţ�Ӣ�ģ���n�����ĸ������������������������Enter����������" << endl;
	cout << "��С�����������ĸ����������ţ�Ӣ�ģ���n�����ĸ�����������С��������������Enter����������" << endl;
	cout << "쳲�������������ڼ����f����Enter����������" << endl;
	cout << "�������������ͣ�������b����Enter����������" << endl;
	cout << "�����������С�e���У���Enter����������" << endl;
	cout << "����ͬ����ͷ����j�����������������ý��������������ý���������Enter����������" << endl;
	cout << "�����׻÷���������h����Enter����������" << endl;
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
		&&in2!='f'&&in2!='F'//쳲������������
		&&in2!='b'&&in2!='B'//�������������͡�
		&&in2!='e'&&in2!='E'//����������
		&&in2!='j'&&in2!='J'//����ͬ����
		&&in2!='h'&&in2!='H'//�����׻÷���
		&&in2!='~')//��������ɡ�
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
		else if(in2=='p'||in2=='P')//�ж�������
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
		else if(in2=='('||in2==')')//���������
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
		else if(in2=='['||in2==']')//��С��������
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
		else if(in2=='f'||in2=='F')//쳲������������
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
		else if(in2=='b'||in2=='B')//�������������͡�
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
		else if(in2=='h'||in2=='H')//�����׻÷���
		{
			huanfang(in1);
			continue;
		}
		cin >> in3;
		if(in2=='+')//�ӷ���
		{
			cout << in1+in3 << endl;
			continue;
		}
		else if(in2=='-')//������
		{
			cout << in1-in3 << endl;
			continue;
		}
		else if(in2=='*')//�˷���
		{
			cout << in1*in3 << endl;
			continue;
		}
		else if(in2=='/')//������
		{
			if(in3==0)
			{
				cout << "0������������" << endl;
				continue;
			}
			cout << in1/in3 << endl;
			continue;
		}
		else if(in2=='d'||in2=='D')//�˷���
		{
			cout << pow(in1,in3) << endl;
			continue;
		}
		else if(in2=='a'||in2=='A')//���������㡣
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
		else if(in2=='c'||in2=='C')//��������㡣
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
		else if(in2=='e'||in2=='E')//����������
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
			g=jttl(in1,in3,in4,in5);
			if(g==-1)
			{
				cout << "�������" << endl;
				continue;
			}
			cout << "����" << in1-g << "ֻ���ã�" << g << "ֻ��" << endl;
		}
	}
}

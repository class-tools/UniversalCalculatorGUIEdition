#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
using namespace std;
default_random_engine dre;
mt19937 Random(time(0));
string s,ans[100];
double in1,in3,in4,in5,in6,hs,a[1754];//in1、in2、in3、in4、in5、in6、in7、in8用于输入，不可调用。其余变量为共享变量。
long long e,f,g,l,k[46][46],x[46][46];
bool h[14944];
char in2,in7,in8;
bool prime(long long p)//判断质数，p为被判断的数。
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
long long gcd(long long a,long long b)//求a和b的最大公因数。
{
	if(a%b==0)
	{
		return b;
	}
	return gcd(b,a%b);
}
long long dsgcd(double n)//最大公因数，n表示求最大公因数的数的个数。
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
	long long j;
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
long long dslcm(double n)//最小公倍数，n表示求最下公倍数的数的个数。
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
	long long j;
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
long long fbnqqx(double n)//斐波那契数列求项，n表示求的是第n项。
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
long long yhsjzhqh(double n)//杨辉三角整行求和，n表示求和的是第n行。
{
	if(n!=(int)n||n<1)
	{
		return 0;
	}
	return pow(2,n-1);
}
bool cmp(double a,double b)//降序排序。
{
	return a>b;
}
void paixu(long long n,char sj)//排序，对长度为n的序列a进行升序（<）/降序（>）排序。
{
	if(sj=='<')
	{
		sort(a,a+n);
	}
	if(sj=='>')
	{
		sort(a,a+n,cmp);
	}
	for(short i=0;i<n;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void huanfang(long long n)//奇数阶幻方，n表示幻方阶数。
{
	if(n%2==0)
	{
		cout << "只能生成正奇数阶！" << endl;
		return;
	}
	if(n<1)
	{
		cout << "请输入正整数！" << endl;
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
void jzzh(short m,string s,short n)//进制转换（整数），m表示被转换数的进制，s表示被转换的数，n表示转换后的进制。
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
	short j=0;
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
void string_splitter(string s,char fh)//字符串分割，s为字符串，fh为分割符。
{
	hs=s.size();
	e=g=l=0;
	for(long long i=0;i<hs;i++)
	{
		if(s[i]==fh)
		{
			ans[g]=s.substr(l,e);
			g++;
			l=i+1;
			e=0;
			continue;
		}
		e++;
		if(hs-i==1)
		{
			ans[g]=s.substr(l,e);
		}
	}
	for(short i=0;i<=g;i++)
	{
		cout << ans[i] << endl;
	}
}
void plapn(long long m,long long n)//质数表&质数个数统计，输出[m,n]中所有的质数及质数的个数。
{
	e=0;
	for(int i=0;i<14944;i++)
	{
		h[i]=0;
	}
	for(short i=m;i<=n;i++)
	{
		if(h[i]==1)
		{
			continue;
		}
		if(prime(i)==1)
		{
			a[e]=i;
			e++;
			for(short j=i;j<=n;j+=i)
			{ 
				h[j]=1;
			}
		}
	}
	for(short i=0;i<e;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << e << endl;
}
long long axy(long long a,long long b)//排列数计算，a为下角标，b为上角标。
{
	if(a<0||b<0)
	{
		return -1;
	}
	if(a<b)
	{
		return -2;
	}
	long long c=1;
	for(long long i=1;i<=b;i++)
	{
		c*=a;
		a--;
	}
	return c;
}
long long yhsjqx(double x,double y)//杨辉三角求项，x表示行，y表示列。
{
	if(x!=(int)x||y!=(int)y||x<1||y<1)
	{
		return 0;
	}
	if(x<y)
	{
		return -1;
	}
	if(y==1||y==x)
	{
		return 1;
	}
	return axy(x-1,y-1)/axy(y-1,y-1);
}
long long ksm(long long a,long long b,long long n)//乘方（快速幂），ksm(a,b,n)表示a的b次方模n。
{
	if(b==0)
	{
		return 1;
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
void random(double a,double b,bool x,long long n,long long m)//随机数生成，生成n个[a,b]范围内的随机数。
{
	if(x==1)
	{
		for(long long i=0;i<n;i++)
		{
			cout << (Random()%(int)(b-a+1))+a << " ";
		}
	}
	if(x==0)
	{
		uniform_real_distribution<double> urd(a,b);
		for(int i=0;i<n;i++)
		{
			cout << setprecision(m) << urd(dre) << " ";
		}
	}
	cout << endl;
}
int main()
{
	cout << "万能计算器" << endl;
	cout << "使用说明：" << endl;
	cout << "每种功能具体输入内容如下所示：" << endl;
	cout << "加法：输入加数、+和另一个加数，按Enter键输出结果。" << endl;
	cout << "减法：被减数、-和减数，按Enter键输出结果。" << endl;
	cout << "乘法：因数、*和另一个因数，按Enter键输出结果。" << endl;
	cout << "除法：被除数、/和除数，按Enter键输出结果。" << endl;
	cout << "模余：被模数、%和模数，按Enter键输出被模数除以模数的余数。" << endl;
	cout << "乘方：底数、^和指数，按Enter键输出结果。" << endl;
	cout << "开平方：被开方数和v，按Enter键输出结果。" << endl;
	cout << "快速幂（正整数）：底数、d、指数和需要取模的数（不需要取模就填1），按Enter键输出结果。" << endl;
	cout << "判断质数：被判断数和p，按Enter键输出结果。" << endl;
	cout << "质数表&质数个数统计：区间起点、t和区间终点，输出这个区间里的所有质数，并在下一行输出区间内质数的个数。" << endl;
	cout << "排列数计算：下角标、a和上角标，按Enter键输出结果。" << endl;
	cout << "组合数计算：下角标、c和上角标，按Enter键输出结果。" << endl;
	cout << "最大公因数：数的个数、小括号（英文）和n（数的个数）个求最大公因数的数，按Enter键输出结果。" << endl;
	cout << "最小公倍数：数的个数、中括号（英文）和n（数的个数）个求最小公倍数的数，按Enter键输出结果。" << endl;
	cout << "等差数列求末项：第一项、s、第二项和项数，按Enter键输出结果。" << endl;
	cout << "斐波那契数列求项：第几项和f，按Enter键输出结果。" << endl;
	cout << "杨辉三角整行求和：行数和b，按Enter键输出结果。" << endl;
	cout << "杨辉三角求项：行、e和列，按Enter键输出结果。" << endl;
	cout << "鸡兔同笼：头数、j、脚数、鸡脚数和兔脚数（鸡脚数≤兔脚数），按Enter键输出结果。" << endl;
	cout << "排序：数的个数、升序（<）或降序（>）、被排序的数列，按Enter键输出结果。" << endl;
	cout << "奇数阶幻方：阶数和h，按Enter键输出结果。" << endl;
	cout << "进制转换（整数）：被转换数的进制（16进制及以内）、:、被转换数、转换后的进制（16进制及以内），按Enter键输出结果。" << endl;
	cout << "随机数生成：随机数范围（一个数~另一个数，前者小于等于后者，范围包括那两个数）、生成整数（1）或小数（0）、生成的个数，如果要生成小数请再输入需要保留的小数位数，按Enter键输出结果。" << endl;
	cout << "字符串分割：字符串个数、|、每个字符串及其分割符（字符串合分割符必须占用独立行），按Enter键输出结果。" << endl;
	cout << "注意事项：请尽量不要严重错误的数据（例如一串乱码），以免影响您的体验。建议在英文输入法下使用。如需运行大数据请自行更改代码相关变量。" << endl;
	while(1)
	{
		fflush(stdin);
		cin >> in1 >> in2;
		if (in2!='+'&&in2!='-'//加法、减法。
			&&in2!='*'&&in2!='/'//乘法、除法。
			&&in2!='%'&&in2!='^'//模余、乘方。
			&&in2!='v'&&in2!='V'//开平方。
			&&in2!='d'&&in2!='D'//快速幂。
			&&in2!='p'&&in2!='P'//判断质数。
			&&in2!='t'&&in2!='T'//质数表&质数个数统计。
			&&in2!='a'&&in2!='A'//排列数计算。
			&&in2!='c'&&in2!='C'//组合数计算。
			&&in2!='('&&in2!=')'//最大公因数。
			&&in2!='['&&in2!=']'//最小公倍数。
			&&in2!='s'&&in2!='S'//等差数列求末项。
			&&in2!='f'&&in2!='F'//斐波那契数列求项。
			&&in2!='b'&&in2!='B'//杨辉三角整行求和。
			&&in2!='e'&&in2!='E'//杨辉三角求项。
			&&in2!='j'&&in2!='J'//鸡兔同笼。
			&&in2!='<'&&in2!='>'//排序。
			&&in2!='h'&&in2!='H'//奇数阶幻方。
			&&in2!=':'&&in2!='~'//进制转换（整数）、随机数生成。
			&&in2!='|')//字符串分割。
		{
			cout << "无此符号！" << endl;
			continue;
		}
		if(in2=='v'||in2=='V')//开平方。
		{
			if(in1<0)
			{
				cout << "负数没有平方根！" << endl;
				continue;
			}
			cout << sqrt(in1) << endl;
			continue;
		}
		if(in2=='p'||in2=='P')//判断质数。
		{
			if(prime(g)==0||in1!=(int)in1)
			{
				cout << in1 << "不是质数。" << endl;
				continue;
			}
			cout << in1 << "是质数。" << endl;
			continue;
		}
		if(in2=='('||in2==')')//最大公因数。
		{
			for(short i=0;i<in1;i++)
			{
				cin >> k[0][i];
			}
			hs=dsgcd(in1);
			if(hs==0)
			{
				cout << "请输入正整数！" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		if(in2=='['||in2==']')//最小公倍数。
		{
			for(short i=0;i<in1;i++)
			{
				cin >> k[0][i];
			}
			hs=dslcm(in1);
			if(hs==0)
			{
				cout << "请输入正整数！" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		if(in2=='f'||in2=='F')//斐波那契数列求项。
		{
			hs=fbnqqx(in1);
			if(hs==0)
			{
				cout << "请输入正整数！" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		if(in2=='b'||in2=='B')//杨辉三角整行求和。
		{
			hs=yhsjzhqh(in1);
			if(hs==0)
			{
				cout << "请输入正整数！" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		if(in2=='<'||in2=='>')//排序。
		{
			if(in1!=(int)in1||in1<0)
			{
				cout << "请输入正整数！" << endl;
				continue;
			}
			for(short i=0;i<in1;i++)
			{
				cin >> a[i];
			}
			paixu(in1,in2);
			continue;
		}
		if(in2=='h'||in2=='H')//奇数阶幻方。
		{
			if(in1!=(int)in1)
			{
				cout << "请输入正整数！" << endl;
				continue;
			}
			huanfang(in1);
			continue;
		}
		if(in2==':')//进制转换（整数）。
		{
			cin >> s >> in3;
			if(in1!=(int)in1||in3!=(int)in3||in1<2||in3<2)
			{
				cout << "（进制数）请输入不小于2的正整数！" << endl;
				continue;
			}
			if(s.find(".")==1)
			{
				cout << "暂不支持小数！" << endl;
				continue;
			}
			jzzh(in1,s,in3);
			continue;
		}
		if(in2=='|')//字符串分割。
		{
			if(in1!=(int)in1)
			{
				cout << "请输入正整数！" << endl;
				continue;
			}
			for(long long i=0;i<in1;i++)
			{
				fflush(stdin);
				getline(cin,s);
				in7=getchar();
				string_splitter(s,in7);
			}
			continue;
		}
		cin >> in3;
		if(in2=='+')//加法。
		{
			cout << in1+in3 << endl;
			continue;
		}
		if(in2=='-')//减法。
		{
			cout << in1-in3 << endl;
			continue;
		}
		if(in2=='*')//乘法。
		{
			cout << in1*in3 << endl;
			continue;
		}
		if(in2=='/')//除法。
		{
			if(in3==0)
			{
				cout << "0不能做除数！" << endl;
				continue;
			}
			cout << in1/in3 << endl;
			continue;
		}
		if(in2=='%')//模余。
		{
			if(in1!=(int)in1||in3!=(int)in3)
			{
				cout << "请输入整数！" << endl;
				continue;
			}
			if(in3==0)
			{
				cout << "0不能做模数！" << endl;
				continue;
			}
			cout << (int)in1%(int)in3 << endl;
			continue;
		}
		if(in2=='^')//乘方。
		{
			cout << pow(in1,in3) << endl;
			continue;
		}
		if(in2=='t'||in2=='T')//质数表&质数个数统计。
		{
			if(in1>in3)
			{
				cout << "区间起点不能大于区间终点！" << endl;
				continue;
			}
			if(in3<=0)
			{
				cout << "请输入正数区间！" << endl;
				continue;
			}
			if(in3<2)
			{
				cout << "该区间没有质数。" << endl;
				continue;
			}
			if(in1<2)
			{
				in1=2;
			}
			if(in3!=(int)in3)
			{
				in3=floor(in3);
			}
			plapn(in1,in3);
			continue;
		}
		if(in2=='a'||in2=='A')//排列数计算。
		{
			hs=axy(in1,in3);
			if(hs==-1)
			{
				cout << "请输入正整数！" << endl;
				continue;
			}
			if(hs==-2)
			{
				cout << "下角标不能小于上角标！" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		if(in2=='c'||in2=='C')//组合数计算。
		{
			hs=axy(in1,in3);
			e=axy(in3,in3);
			if(hs==-1||e==-1)
			{
				cout << "请输入正整数！" << endl;
				continue;
			}
			if(hs==-2)
			{
				cout << "下角标不能小于上角标！" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		if(in2=='e'||in2=='E')//杨辉三角求项。
		{
			hs=yhsjqx(in1,in3);
			if(hs==0)
			{
				cout << "请输入正整数！" << endl;
				continue;
			}
			if(hs==-1)
			{
				cout << "位置越界！" << endl;
				continue;
			}
			cout << hs << endl;
			continue;
		}
		cin >> in4;
		if(in2=='d'||in2=='D')//快速幂。
		{
			if(in1!=(int)in1||in3!=(int)in3||in4!=(int)in4||in1<0||in3<0||in4<0)
			{
				cout << "请输入正整数！" << endl;
				continue;
			}
			if(in4==0)
			{
				cout << "0不能做模数！" << endl;
				continue;
			}
			cout << ksm(in1,in3,in4) << endl;
			continue;
		}
		if(in2=='s'||in2=='S')//等差数列求末项。
		{
			if(in1<0||in3<0||in4<0)
			{
				cout << "请输入正数！" << endl;
				continue;
			}
			cout << (in4-1)*(in3-in1)+in1 << endl;
			continue;
		}
		cin >> in5;
		if(in2=='j'||in2=='J')//鸡兔同笼。
		{
			if(in1!=(int)in1||in3!=(int)in3||in4!=(int)in4||in5!=(int)in5||in1<0||in3<0||in4<0||in5<0)
			{
				cout << "请输入正整数！" << endl;
				continue;
			}
			if(in4>in5)
			{
				cout << "鸡脚数不能大于兔脚数！" << endl;
				continue;
			}
			g=(in3-in1*in4)/(in5-in4);
			e=in1-g;
			if(e<0||g<0)
			{
				cout << "数据不符合实际！" << endl;
				continue;
			}
			cout << "鸡：" << in1-g << "只，兔：" << g << "只。" << endl;
		}
		if(in2=='~')//随机数生成。
		{
			if(in4!=(int)in4||in4<0)
			{
				cout << "个数请输入非负整数！" << endl;
				continue;
			}
			if(in1>in3)
			{
				cout << "范围输入错误！" << endl;
				continue;
			}
			if(in4!=0&&in4!=1)
			{
				cout << "仅支持整数和小数！" << endl;
				continue;
			}
			if(in4==0)
			{
				cin >> in6;
			}
			random(in1,in3,in4,in5,in6);
			continue;
		}
	}
}
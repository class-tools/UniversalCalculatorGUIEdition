#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
double b,c,h,m,hs;//b、c、d、h、m用于输入，不可调用。
long long e,f=2,g,k[10005][10005],l,x[42][42],j,bug;
char d;
bool prime(long long a)//判断质数，a为被判断的数。
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
long long axy(long long a,long long b)//排列数计算，a为下角标，b为上角标。
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
long long yhsjzhqh(double a)//杨辉三角整行求和，a表示求和的是第几行。
{
	if(a!=(int)a||a<=0)
	{
		return 0;
	}
	return pow(2,a-1);
}
long long yhsjqx(double a,double b)//杨辉三角求项，a表示行，b表示列。
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
void huanfang(long long a)//奇数阶幻方，a表示幻方阶数。
{
	if(a%2==0)
	{
		cout << "只能生成正奇数阶！" << endl;
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
long long gcd(long long a,long long b)//求a和b的最大公因数。
{
	if(a%b==0)
	{
		return b;
	}
	return gcd(b,a%b);
}
long long jttl(double a,double b,double c,double d)//鸡兔同笼，a表示头数，b表示脚数，c表示鸡脚数，d表示兔脚数。
{
	if(a!=(int)a||b!=(int)b||c!=(int)c||d!=(int)d||a<0||b<0||c<0||d<0)
	{
		return -1;
	}
	return (b-a*c)/d-c;
}
long long dsgcd(double a)//最大公因数，a表示求最大公因数的数的个数。
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
long long dslcm(double a)//最小公倍数，a表示求最下公倍数的数的个数。
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
void random(long long a,long long b,long long c)//随机数生成，生成c个[a,b]范围内的随机数。
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
	cout << "万能计算器" << endl;
	cout << "使用说明：" << endl;
	cout << "每种功能具体输入内容如下所示：" << endl;
	cout << "加法：输入加数、+和另一个加数，按Enter键输出结果。" << endl;
	cout << "减法：被减数、-和减数，，按Enter键输出结果。" << endl;
	cout << "乘法：因数、*和另一个因数，按Enter键输出结果。" << endl;
	cout << "除法：被除数、/和除数，按Enter键输出结果。" << endl;
	cout << "乘方：底数、d和指数，按Enter键输出结果。" << endl;
	cout << "杨辉三角求项：行、e和列，按Enter键输出结果。" << endl;
	cout << "排列数计算：下角标、a和上角标，按Enter键输出结果。" << endl;
	cout << "组合数计算：下角标、c和上角标，按Enter键输出结果。" << endl;
	cout << "开平方：被开方数和g，按Enter键输出结果。" << endl;
	cout << "判断质数：被判断数和p，按Enter键输出结果。" << endl;
	cout << "杨辉三角整行求和：行数和b，按Enter键输出结果。" << endl;
	cout << "奇数阶幻方：阶数和h，按Enter键输出结果。" << endl;
	cout << "最大公因数：数的个数、小括号（英文）和n（数的个数）个求最大公因数的数，按Enter键输出结果。" << endl;
	cout << "最小公倍数：数的个数、中括号（英文）和n（数的个数）个求最小公倍数的数，按Enter键输出结果。" << endl;
	cout << "鸡兔同笼：头数、f、脚数、鸡脚数和兔脚数（鸡脚数≤兔脚数），按Enter键输出结果。" << endl;
	cout << "随机数生成：随机数范围（一个数~另一个数，前者小于等于后者，范围包括那两个数）和生成的个数。" << endl;
	cout << "注意事项：每输入完一个数就输入一个空格，输入完符号后换一行再输入。请尽量不要输出错误的符号，以免影响您的体验。" << endl;
	cout << "建议在英文输入法下使用。" << endl;
	while(1)
	{
		cin >> b >> d;
		if(d!='g'&&d!='G'//开平方。
		&&d!='p'&&d!='P'//判断质数。
		&&d!='b'&&d!='B'//杨辉三角整行求和。
		&&d!='h'&&d!='H'//奇数阶幻方。
		&&d!='('&&d!=')'//最大公因数。
		&&d!='['&&d!=']'//最小公倍数。
		&&d!='+'&&d!='-'//加法、减法。
		&&d!='*'&&d!='/'//乘法、除法。
		&&d!='d'&&d!='D'//乘方。
		&&d!='e'&&d!='E'//杨辉三角求项。
		&&d!='f'&&d!='F'//鸡兔同笼。
		&&d!='a'&&d!='A'//排列数计算。
		&&d!='c'&&d!='C'//组合数计算。
		&&d!='~')//随机数生成。
		{
			if(bug>0)
			{
				cout << "发现bug，自动结束程序。" << endl;
				return 0;
			}
			cout << "无此符号！" << endl;
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
				cout << b << "不是质数。" << endl;
				continue;
			}
			cout << b << "是质数。" << endl;
			continue;
		}
		else if(d=='b'||d=='B')
		{
			hs=yhsjzhqh(b);
			if(hs==0)
			{
				cout << "请输入正整数！" << endl;
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
				cout << "输入错误！" << endl;
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
				cout << "输入错误！" << endl;
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
				cout << "0不能做除数！" << endl;
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
				cout << "输入错误！" << endl;
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
				cout << "输入错误！" << endl;
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
				cout << "输入错误！" << endl;
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
				cout << "输入错误！" << endl;
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
				cout << "输入错误！" << endl;
				continue;
			}
			cout << "鸡：" << b-g << "只，兔：" << g << "只。" << endl;
		}

	}
}

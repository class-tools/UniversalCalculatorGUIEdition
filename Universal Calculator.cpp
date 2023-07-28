#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
using namespace std;
default_random_engine dre;
mt19937 Random(time(0));
string ans[100],in1,in8;
double in2,in3,in4,in5,in6,hs,k[46][1754];//in1、in2、in3、in4、in5、in6、in7、in8用于输入，不可调用。其余变量为共享变量。
long long e,f,g,l,x[46][46];
bool h[14944];
char in7;
long long ksm(long long a,long long b,long long n)//快速幂（非负整数）（取模），ksm(a,b,n)表示a的b次方模n。
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
long long nmksm(long long a,long long b)//快速幂（非负整数）（不取模），nmksm(a,b)表示a的b次方。
{
	if(b==0)
	{
		return 1;
	}
	if(b==1)
	{
		return a;
	}
	e=nmksm(a,b/2);
	if(b%2==0)
	{
		return e*e;
	}
	else
	{
		return e*e*a;
	}
}
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
			k[0][e]=i;
			e++;
			for(short j=i;j<=n;j+=i)
			{ 
				h[j]=1;
			}
		}
	}
	for(short i=0;i<e;i++)
	{
		cout << k[0][i] << " ";
	}
	cout << endl << e << endl;
}
long long axy(long long a,long long b)//排列数计算，a为下角标，b为上角标。
{
	long long c=1;
	for(long long i=1;i<=b;i++)
	{
		c*=a;
		a--;
	}
	return c;
}
long long gcd(long long a,long long b)//求a和b的最大公因数。
{
	if(a%b==0)
	{
		return b;
	}
	return gcd(b,a%b);
}
long long dsgcd(long long n)//最大公因数，n表示求最大公因数的数的个数。
{
	for(short i=0;i<n;i++)
	{
		if(k[0][i]!=(long long)k[0][i]||k[0][i]<1)
		{
			return 0;
		}
	}
	long long j=gcd(k[0][0],k[0][1]);
	for(short i=1;i<n;i++)
	{
		j=gcd(j,k[0][i]);
	}
	return j;
}
long long dslcm(long long n)//最小公倍数，n表示求最下公倍数的数的个数。
{
	for(short i=0;i<n;i++)
	{
		if(k[0][i]!=(long long)k[0][i]||k[0][i]<1)
		{
			return 0;
		}
	}
	long long j=k[0][0]/gcd(k[0][0],k[0][1])*k[0][1];;
	for(short i=1;i<n;i++)
	{
		if(i==1)
		{
			continue;
		}
		j=j/gcd(j,k[0][i])*k[0][i];
	}
	return j;
}
long long fbnqqx(long long n)//斐波那契数列求项，n表示求的是第n项。
{
	k[0][0]=k[0][1]=1;
	for(long long i=2;i<n;i++)
	{
		k[0][i%3]=k[0][(i-1)%3]+k[0][(i-2)%3];
	}
	return k[0][(int)(n-1)%3];
}
bool cmp(double a,double b)//降序排序。
{
	return a>b;
}
void paixu(long long n,string sj)//排序，对长度为n的序列a进行升序（<）/降序（>）排序。
{
	if(sj=="1")
	{
		sort(k[0],k[0]+n);
	}
	if(sj=="2")
	{
		sort(k[0],k[0]+n,cmp);
	}
	for(short i=0;i<n;i++)
	{
		cout << k[0][i] << " ";
	}
	cout << endl;
}
void huanfang(long long n)//奇数阶幻方，n表示幻方阶数。
{
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
	e=f=0;
	for(short i=0;i<46;i++)
	{
		k[0][i]=x[0][i]=0;
	}
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
void random(double a,double b,bool x,long long n,long long m)//随机数生成，生成n个[a,b]范围内的随机数。
{
	if(x==1)
	{
		for(long long i=0;i<n;i++)
		{
			cout << (Random()%(long long)(b-a+1))+a << " ";
		}
	}
	if(x==0)
	{
		uniform_real_distribution <double> urd(a,b);
		for(int i=0;i<n;i++)
		{
			cout << setprecision(m) << urd(dre) << " ";
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
bool sdxh(short il,short ir,short jl,short jr,short x,short y)
{
	for(short i=il;i<=ir;i++)
	{
		for(short j=jl;j<=jr;j++)
		{
			if(k[i][j]==k[x][y]&&(i!=x||j!=y))
			{
				return 0;
			}
		}
	}
	return 1;
}
bool sdcheck(short x,short y)
{
	for(short i=0;i<9;i++)
	{
		if((k[x][i]==k[x][y]&&i!=y)||(k[i][y]==k[x][y]&&i!=x))
		{
			return 0;
		}
	}
	if(x>=0&&x<=2)
	{
		if(y>=0&&y<=2)
		{
			return sdxh(0,2,0,2,x,y);
		}
		if(y>=3&&y<=5)
		{
			return sdxh(0,2,3,5,x,y);
		}
		if(y>=6&&y<=8)
		{
			return sdxh(0,2,6,8,x,y);
		}
	}
	if(x>=3&&x<=5)
	{
		if(y>=0&&y<=2)
		{
			return sdxh(3,5,0,2,x,y);
		}
		if(y>=3&&y<=5)
		{
			return sdxh(3,5,3,5,x,y);
		}
		if(y>=6&&y<=8)
		{
			return sdxh(3,5,6,8,x,y);
		}
	}
	if(x>=6&&x<=8)
	{
		if(y>=0&&y<=2)
		{
			return sdxh(6,8,0,2,x,y);
		}
		if(y>=3&&y<=5)
		{
			return sdxh(6,8,3,5,x,y);
		}
		if(y>=6&&y<=8)
		{
			return sdxh(6,8,6,8,x,y);
		}
	}
	return 0;
}
void shudu(short x,short y)
{
	if(x>=9||y>=9)
	{
		cout << endl;
		for(short i=0;i<9;i++)
		{
			for(short j=0;j<9;j++)
			{
				cout << k[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	if(k[x][y]==0)
	{
		for(short i=1;i<=9;i++)
		{
			k[x][y]=i;
			if(sdcheck(x,y)==1)
			{
				if(y==8)
				{
					shudu(x+1,0);
				}
				else
				{
					shudu(x,y+1);
				}
			}
			k[x][y]=0;
		}
	}
	if(k[x][y]!=0)
	{
		if(y==8)
		{
			shudu(x+1,0);
		}
		else
		{
			shudu(x,y+1);
		}
	}
}
int main()
{
	cout << "万能计算器" << endl;
	cout << "功能列表（输入对应编号使用对应功能）：" << endl;
	cout << "1、通用计算（加、减、乘、除、乘方、模余）。" << endl;
	cout << "2、开平方。" << endl;
	cout << "3、快速幂（非负整数）。" << endl;
	cout << "4、判断质数。" << endl;
	cout << "5、质数表&质数个数统计。" << endl;
	cout << "6、排列数计算。" << endl;
	cout << "7、组合数计算。" << endl;
	cout << "8、最大公因数。" << endl;
	cout << "9、最小公倍数。" << endl;
	cout << "10、等差数列求末项。" << endl;
	cout << "11、斐波那契数列求项。" << endl;
	cout << "12、杨辉三角整行求和。" << endl;
	cout << "13、杨辉三角求项。" << endl;
	cout << "14、鸡兔同笼。" << endl;
	cout << "15、排序。" << endl;
	cout << "16、奇数阶幻方。" << endl;
	cout << "17、进制转换（整数）。" << endl;
	cout << "18、随机数生成。" << endl;
	cout << "19、字符串分割。" << endl;
	cout << "20、九宫数独。" << endl;
	cout << "注意事项：请尽量不要严重错误的数据（例如一串乱码），以免影响您的体验。建议在英文输入法下使用。如需运行大数据请自行更改代码相关变量。" << endl;
	while(1)
	{
		fflush(stdin);
		cin >> in1;
		if(in1!="1"&&in1!="2"//通用计算（加、减、乘、除、乘方、模余）、开平方。
		&&in1!="3"&&in1!="4"//快速幂（非负整数）、判断质数。
		&&in1!="5"&&in1!="6"//质数表&质数个数统计、排列数计算。
		&&in1!="7"&&in1!="8"//组合数计算、最大公因数。
		&&in1!="9"&&in1!="10"//最小公倍数、等差数列求末项。
		&&in1!="11"&&in1!="12"//斐波那契数列求项、杨辉三角整行求和。
		&&in1!="13"&&in1!="14"//杨辉三角求项、鸡兔同笼。
		&&in1!="15"&&in1!="16"//排序、奇数阶幻方。
		&&in1!="17"&&in1!="18"//进制转换（整数）、随机数生成。
		&&in1!="19"&&in1!="20")//字符串分割、九宫数独。
		{
			cout << "无效输入！" << endl;
			continue;
		}
		if(in1=="1")//通用计算（加、减、乘、除、乘方、模余）。
		{
			cout << "通用计算（加、减、乘、除、乘方、模余）：输入由“运算数1 运算符（+、-、*、/、^、%） 运算数2”组成的算式（如1+1），按Enter键输出结果（保留15位有效数字），输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				cin >> in7 >> in3;
				if(in7!='+'&&in7!='-'&&in7!='*'&&in7!='/'&&in7!='^'&&in7!='%')
				{
					cout << "无效输入！" << endl;
					continue;
				}
				if(in7=='+')//加法。
				{
					cout << setprecision(15) << in2+in3 << endl;
					continue;
				}
				if(in7=='-')//减法。
				{
					cout << setprecision(15) << in2-in3 << endl;
					continue;
				}
				if(in7=='*')//乘法。
				{
					cout << setprecision(15) << in2*in3 << endl;
					continue;
				}
				if(in7=='/')//除法。
				{
					if(in3==0)
					{
						cout << "0不能做除数！" << endl;
						continue;
					}
					cout << setprecision(15) << in2/in3 << endl;
					continue;
				}
				if(in7=='^')//乘方。
				{
					cout << setprecision(15) << pow(in2,in3) << endl;
					continue;
				}
				if(in7=='%')//模余。
				{
					if(in2!=(long long)in2||in3!=(long long)in3)
					{
						cout << "请输入整数！" << endl;
						continue;
					}
					if(in3==0)
					{
						cout << "0不能做模数！" << endl;
						continue;
					}
					cout << setprecision(15) << (long long)in2%(long long)in3 << endl;
					continue;
				}
			}
		}
		if(in1=="2")//开平方。
		{
			cout << "开平方：输入被开方数，按Enter键输出结果（保留15位有效数字），输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				if(in2<0)
				{
					cout << "负数没有平方根！" << endl;
					continue;
				}
				cout << setprecision(15) << sqrt(in2) << endl;
				continue;
			}
		}
		if(in1=="3")//快速幂（非负整数）。
		{
			cout << "快速幂（非负整数）：输入底数、指数和需要取模的数（不需要取模就填0），按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				cin >> in3 >> in4;
				if(in2!=(long long)in2||in3!=(long long)in3||in4!=(long long)in4||in2<0||in3<0||in4<0)
				{
					cout << "请输入非负整数！" << endl;
					continue;
				}
				if(in4==0)
				{
					cout << nmksm(in2,in3) << endl;
					continue;
				}
				cout << ksm(in2,in3,in4) << endl;
				continue;
			}
		}
		if(in1=="4")//判断质数。
		{
			cout << "判断质数：输入被判断数，按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "-1不是质数。" << endl;
					cout << "已退出。" << endl;
					break;
				}
				if(prime(in2)==0||in2!=(long long)in2)
				{
					cout << in2 << "不是质数。" << endl;
					continue;
				}
				cout << in2 << "是质数。" << endl;
			}
		}
		if(in1=="5")//质数表&质数个数统计。
		{
			cout << "质数表&质数个数统计：输入区间起点和区间终点，按Enter键输出这个区间内的所有质数，并在下一行输出区间内质数的个数，输入一组错误数据（区间起点大于区间终点）退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2 >> in3;
				if(in2>in3)
				{
					cout << "已退出。" << endl;
					break;
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
				if(in2<2)
				{
					in2=2;
				}
				plapn(in2,in3);
			}
		}
		if(in1=="6")//排列数计算。
		{
			cout << "排列数计算：下角标和上角标，按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				cin >> in3;
				if(in2<0||in3<0||in2!=(long long)in2||in3!=(long long)in3)
				{
					cout << "请输入正整数！" << endl;
					continue;
				}
				if(in2<in3)
				{
					cout << "下角标不能小于上角标！" << endl;
					continue;
				}
				cout << axy(in2,in3) << endl;
			}
		}
		if(in1=="7")//组合数计算。
		{
			cout << "组合数计算：下角标和上角标，按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				cin >> in3;
				if(in2<0||in3<0||in2!=(long long)in2||in3!=(long long)in3)
				{
					cout << "请输入正整数！" << endl;
					continue;
				}
				if(in2<in3)
				{
					cout << "下角标不能小于上角标！" << endl;
					continue;
				}
				cout << axy(in2,in3)/axy(in3,in3) << endl;
			}
		}
		if(in1=="8")//最大公因数。
		{
			cout << "最大公因数：数的个数和求最大公因数的数，按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				if(in2<2)
				{
					cout << "至少2个数才能求最大公因数！" << endl;
					continue;
				}
				if(in2!=(long long)in2)
				{
					cout << "个数必须是整数！" << endl;
					continue;
				}
				for(short i=0;i<in2;i++)
				{
					cin >> k[0][i];
				}
				hs=dsgcd(in2);
				if(hs==0)
				{
					cout << "请输入正整数！" << endl;
					continue;
				}
				cout << hs << endl;
			}
		}
		if(in1=="9")//最小公倍数。
		{
			cout << "最小公倍数：数的个数和求最小公倍数的数，按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				if(in2<2)
				{
					cout << "至少2个数才能求最小公倍数！" << endl;
					continue;
				}
				if(in2!=(long long)in2)
				{
					cout << "个数必须是整数！" << endl;
					continue;
				}
				for(short i=0;i<in2;i++)
				{
					cin >> k[0][i];
				}
				hs=dslcm(in2);
				if(hs==0)
				{
					cout << "请输入正整数！" << endl;
					continue;
				}
				cout << hs << endl;
			}
		}
		if(in1=="10")//等差数列求末项。
		{
			cout << "等差数列求末项：任意相邻两项和项数，按Enter键输出结果，输入一组错误数据（项数非正整数）退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2 >> in3 >> in4;
				if(in4<=0||in4!=(long long)in4)
				{
					cout << "已退出。" << endl;
					break;
				}
				cout << (in4-1)*(in3-in2)+in2 << endl;
			}
		}
		if(in1=="11")//斐波那契数列求项。
		{
			cout << "斐波那契数列求项：输入所求的项（第几项），按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				if(in2!=(long long)in2||in2<1)
				{
					cout << "请输入正整数！" << endl;
					continue;
				}
				cout << fbnqqx(in2) << endl;
			}
		}
		if(in1=="12")//杨辉三角整行求和。
		{
			cout << "杨辉三角整行求和：输入所求的行（第几行），按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				if(in2!=(long long)in2||in2<1)
				{
					cout << "请输入正整数！" << endl;
					continue;
				}
				cout << pow(2,in2-1) << endl;
			}
		}
		if(in1=="13")//杨辉三角求项。
		{
			cout << "杨辉三角求项：输入被求项的行和列，按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				cin >> in3;
				if(in2!=(long long)in2||in3!=(long long)in3||in2<1||in3<1)
				{
					cout << "请输入正整数！" << endl;
					continue;
				}
				if(in2<in3)
				{
					cout << "位置越界！" << endl;
					continue;
				}
				cout << axy(in2-1,in3-1)/axy(in3-1,in3-1) << endl;
			}
		}
		if(in1=="14")//鸡兔同笼。
		{
			cout << "鸡兔同笼：输入头数、脚数、鸡脚数和兔脚数（鸡脚数≤兔脚数），按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				cin >> in3 >> in4 >> in5;
				if(in2!=(long long)in2||in3!=(long long)in3||in4!=(long long)in4||in5!=(long long)in5||in2<0||in3<0||in4<0||in5<0)
				{
					cout << "请输入正整数！" << endl;
					continue;
				}
				if(in4>in5)
				{
					cout << "鸡脚数不能大于兔脚数！" << endl;
					continue;
				}
				g=(in3-in2*in4)/(in5-in4);
				e=in2-g;
				if(e<0||g<0)
				{
					cout << "数据不符合实际！" << endl;
					continue;
				}
				cout << "鸡：" << in2-g << "只，兔：" << g << "只。" << endl;
			}
		}
		if(in1=="15")//排序。
		{
			cout << "排序：数的个数、升序（1）或降序（2）、被排序的数列，按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				if(in2!=(long long)in2||in2<1)
				{
					cout << "请输入正整数！" << endl;
					continue;
				}
				cin >> in8;
				for(short i=0;i<in2;i++)
				{
					cin >> k[0][i];
				}
				paixu(in2,in8);
			}
		}
		if(in1=="16")//奇数阶幻方。
		{
			cout << "奇数阶幻方：输入阶数，按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				if(in2!=(long long)in2||in2<1||(long long)in2%2==0)
				{
					cout << "请输入正奇数！" << endl;
					continue;
				}
				huanfang(in2);
			}
		}
		if(in1=="17")//进制转换（整数）。
		{
			cout << "进制转换（整数）：输入被转换数的进制（16进制及以内）、被转换数和转换后的进制（16进制及以内），按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				cin >> in8 >> in3;
				if(in2!=(long long)in2||in3!=(long long)in3||in2<2||in3<2||in2>16||in3>16)
				{
					cout << "请输入不小于2且不大于16的进制数（正整数）！" << endl;
					continue;
				}
				if(in8.find(".")==1)
				{
					cout << "暂不支持小数。" << endl;
					continue;
				}
				jzzh(in2,in8,in3);
			}
		}
		if(in1=="18")//随机数生成。
		{
			cout << "随机数生成：输入随机数范围的起点、终点、生成整数（1）或小数（0）和生成的个数，如果要生成小数请再输入需要保留的小数位数，按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				cin >> in3 >> in4 >> in5;
				if(in4!=(long long)in4||in4<=0)
				{
					cout << "个数请输入正整数！" << endl;
					continue;
				}
				if(in2>in3)
				{
					cout << "范围输入错误！" << endl;
					continue;
				}
				if(in4!=0&&in4!=1)
				{
					cout << "数据类型输入错误！" << endl;
					continue;
				}
				if(in4==0)
				{
					cin >> in6;
				}
				random(in2,in3,in4,in5,in6);
			}
		}
		if(in1=="19")//字符串分割。
		{
			cout << "字符串分割：输入字符串个数和每个字符串及其分割符（字符串分割符必须占用独立行），按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> in2;
				if(in2==-1)
				{
					cout << "已退出。" << endl;
					break;
				}
				if(in2!=(long long)in2)
				{
					cout << "请输入正整数！" << endl;
					continue;
				}
				for(long long i=0;i<in2;i++)
				{
					fflush(stdin);
					getchar();
					getline(cin,in8);
					in7=getchar();
					string_splitter(in8,in7);
				}
			}
		}
		if(in1=="20")//九宫数独。
		{
			cout << "九宫数独：输入数独（数字用空格隔开，空位用0表示，每9个数字一行），按Enter键输出结果，输入-1退出。" << endl;
			while(1)
			{
				fflush(stdin);
				cin >> k[0][0];
				if(k[0][0]==-1)
				{
					cout << "已退出。" << endl;
					continue;
				}
				for(short i=1;i<9;i++)
				{
					cin >> k[0][i];
				}
				for(short i=1;i<9;i++)
				{
					for(short j=0;j<9;j++)
					{
						cin >> k[i][j];
					}
				}
				for(short i=0;i<9;i++)
				{
					for(short j=0;j<9;j++)
					{
						if(k[i][j]<0||k[i][j]>9||k[i][j]!=(long long)k[i][j])
						{
							cout << "输入错误！" << endl;
							continue;
						}
					}
				}
				shudu(0,0);
			}
		}
	}
}
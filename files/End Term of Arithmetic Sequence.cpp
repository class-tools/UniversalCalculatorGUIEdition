#include <iostream>
using namespace std;
int main()
{
	long long a,b,c;
	cout << "等差数列末项计算器" << endl;
	cout << "使用说明：输入等差数列的第一、第二项和末项是第几项，按Enter键即可求等差数列的末项。" << endl;
	b:cin >> a >> b >> c;
	cout << (c-1)*(b-a)+a << endl;
	goto b;
	return 0;
}

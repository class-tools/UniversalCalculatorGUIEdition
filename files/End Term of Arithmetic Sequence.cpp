#include <iostream>
using namespace std;
int main()
{
	long long a,b,c;
	cout << "�Ȳ�����ĩ�������" << endl;
	cout << "ʹ��˵��������Ȳ����еĵ�һ���ڶ����ĩ���ǵڼ����Enter��������Ȳ����е�ĩ�" << endl;
	b:cin >> a >> b >> c;
	cout << (c-1)*(b-a)+a << endl;
	goto b;
	return 0;
}

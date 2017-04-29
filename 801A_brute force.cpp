#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>

typedef long long ll;
#define MAXN 100000
using namespace std;

string k;
int cnt()
{
	int rst = 0;
	for (int i = 0; i<k.size() - 1; i++)
	{
		if (k.substr(i, 2) == "VK")
			rst++;
	}
	return rst;
}
int main()
{
	string s;
	cin >> s;
	k = s;
	int ans = cnt();
	for (int i = 0; i<s.size(); i++)
	{
		k = s;
		if (s[i] == 'K')
			k[i] = 'V';
		else
			k[i] = 'K';
		ans = max(ans, cnt());
	}
	printf("%d\n", ans);
}



#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>

typedef long long ll;
#define MAXN 100000
using namespace std;

string s1, s2;
int main()
{
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] < s2[i])
		{
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] > s2[i])
		{
			s1[i] = s2[i];
		}
	}
	cout << s1 << endl;
	return 0;
}

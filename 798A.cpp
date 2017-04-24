#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;


#define MAXN 100000

using namespace std;

typedef long long ll;

string s;
int main()
{
	cin >> s;
	int num = 0; 
	if (s.size() % 2 == 0)
	{
		for (int i = 0, j = s.size()-1; i < j; i++, j--)
		{
			if (s[i] != s[j])num++;
		}
          if (num == 1)cout << "YES" << endl;
	  else cout << "NO" << endl;
	}
	else
	{
		for (int i = 0, j = s.size()-1; i < j; i++, j--)
		{
			if (s[i] != s[j])num++;
		}
           if (num <= 1)cout << "YES" << endl;
	   else cout << "NO" << endl;
	}
	
	return 0;
}
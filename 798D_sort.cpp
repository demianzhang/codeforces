#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;


#define MAXN 100000

using namespace std;

typedef long long ll;

int n;
struct node
{
	int id;
	int val;
}a[100001], b[100001];
int cmp(node x, node y)
{
	return x.val > y.val;
}

int main()
{
	cin >> n; 
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].val;
		a[i].id = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i].val;
		b[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	cout << n / 2 + 1 << endl << a[1].id;
	for (int i = 2; i <= n; i+=2)
	{
		if (i<n)
		{
			if (b[a[i].id].val>b[a[i + 1].id].val)cout << ' ' << a[i].id;
			else cout << ' ' << a[i + 1].id;
		}
		else  cout << ' ' << a[i].id;
		
	}
	return 0;
}

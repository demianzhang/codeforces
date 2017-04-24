#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;


#define MAXN 100000

using namespace std;

typedef long long ll;

int N;
ll a, b;
ll A[MAXN + 5];
ll B[MAXN + 5];
ll max1, max2;
ll res;

int main()
{
	cin >> N;

	for (int i = 0; i<N; i++)
	{
		cin >> a;
		A[i] = abs(a - b);
		if (i % 2) A[i] *= -1;

		B[i] = abs(a - b);
		if (!(i % 2)) B[i] *= -1;

		b = a;
	}

	for (int i = 1; i<N; i++)
	{
		max1 += A[i];
		max2 += B[i];

		if (max1<0) max1 = 0;
		if (max2<0) max2 = 0;

		if (max1 > res) res = max1;
		if (max2 > res) res = max2;
	}

	cout << res << endl;
}
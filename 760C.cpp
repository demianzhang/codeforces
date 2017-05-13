#include <iostream>
#include <algorithm>
#include <cstring>

const int maxn = 1e6 + 100;
int vis[maxn];
int p[maxn];
int b[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	int sum = 0, ans = 0;
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &b[i]);
		sum += b[i];
	}
	if (sum % 2 == 0)
		ans++;
	int tt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
			continue;
		tt++;
		for (int j = i; !vis[j]; j = p[j])
			vis[j] = 1;
	}
	if (tt>1)
		ans += tt;
	printf("%d\n", ans);
	return 0;
}


#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;


#define MAXN 100000

using namespace std;

typedef long long ll;

bool a[100005];
int mygcd(int x, int y) {
	if (x%y != 0) return mygcd(y, x%y); else return y;
}
int main() {
	int n, i, ans = 0, t;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (i == 1) t = x;
		else {
			if (t != 1) t = mygcd(x, t);
		}
		if (x % 2 == 1) a[i] = true; else a[i] = false;
	}
	if (t != 1) {
		puts("YES");
		puts("0"); return 0;
	}
	for (i = 1; i<n; i++) {
		if (a[i] && a[i + 1]) {
			a[i] = !a[i]; a[i + 1] = !a[i + 1]; ans++;
		}
	}
	for (i = 1; i <= n; i++) {
		if (a[i]) ans += 2;
	}
	puts("YES");
	printf("%d\n", ans);
	return 0;
}
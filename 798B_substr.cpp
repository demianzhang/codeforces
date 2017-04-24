#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;


#define MAXN 100000

using namespace std;

typedef long long ll;

string a[55];
int b[55];
int main() {
	int n, i, j, k, l, ans = 2147483647;
	scanf("%d", &n);
	cin >> a[1];
	l = a[1].length();
	for (i = 2; i <= n; i++) {
		cin >> a[i];
		if (a[i].length() != l) { puts("-1"); return 0; }
	}
	for (i = 2; i <= n; i++) {
		if (a[i] == a[1]) continue;
		bool f = false;
		for (j = 1; j<l; j++) {
			if (a[i].substr(j) + a[i].substr(0, j) == a[1]) { f = true; break; }
		}
		if (f == false) { puts("-1"); return 0; }
	}
	for (i = 0; i<l; i++) {
		int p = 0;
		string t;
		if (i == 0) t = a[1]; else t = a[1].substr(i) + a[1].substr(0, i);
		for (j = 1; j <= n; j++) {
			if (a[j] == t) continue;
			for (k = 1; k<l; k++) {
				if (a[j].substr(k) + a[j].substr(0, k) == t) { p += k; break; }
			}
		}
		if (p<ans) ans = p;
	}
	printf("%d\n", ans);
	return 0;
}
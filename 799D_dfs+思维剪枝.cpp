#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 0X3f3f3f3f
using namespace std;
typedef long long ll;
const int M = 1e5 + 10;
ll z[M], x, y;
bool cmp(int a, int b) {
	return a > b;
}
//last表示上次去的z
bool solve(int pos, ll cx, ll cy, ll last, int type) {
	if (pos == -1) {
		if (cx >= x && cy >= y) return true;
		return false;
	}
	if (type != 1 || z[pos] != last) {
		if (solve(pos - 1, cx * z[pos], cy, z[pos], 0)) return true;
	}
	return solve(pos - 1, cx, cy * z[pos], z[pos], 1);
	//使用last的原因就是由于，z会有重复出现导致dfs出现重复。
}
int main() {
	ll a, b, h, w, n;
	cin >> a >> b >> h >> w >> n;
	for (int i = 0; i < n; i++) {
		cin >> z[i];
	}
	sort(z, z + n, cmp);
	x = a / h + (a % h ? 1 : 0);
	y = b / w + (b % w ? 1 : 0);
	ll pp = 1, ans = inf;
	if (x == 1 && y == 1) {
		ans = 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			pp *= z[i];
			if (pp >= x * y) {
				if (solve(i, (ll)1, (ll)1, (ll)-1, -1)) {
					ans = min(ans, (ll)(i + 1));
				}
			}
		}
		swap(h, w);
		x = a / h + (a % h ? 1 : 0);
		y = b / w + (b % w ? 1 : 0);
		pp = 1;
		if (x == 1 && y == 1) {
			ans = 0;
		}
		for (int i = 0; i < n; i++) {
			pp *= z[i];
			if (pp >= x * y) {
				if (solve(i, (ll)1, (ll)1, (ll)-1, -1)) {
					ans = min(ans, (ll)(i + 1));
				}
			}
		}
	}
	if (ans != inf) {
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}

//题意：给出h*w的矩阵，要求经过操作使得h*w的矩阵能够放下a*b的矩阵，操作为：将长或者宽*z[i]
//
//有n个z[i]而且每个z[i]只能用一次。
//
//
//
//题解：首先我们知道最少要扩大几倍，
//
//x = a / h + (a % h ? 1 : 0);
//
//y = b / w + (b % w ? 1 : 0);
//
//当然要先排一下序从大到小，然后再是for一遍
//
//pp *= z[i];
//
//如果pp >= x*y就是可行。
//
//然后就是dfs，这里dfs直接暴力解决就行但还是需要一点剪枝的，由于会出现重复的z，dfs会出现重复情况这里需要剪一下
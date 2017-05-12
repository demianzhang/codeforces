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
//last��ʾ�ϴ�ȥ��z
bool solve(int pos, ll cx, ll cy, ll last, int type) {
	if (pos == -1) {
		if (cx >= x && cy >= y) return true;
		return false;
	}
	if (type != 1 || z[pos] != last) {
		if (solve(pos - 1, cx * z[pos], cy, z[pos], 0)) return true;
	}
	return solve(pos - 1, cx, cy * z[pos], z[pos], 1);
	//ʹ��last��ԭ��������ڣ�z�����ظ����ֵ���dfs�����ظ���
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

//���⣺����h*w�ľ���Ҫ�󾭹�����ʹ��h*w�ľ����ܹ�����a*b�ľ��󣬲���Ϊ���������߿�*z[i]
//
//��n��z[i]����ÿ��z[i]ֻ����һ�Ρ�
//
//
//
//��⣺��������֪������Ҫ���󼸱���
//
//x = a / h + (a % h ? 1 : 0);
//
//y = b / w + (b % w ? 1 : 0);
//
//��ȻҪ����һ����Ӵ�С��Ȼ������forһ��
//
//pp *= z[i];
//
//���pp >= x*y���ǿ��С�
//
//Ȼ�����dfs������dfsֱ�ӱ���������е�������Ҫһ���֦�ģ����ڻ�����ظ���z��dfs������ظ����������Ҫ��һ��
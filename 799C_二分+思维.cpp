#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int M = 1e5 + 10;
ll a[5], b[M], p[M], CM[M], DM[M];
char cp[M][3];
struct TnT {
	ll pr, be;//pr表示需要多少原料，be表示美丽值为多少
}C[M], D[M];
bool cmp(int x, int y) {
	return x > y;
}
bool cmp1(TnT x, TnT y) {
	return x.pr < y.pr;//按照原料量排序
}
ll binsearch(TnT x[], int l, int r, ll val) {
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (val < x[mid].pr) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return l;
}
int main() {
	ll n, c, d;
	ll M1 = -1, M2 = -1;
	cin >> n >> c >> d;
	for (int i = 0; i < n; i++) {
		cin >> b[i] >> p[i] >> cp[i];
	}
	for (int i = 0; i < n; i++) {
		if (cp[i][0] == 'C' && p[i] <= c) M1 = max(M1, b[i]);
		if (cp[i][0] == 'D' && p[i] <= d) M2 = max(M2, b[i]);
	}
	ll sum = 0;
	if (M1 != -1 && M2 != -1) {
		sum = M1 + M2;//表示各造一种
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (cp[i][0] == 'C') {
			C[cnt1].be = b[i], C[cnt1].pr = p[i];
			cnt1++;
		}
		else {
			D[cnt2].be = b[i], D[cnt2].pr = p[i];
			cnt2++;
		}
	}
	sort(C, C + cnt1, cmp1);
	sort(D, D + cnt2, cmp1);
	memset(CM, -1, sizeof(CM));
	CM[0] = C[0].be;
	for (int i = 1; i < cnt1; i++) {
		CM[i] = max(CM[i - 1], C[i].be);//pr为有序记录小于等于pr的最大美丽值。
	}
	for (int i = cnt1 - 1; i >= 1; i--) {
		ll gg = c - C[i].pr;
		int pos = binsearch(C, 0, i - 1, gg);
		if (pos != 0) {
			sum = max(sum, C[i].be + CM[pos - 1]);
		}
	}
	memset(DM, -1, sizeof(DM));
	DM[0] = D[0].be;
	for (int i = 1; i < cnt2; i++) {
		DM[i] = max(DM[i - 1], D[i].be);
	}
	for (int i = cnt2 - 1; i >= 1; i--) {
		ll gg = d - D[i].pr;
		int pos = binsearch(D, 0, i - 1, gg);
		if (pos != 0) {
			sum = max(sum, D[i].be + DM[pos - 1]);
		}
	}
	cout << sum << endl;
	return 0;
}

//题意：要求造2座fountains，可以用钻石，也可以用硬币来造，但是能用的钻石有限，硬币也有限，问能造出最大的美丽值为多少。
//
//
//
//题解：显然如果两个fountains分别用钻石和硬币来造的话就直接取两种类型里满足条件的最大值即可。
//
//如果选的是同类的话，先按照数量来排序，然后那一个数量为基准二分下个可行的数量，然后还需要一个
//
//数组来存小于等于某个数量的最大美丽值。
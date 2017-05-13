#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int M = 1e5 + 10;
ll a[5], b[M], p[M], CM[M], DM[M];
char cp[M][3];
struct TnT {
	ll pr, be;//pr��ʾ��Ҫ����ԭ�ϣ�be��ʾ����ֵΪ����
}C[M], D[M];
bool cmp(int x, int y) {
	return x > y;
}
bool cmp1(TnT x, TnT y) {
	return x.pr < y.pr;//����ԭ��������
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
		sum = M1 + M2;//��ʾ����һ��
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
		CM[i] = max(CM[i - 1], C[i].be);//prΪ�����¼С�ڵ���pr���������ֵ��
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

//���⣺Ҫ����2��fountains����������ʯ��Ҳ������Ӳ�����죬�������õ���ʯ���ޣ�Ӳ��Ҳ���ޣ����������������ֵΪ���١�
//
//
//
//��⣺��Ȼ�������fountains�ֱ�����ʯ��Ӳ������Ļ���ֱ��ȡ�����������������������ֵ���ɡ�
//
//���ѡ����ͬ��Ļ����Ȱ�������������Ȼ����һ������Ϊ��׼�����¸����е�������Ȼ����Ҫһ��
//
//��������С�ڵ���ĳ���������������ֵ��
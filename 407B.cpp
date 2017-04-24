#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;


int q, l, m;
ll b;
set<ll> st;

int solve(){
	cin >> b >> q >> l >> m;
	int tp; for (int i = 0; i<m; i++) cin >> tp, st.insert(tp);
	int cnt = 0, bad = 0;
	while (abs(b) <= l && cnt < 400000){
		if (st.count(b)) bad++;
		cnt++;
		b = b * q;
	}
	if (cnt - bad > 100000)
		cout << "inf" << endl;
	else
		cout << cnt - bad << endl;
	return 0;
}

int main(){
	
	solve();
	return 0;
}
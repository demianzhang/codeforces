#include <iostream>  
#include <stdio.h>  
using namespace std;
int n, m, k;
bool h[1000015] = { false };
int bones = 1;
int main() {
	cin >> n >> m >> k;
	int holes;
	for (int i = 1; i <= m; i++)
	{
		cin >> holes;
		h[holes] = 1;
	}
	int u, v;
	bool flag = 0;
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d", &u, &v);
		if (h[1] == 1)
		{
			bones = 1;
			flag = 1;
		}
		if ((bones == u || bones == v) && !flag)
		{
			bones = u + v - bones;
		}
		if (h[bones] == 1)
		{
			flag = 1;
		}
	}
	cout << bones << endl;
	return 0;
}
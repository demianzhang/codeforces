#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2007;
const double EPS = 1e-10;

double add(double a, double b)
{
	if (abs(a + b) < EPS*(abs(a) + abs(b)))return 0;
	return a + b;
}

struct P
{
	double x, y;
	P(){}
	P(double x_, double y_) :x(x_), y(y_){}
	P operator + (P p)
	{
		return P(add(x, p.x), add(y, p.y));
	}
	P operator - (P p)
	{
		return P(add(x, -p.x), add(y, -p.y));
	}
	P operator * (double d)
	{
		return P(x*d, y*d);
	}
	double dot(P p)
	{
		return add(x*p.x, y*p.y);
	}
	double det(P p)
	{
		return add(x*p.y, -y*p.x);
	}

}s[MAXN];

bool on_seg(P p1, P p2, P q)//q在p1-p2线段上
{
	return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

double dist(P p1, P p2)//两点间距离公式
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf%lf", &s[i].x, &s[i].y);
	}
	for (int i = n + 1; i <= 2*n; i++)
	{
		s[i] = s[i - n];
	}
	double ans = 1e18;
	for (int i = 1; i <= n; i++)
	{
		double tmp = (s[i + 2] - s[i]).det(s[i + 1] - s[i]) / 2;
		ans = min(ans, tmp / dist(s[i], s[i + 2]));
	}
	printf("%.10f\n", ans);
	return 0;
}

//题目大意：给你一个凸n边形，你可以移动每个点在m范围之内，问你m最大为多少时，这个n边形仍为凸边形。
//
//题目解析：当一个点A和它相连的两个点B、 C退化为成一条直线的时候就不满足题意了。
//
//所以呢，这三个点分别画圆，半径为m，然后一条直线可以切过这三个圆。
//
//然后这个最小的切线就是答案。
//
//如果你画个图可以发现，这三个点组成的三角形，其中点A到BC的距离为2R = 2m
//
//所以求出这个三角形的高h / 2就好了嘛
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

bool on_seg(P p1, P p2, P q)//q��p1-p2�߶���
{
	return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

double dist(P p1, P p2)//�������빫ʽ
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

//��Ŀ���⣺����һ��͹n���Σ�������ƶ�ÿ������m��Χ֮�ڣ�����m���Ϊ����ʱ�����n������Ϊ͹���Ρ�
//
//��Ŀ��������һ����A����������������B�� C�˻�Ϊ��һ��ֱ�ߵ�ʱ��Ͳ����������ˡ�
//
//�����أ���������ֱ�Բ���뾶Ϊm��Ȼ��һ��ֱ�߿����й�������Բ��
//
//Ȼ�������С�����߾��Ǵ𰸡�
//
//����㻭��ͼ���Է��֣�����������ɵ������Σ����е�A��BC�ľ���Ϊ2R = 2m
//
//���������������εĸ�h / 2�ͺ�����
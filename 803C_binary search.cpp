#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1e5+5;
const double eps=1e-4;//精度
int n,p;
int a[N],b[N];
int check(double mid)
{
    double E=mid*p; 
    for(int i=0;i<n;i++)
    {
        double e=b[i]-a[i]*mid;
        if(e<0)E+=e;
        if(E<0)return 0;//如果充电宝的能量不足以供应，说明mid太大
    }
    return 1;//否则mid太小
}
int main()
{
    cin>>n>>p;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    if(sum<=p)
    {
        cout<<-1<<endl;
        return 0;
    }
    double low=0,high=1e18;
    double mid;
    while(high-low>=eps)//实数域上的二分不可能为0，只能以精度控制
    {
        mid=(high+low)/2;
        if(check(mid))low=mid;
        else high=mid;
    } 
    cout<<mid<<endl;
    return 0;
}
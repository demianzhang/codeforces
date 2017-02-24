#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i,start,lim) for(int i=start;i<lim;i++)
bool isprime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)return false;
    }
    return true;
}
vector<int> v;
int main()
{
    int n,i,flag=0;
    cin>>n;
    rep(i,2,n+2)
    {
        if(!isprime(i))
        {
            flag=1;
            v.push_back(2);
        }
        else v.push_back(1);
    }
    if(flag==0)cout<<1<<endl;
    else cout<<2<<endl;
    rep(i,0,n)
    {
        if(i==0)cout<<v[0];
        else cout<<' '<<v[i];
    }
	return 0;
}












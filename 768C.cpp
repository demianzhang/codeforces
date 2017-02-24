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
int cnt[1024],tmp[1024];
int main()
{
	int n,k,maxm=0,minm=INT_MAX,p,x;
    cin>>n>>k>>x;
    rep(i,0,n)cin>>p,cnt[p]++;
    rep(i,0,k)
    {
        rep(j,0,1024)tmp[j]=cnt[j];
        int par=0;
        rep(j,0,1024)
        {
            if(cnt[j]>0)
            {
                int curr=j^x;
                int change=cnt[j]/2;
                if(par==0)change+=(cnt[j]&1);
                tmp[j]-=change;
                tmp[curr]+=change;
                par^=(cnt[j]&1);
            }
        }
        memcpy(cnt,tmp,sizeof(tmp));
    }
    rep(i,0,1024) if(cnt[i]>0) minm=min(minm,i),maxm=max(maxm,i);
	cout<<maxm<<" "<<minm;

	return 0;
}












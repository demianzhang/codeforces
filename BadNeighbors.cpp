//https://community.topcoder.com/stat?c=problem_statement&pm=2402&rd=5009
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

int n;
int s[40],dp1[40],dp2[40];
int maxDonations(int donations[])
{
    dp1[0]=s[0];
    for(int i=1;i<n-1;i++)
        for(int j=0;j<i-1;j++)
    {
        dp1[i]=max(dp1[i],dp1[j]+s[i]);
    }
    dp2[n-1]=s[n-1];
    for(int i=n-2;i>0;i--)
        for(int j=n-1;j>i+1;j--)
    {
        dp2[i]=max(dp2[i],dp2[j]+s[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp1[i]);
        ans=max(ans,dp2[i]);
    }
    return ans;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    cout<<maxDonations(s)<<endl;
    return 0;
}






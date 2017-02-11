//https://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493
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
int s[50];
int dp[50];
int f[50];
int longestZigZag(int sequence[])
{
    memset(f,0,sizeof(f));
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
           if(dp[j]==1)
           {
               if(s[i]!=s[j])
               {
                   if(dp[i]<2)
                   {
                       if(s[j]<s[i])f[i]=1;
                       else f[i]=0;
                   }
                   dp[i]=max(dp[i],2);
               }
               continue;
           }
           if(s[j]<s[i]&&!f[j])
            {
                if(dp[i]<dp[j]+1)f[i]=1;
                dp[i]= max(dp[i],dp[j]+1);
            }
           else if(s[j]>s[i]&&f[j])
           {
                if(dp[i]<dp[j]+1)f[i]=0;
                dp[i]= max(dp[i],dp[j]+1);
           }
        }
    }
    return dp[n-1];
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    cout<<longestZigZag(s)<<endl;
    return 0;
}






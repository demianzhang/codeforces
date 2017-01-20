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

char s[1000];
long long dp[1000];

int main()
{
    long long n;
    scanf("%I64d",&n);
    scanf("%s",s);
    int len=strlen(s);
    for(int i=1;i<=len;i++)
        dp[i]=2e18;
    dp[0]=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='0')
        {
            if(dp[i]>2e18/n)continue;
            dp[i+1]=min(dp[i+1],dp[i]*n);
            continue;
        }
        long long x=0;
        for(int j=i+1;j<=len;j++)
        {
            x=x*10+(s[j-1]-'0');
            if(x>=n)break;
            if(dp[i]>2e18/n)continue;
            dp[j]=min(dp[j],dp[i]*n+x);
        }
    }
    printf("%I64d\n",dp[len]);
    return 0;
}






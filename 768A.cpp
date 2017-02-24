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
int a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int i,j;
    for(i=0;i<n;i++)
    {
        if(a[i]==a[0])continue;
        else break;
    }
    for(j=n-1;j>=0;j--)
    {
        if(a[j]==a[n-1])continue;
        else break;
    }
    if(i>j)cout<<0<<endl;
    else cout<<j-i+1<<endl;
    return 0;
}












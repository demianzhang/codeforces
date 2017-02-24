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

char n1[11],n2[11],n3[11];
int main()
{
    int n;
     cin>>n1>>n2;
     cout<<n1<<' '<<n2<<endl;
     cin>>n;
     getchar();
     rep(i,0,n)
     {
         cin>>n3;
         if(strcmp(n1,n3)==0)
         {
             cin>>n1;
             cout<<n1<<' '<<n2<<endl;
         }
         else
         {
             cin>>n2;
             cout<<n1<<' '<<n2<<endl;
         }
     }
	return 0;
}












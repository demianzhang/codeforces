#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct NODE
{
    int id,in,num;
}node[70000];
struct EDGE
{
    int a,b;
}edge[70000];
int cmp(NODE a,NODE b)
{
    return a.in<b.in;
}
int main()
{
    int m,n,i,t1,t2,cnt;
    while(cin>>n)
    {
        m=n;
        cnt=0;
        queue <NODE> Q;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&t1,&t2);
            node[i].id=i;
            node[i].in=t1;
            node[i].num=t2;
            if(t1==1)
                Q.push(node[i]);
        }
        NODE tt;
        while(!Q.empty())
        {
            tt=Q.front();
            if(node[tt.id].in>0)
            {
              edge[cnt].a=tt.id;
              edge[cnt].b=tt.num;
              cnt++;
              node[tt.num].in--;
              node[tt.num].num^=tt.id;
              if(node[tt.num].in==1)
                  Q.push(node[tt.num]);
            }
            Q.pop();
            //cout<<node[0].in<<endl;
        }
        printf("%d\n",cnt);
        for(i=0;i<cnt;i++)
        {
            printf("%d %d\n",edge[i].a,edge[i].b);
        }
    }
    return 0;
}
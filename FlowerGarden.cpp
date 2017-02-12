//https://community.topcoder.com/stat?c=problem_statement&pm=1918&rd=5006
//拓扑排序，每次选择最大的就好了
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

#define rep(i,n) for(i=0;i<n;i++)
#define cle(a) memset(a,0,sizeof(a))
using namespace std;

struct edge{
    int to;
    int next;
}E[2050];

class FlowerGarden
{
    public:
        int n;
        int ip;
        int in[1005];//入度
        int head[1005];//邻接顶点
        void init()
        {
            ip=0;
            cle(in);
            memset(head,-1,sizeof(head));
        }
        void add(int x,int y){
            in[y]++;
            E[ip].to=y;
            E[ip].next=head[x];
            head[x]=ip++;
        }
    vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt)
       {
          n=height.size();
          int i,j,k;
          vector<int> ans;
          ans.clear();
          init();
          rep(i,n){
               rep(j,n){//有序枚举
                if(i==j)continue;
                   if(height[i]<height[j]){
                      if(!((wilt[j]<bloom[i])||(bloom[j]>wilt[i])))
                            add(height[i],height[j]);
                  }
             }
         }
         int used[1500];cle(used);
         for(i=1;i<=n;i++)
         {
            int maxnum=0;
            for(j=0;j<n;j++)
            {
                if(used[height[j]])continue;
                if(in[height[j]]==0)
                {
                    maxnum=max(maxnum,height[j]);
                }
                //break;
            }
            used[maxnum]=1;
            ans.push_back(maxnum);
            for(k=head[maxnum];k!=-1;k=E[k].next)in[E[k].to]--;
        }
        return ans;
   }
};






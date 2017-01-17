#include <iostream>
using namespace std;

int main()
{

    long long m,n,a;
    long long tmp1=0,tmp2=0;
    cin>>n>>m>>a;
    if(n%a)tmp1=n/a+1;
    else tmp1=n/a;
    if(m%a)tmp2=m/a+1;
    else tmp2=m/a;
    cout<<tmp1*tmp2;
	return 0;
}

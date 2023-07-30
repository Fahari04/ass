#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ans1,n;
    cin>>n;


        ans1=ceil(n/12);
       int ans2=((n/4)-ans1);
       int ans3=((n/2)-(ans1+ans2));
        cout<<ans1<<" "<<ans2<<" "<<ans3;

}

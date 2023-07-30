
#include <bits/stdc++.h>
using namespace std;

int mx=999;
int vis[100];
vector<pair<int,int>>g[100];
pair<int,int>cost[100];

void dfs(int node)
{
    vis[node]=1;
    for(auto child:g[node])
    {
        if(vis[child.first]==0)
        {
            dfs(child.first);
        }
    }
    vis[node]=2;
}

void relax(int u,int v,int w)
{
    if(cost[v].second>cost[u].second+w)
    {
        cost[v].second=cost[u].second+w;
        cost[v].first=u;
    }
}
void path(int v)
{
    if(cost[v].first==0)
    {
        cout<<v<<" ";
        return;
    }
    path(cost[v].first);
    cout<<v<<endl;
}

void DAG(int node,int n)
{
    for(int i=1; i<=n; i++)
    {
        if(vis[i]!=2)
        {
            dfs(i);
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(i==node)
        {
            cost[i].first=0;
            cost[i].second=0;
        }
        else
        {
            cost[i].first=0;
            cost[i].second=mx;
        }
    }
    for(int j=1; j<=n; j++)
    {
        for(auto v:g[j])
        {
            relax(j,v.first,v.second);
        }
    }
}

int main()
{
    int n,e;
    cout<<"node:"<<endl;
    cin>>n;
    cout<<"edge:"<<endl;
    cin>>e;
    cout<<"data:"<<endl;

    while(e--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back(make_pair(y,w));
    }
    int x;
    cout<<"source:"<<endl;
    cin>>x;
    DAG(x,n);

    for(int i=1; i<=n; i++)
    {
        cout<<i<<endl;
        cout<<"PATH:"<<endl;
        path(i);
        cout<<endl;
        cout<<"cost:"<<cost[i].second<<endl;
    }
}

#inlcude <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>n;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int vis[n+1];
    int count=0;
    for(int i=0;i<m;i++)
    {
        if(!vis[i])
        {
            count++;
            //some stuff
        }
    }
    cout<<count;
    return 0;
}
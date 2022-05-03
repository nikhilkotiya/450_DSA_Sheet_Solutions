#include <iostream>
using namespace std;
int parent[10000];
int rank[10000];
void makeSet()
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}
int find_parent(int n)
{
    if(n==parent[n])
    {
        return n;
    }
    return parent[n]=find_parent(parent[n]);
}
void union(int n,int m)
{
    n=find_parent(n);
    m=find_parent(m);
    if(rank[n]>rank[m])
    {
        parent[n]=m;
    }
    else if(rank[n]<rank[m])
    {
        parent[m]=n;
    }
    else
    {
        parent[n]=m;
        rank[m]++;
    }
}
int main() {
    makeSet();
    int m;
    cin>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        union(u,v);
    }
}

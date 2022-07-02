#include <bits/stdc++.h>
using namespace std;
bool rec(vector<int>&v,int arr[],int i,int sum)
{
    if(i>=3)
    {
        if(sum==0)
        {
            for(int i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
            return true;
        }
        return false;
    }
    if(rec(v,arr,i+1,sum )==true)
    {
        return true;
    }
    v.push_back(arr[i]);
    if(rec(v,arr,i+1,sum-arr[i])==true)
    {
        return true;
    }
    v.pop_back();
    return false;
}
int main() {
    int arr[]={3,1,2,1,1,2};
    vector<int>v;
    int sum=3;
    vector<vector<int>>v2;
    rec(v,arr,0,sum);
}
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    int gapfind(int n)
    {
        int x=n;
        if(x==1 || x==0)
        {
            return 0;
        }
        if(x%2==0)
        {
            return x/2;
        }
        return (x/2)+1;
    }
	void merge(int arr1[], int arr2[], int n, int m) {
	    int gap=n+m;
	    int i=0;
	    int j=0;
	    while(gap)
	    {
	        gap=gapfind(gap);
	        for(i=0 ;i+gap<n;i++)
	        {
	            if(arr1[i]>arr1[i+gap])
	            {
	                swap(arr1[i],arr1[i+gap]);
	            }
	        }
	        for(j = gap>n?gap-n:0; j<m && i<n; i++,j++)
	        {
	            if(arr1[i]>arr2[j])
	            {
	                swap(arr1[i],arr2[j]);
	            }
	        }
	        if(j<m)
	        {
	            for(j=0;j+gap<m;j++)
	            {
    	            if(arr2[j]>arr2[j+gap])
                    {
                        swap(arr2[j],arr2[j+gap]);
                    }
	            }
	        }
	    }
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
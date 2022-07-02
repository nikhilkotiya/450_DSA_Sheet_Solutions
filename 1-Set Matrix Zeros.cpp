// Brute force-> create another matrix and copy all the values in 2nd matrix and then iterate in 1st matrix and when we get 0 then we
// iterate in col and raw and change all values to 0


// Time Complexity: O((N*M)*(N + M)). O(N*M) for traversing through each element and (N+M)for traversing to row and column of elements 
// having value 0.
// space complexity: O(N*M)


// 2nd space Optimised
void setZeroes(vector < vector < int >> & matrix) {
  int rows = matrix.size(), cols = matrix[0].size();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 0) {

        int ind = i - 1;
        while (ind >= 0) {
          if (matrix[ind][j] != 0) {
            matrix[ind][j] = -1;
          }
          ind--;
        }
        ind = i + 1;
        while (ind < rows) {
          if (matrix[ind][j] != 0) {
            matrix[ind][j] = -1;
          }
          ind++;
        }
        ind = j - 1;
        while (ind >= 0) {
          if (matrix[i][ind] != 0) {
            matrix[i][ind] = -1;

          }
          ind--;
        }
        ind = j + 1;
        while (ind < cols) {
          if (matrix[i][ind] != 0) {
            matrix[i][ind] = -1;

          }
          ind++;
        }
      }
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] <= 0) {
        matrix[i][j] = 0;
      }
    }
  }

}
// 3rd Instead  of traversing through each raw and col, we can create dummy array to check if the particular raw or col has element 0 or not,
// which imporve the time complexity.
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &mat)
{
    int n=mat.size();
    int m=mat[0].size();
    vector<int>v1(n,0);
    vector<int>v2(m,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                v1[i]=1;
                v2[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v1[i]==1 || v2[j]==1)
            {
                mat[i][j]=0;    
            }
        }
    }
}
// 4th 
// Instead of taking two dummy arrays we can use the first row and column of the matrix for the same work. This will help to reduce the space
//  complexity of the problem. While traversing for the second time the first row and column will be computed first, which will affect the 
// values of further elements that’s why we traversing in the reverse direction.
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &mat)
{
	// Write your code here.
    int n=mat.size();
    bool raw=0;
    int m=mat[0].size();
    for(int i=0;i<m;i++)
    {
        if(mat[0][i]==0)
        {
            raw=1;
            break;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                mat[i][0]=0;
                mat[0][j]=0;
            }    
        }    
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==0)
            {
                if(raw==1)
                {
                      mat[i][j]=0;
                }
            }
            else if(mat[0][j]==0 || mat[i][0]==0)
            {
                mat[i][j]=0;    
            }
        }    
    }
}
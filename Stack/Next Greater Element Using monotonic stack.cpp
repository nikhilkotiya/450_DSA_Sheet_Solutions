// brute force 
// for every value of nums1 we iterate in nums2 and after a val matches with nums1 val then 
// we start find nexrt greater element of that value
// time complexity - O(N^2)
// space - O(N)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for(int i=0;i<nums1.size();i++)
        {
            int f=0;
            for(int j=0;j<nums2.size();j++)
            {
                if(f==1)
                {
                    break;
                }
                int next=-1;
                if(nums1[i]==nums2[j])
                {
                    int x=j+1;
                    for(x;x<nums2.size();x++)
                    {
                        if(nums2[j]<nums2[x])
                        {
                            next=nums2[x];
                            f=1;
                            v.push_back(next);
                            break;
                        }
                    }
                    if(x>=nums2.size())
                    {
                         v.push_back(next);   
                    }
                }
            }
        }
        return v;
    }
};
// optimised Apprach 
// By using a monotonic stack property we can find the next greater elemnt of an array
// Decreasing Monotonic stack ->  we iterate in a array if stack is empty then we put that comming 
// value in satck. If arr[i] > stack.top() it means it breaking the decreasing order so we pop out
// stack.top value and save that arr[i] & stack top in map, we do this until arr[i] > stack.top(). 
// After iterating till n that value remanin in stack that value haven't his next greater element.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v(nums1.size(),-1);
        map<int,int>m;
        map<int,int>:: iterator it;
        stack<int>s;
        for(int i=0;i<nums2.size();i++)
        {
            while(s.size()!=0 && s.top()<nums2[i])
            {
                m[s.top()]=nums2[i]; // saving next greater in map
                s.pop();  // poping value which is less then arr[i]
            }
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            if(m.find(nums1[i])!=m.end())
            {
                v[i]=m[nums1[i]];
            }
        }
        return v;
    }
};
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)
            return 0;
        set<char> st;
        int maxsize=0;
        int i=0,j=0;
        while(j<n)
        {
            if(st.count(s[j])==0)
            {
                st.insert(s[j]);
                maxsize=max(maxsize,(int)st.size());
                j++;
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return maxsize;
    }
// 2nd 
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }

//3rd 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==1)
        {
            return 1;    
        }
        string x="";
        map<int,int>m;
        int count=0;
        int r=0;
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(m.find(s[i])!=m.end() && m[s[i]]>=r)
            {
                r=m[s[i]]+1;
                f=1;
                m[s[i]]=i;
            }
            else
            {
                m[s[i]]=i;   
            }
            count=max(i-r+1,count);  
        }
        if(f==1)
        {
            return count;
        }
        return n;
    }
};
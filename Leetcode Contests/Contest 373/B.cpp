class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int res=0,n=s.size();
        set<char> st = {'a','e','i','o','u'};
        for(int i=0;i<n;i++)
        {
            int v=0,c=0;
            for(int j=i;j<n;j++)
            {
                if(st.count(s[j])) v++;
                else c++;
                if(c && v && c == v && (c*v)%k == 0)
                    res++;
            }
        }
        return res;
    }
};
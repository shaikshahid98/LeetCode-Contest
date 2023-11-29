class Solution {
public:
    string getbase(int n,int i)
    {
        string res= "";
        while(n)
        {
            int tmp = n/i;
            int rm = n - (i*tmp);
            res = to_string(rm) + res; 
            n=n/i;
        }
        return res;
    } 
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++)
        {
            auto st = getbase(n,i);
           // cout<<st<<endl;
            auto rv = st;
            reverse(begin(rv),end(rv));
            if(rv != st)
            return false;
        }
        return true;
    }
};
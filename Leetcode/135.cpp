class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size(),res=0;
        if(n==1)return 1;
        vector<int> p(n,1);
        for(int i=n-2;i>=0;i--)
            if(r[i] > r[i+1])
                p[i] = p[i+1]+1;
        for(int i=1;i<n;i++)
            if(r[i] > r[i-1])
                p[i] = max(p[i],p[i-1] + 1 );
        for(int i:p) res+=i;
        return res;
    }
};

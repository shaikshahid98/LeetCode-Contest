class Solution {
public:
    int minimumAddedCoins(vector<int>& c, int t) {
        long miss = 1;
        int res=0;
        int i=0,n=c.size();
        sort(begin(c),end(c));
        while(miss<=t)
        {
            if(i< n && c[i] <= miss) miss+= c[i++];
            else miss+=miss,res++;
        }
        return res;
    }
};
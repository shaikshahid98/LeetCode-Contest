class Solution {
public:
    int maxCoins(vector<int>& p) {
        int res=0;
        int l=0,h=p.size()-1;
        sort(begin(p),end(p));
        while(l<h)
        {
            h--;
            res+=p[h];
            //cout<<"now taking "<<p[h]<<endl;
            h--;
            l++;
        }
        return res;
    }
};

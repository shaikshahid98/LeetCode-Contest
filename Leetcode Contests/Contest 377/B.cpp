class Solution {
public:
    const int mod = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        set<int> st;
        h.push_back(1);
        h.push_back(m);
           v.push_back(1);
        v.push_back(n);
        sort(begin(h),end(h));        
        sort(begin(v),end(v));

        for(int i=0;i<h.size();i++)
            for(int j=i+1;j<h.size();j++)
                if(i!=j)
                {
                    st.insert(abs(h[i]-h[j]));
                }
        
        long long res = 0 ;
     
        for(int i=0;i<v.size();i++)
            for(int j=i+1;j<v.size();j++)
                if(i!=j)
                {
                    long long dis = (abs(v[i]-v[j])); 
                    if(st.count(dis))
                        res = max(res,dis);
                }
        return res == 0 ? -1 : (res*res) % mod;
    }
};
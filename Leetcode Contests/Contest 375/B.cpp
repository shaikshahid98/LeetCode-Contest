class Solution {
public:
   
    int modulo(int a, int b, int n){
    long long x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}
    vector<int> getGoodIndices(vector<vector<int>>& v, int t) {
        int i=0;
        vector<int> res;
        for(auto p:v)
        {
            int a = p[0],b=p[1],c=p[2],d=p[3];
            int cur = 1;
            int t1= modulo(a,b,10);
            int t2 = modulo(t1,c,d);
            if(t2 == t)
                res.push_back(i);
            i++;
        }
        return res;
    }
};
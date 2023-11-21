class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) {
        int res=1;
        if(a.size() == 1) return 1;
        sort(begin(a),end(a));
        a[0] =1;
        int n=a.size();
        for(int i=1;i<a.size();i++)
        {
            if(abs(a[i] - a[i-1]) <=1) continue;
            else a[i] = a[i-1] + 1,res++;
        }
        return max(res,a[n-1]);
    }
};
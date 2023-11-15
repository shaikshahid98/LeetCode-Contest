class Solution {
public:
    int solve(vector<int> a,vector<int> b)
    {
         int mx1 = INT_MIN,mx2=INT_MIN;
        int n=a.size();
         for(int i=0;i<n;i++) mx1=max(mx1,a[i]);        
        for(int i=0;i<n;i++) mx2=max(mx2,b[i]);
        int t1 = a[n-1],t2 = b[n-1];
        if(mx1 == a[n-1] && mx2 == b[n-1]) return 0;
        int res = 0;
        for(int i = 0;i<n-1;i++)
        {
            if(a[i] <= t1 && b[i] <= t2) continue;
            if(b[i] > t1 || a[i] > t2) return -1;
            swap(b[i],a[i]);
            res++;            
        }
        return res;
    }
    int minOperations(vector<int>& a, vector<int>& b) {
       int t1 = solve(a,b);
      
        int n=a.size();
        swap(a[n-1],b[n-1]);
        int t2 = solve(a,b);
          if(t1 == -1 && t2 == -1 ) return -1;
        return min(t1 , 1 +  t2 );
    }
};
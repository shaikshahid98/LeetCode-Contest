class Solution
{
    using int64 = long long;
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        map<int64,int64> mp;
        int64 sm =0 ;
        
        for(int64 l=0,h=0;l<=h && h<n;h++)
        {
            sm+=arr[h];
            while(sm > s){
                sm-=arr[l++];
            }
            if(sm ==s && sm >0) return {l+1,h+1};
        }
        
        
        return {-1};
    }
};
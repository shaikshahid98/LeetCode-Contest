class Solution {
public:
    int countTestedDevices(vector<int>& b) {
        int dec = 0;
        int res=0;
        for(int i:b)
        {
            if(i+dec > 0)
            {
                res++;
                dec--;
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> numberGame(vector<int>& ar) {
        vector<int>res = ar;
        sort(begin(res),end(res));
        for(int i=0;i<ar.size();i+=2)
        {
            swap(res[i],res[i+1]);
        }
        return res;
    }
};
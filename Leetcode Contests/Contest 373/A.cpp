class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        auto org = mat;
        int m = mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            auto tmp = mat[i];
            k=k%n;
            if(i%2)
            for(int j=0;j<n;j++)
            {
                mat[i][(j+k)%n] = tmp[j];
            }
            else
            {
                for(int j=0;j<n;j++)
            {
                mat[i][(j-k+n)%n] = tmp[j];
            }
            }
        }
        return org == mat;
    }
};
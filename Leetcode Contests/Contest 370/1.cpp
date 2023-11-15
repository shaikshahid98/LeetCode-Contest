class Solution {
public:
    int findChampion(vector<vector<int>>& gr) {
        for(int i=0;i<gr.size();i++)
        {
            bool ok=1;
            for(int j=0;j<gr[0].size();j++)
            {
                if(i!=j && gr[i][j] != 1) ok = false;
            }
            if(ok) return i;
        }
        return -1;
    }
};
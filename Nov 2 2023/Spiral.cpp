class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& ma) {
        vector<int> res;
        int m =  ma.size(),n=ma[0].size();
        int top = 0,bot = m-1;
        int l = 0,h=n-1;
        while(res.size() < m * n)
        {
            for(int i=l;i<=h;i++)
                res.push_back(ma[top][i]);
            top++;
            for(int i=top;i<=bot;i++)
                res.push_back(ma[i][h]);
            h--;
            for(int i= h;i>=l;i--)
                if(top<=bot)
                res.push_back(ma[bot][i]);
            bot--;
            for(int i=bot;i>=top;i--)
            if(l<=h)
                res.push_back(ma[i][l]);
            l++;
        }
        return res;
    }
};
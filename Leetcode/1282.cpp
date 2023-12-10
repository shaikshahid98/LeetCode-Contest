class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<vector<int>> res;

        map<int,vector<int>> mp;
        int n=gs.size();
        for(int i=0;i<n;i++)
        {
            int k = gs[i];
            if(mp[k].size() == k)
            {
                vector<int> tmp = {i};
                res.push_back(mp[k]);
                mp[k] = tmp;
            }
            else{
                mp[k].push_back(i);
            }
        }
        for(auto &p:mp)
        {
            if(p.second.size())
                res.push_back(p.second);
        }
        return res;
    }
};
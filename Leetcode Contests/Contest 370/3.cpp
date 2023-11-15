
class Solution {
public:
    #define ll long long
    ll dfs(int st,vector<vector<int>> &gr,vector<int> &v,vector<bool> &vis)
    {
        ll cur = 0;
        vis[st] = 1;
        if(gr[st].size() == 1 && st != 0) return (ll)v[st];
        for(int i:gr[st])
        {
            if(vis[i] == 0){
                ll tmp = dfs(i,gr,v,vis);
            // cout<<"Got sum "<<tmp << " at index "<<st<<endl;
            cur+=tmp;
            }
        }
        // cout<<"Total sum at index "<<st <<" is "<<cur<<endl;
        return min(cur,(ll)v[st]);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& v) {
        vector<vector<int>> gr(v.size());
        for(auto p:edges) gr[p[0]].push_back(p[1]), gr[p[1]].push_back(p[0]);
        vector<bool> vis(v.size(),0);
        ll sum  = 0;
        for(int i:v) sum+=(ll)i;
        ll reqs = dfs(0,gr,v,vis);
        return sum -reqs; 
    }
};
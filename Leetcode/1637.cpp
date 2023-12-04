class Solution {
public:
    #define pr pair<int,int>
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        priority_queue<pr> pq;
        for(auto &p:points)
            pq.push({p[0],p[1]});
        auto cur = pq.top();pq.pop();
        int res=0;
        while(pq.size())
        {
            auto tmp = pq.top();
            res = max(res,cur.first - tmp.first);
            cur = tmp;
            pq.pop();
        }
        return res;
    }
};

vector<int> jumpingNumbers(int n)
{
    vector<int> res = {0};
    queue<int> q;
    for(int i =1;i<=9;i++)
        q.push(i);
    while(q.size())
    {
        int cur = q.front();q.pop();
        if(cur<=n)
        {
        res.push_back(cur);
            int lst = cur % 10;

            if(lst==0)
            {
                q.push(cur * 10 + (lst+1));
            }
            else if(lst == 9)
                q.push(cur * 10 + (lst-1));
            else{
                q.push(cur * 10 + (lst-1));
                q.push(cur * 10 + (lst+1));
            }

        }
    }   

    return res; 
    
}
int bfs(int **arr,int start,int visited[],int n,int cisl)
{
    int total_wt=0;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {

        int node=q.front();
        q.pop();
        if(visited[node]==0)
        {
            //cout<<node<<" ";
            visited[node]=1;
            for(int i=0;i<n;i++)
            {
                if(arr[node][i]==0)
                continue;
                if(visited[i]==0)
                {
                    q.push(i);
                    total_wt+=arr[node][i];
                }
            }
        }
    }
//解法一：bfs 广度优先遍历
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       
        int r =grid.size();
        if(r==0)
            return 0;
        int w = grid[0].size();
        int res=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<w;j++)
            {
                 if(grid[i][j]=='1')
                 {
                    queue<pair<int, int> > myQueue;
                    res++;
                    myQueue.push({i,j});
                    grid[i][j]='0';
                    while(!myQueue.empty())
                    {   
                        auto rc = myQueue.front();
                        myQueue.pop();
                        int row = rc.first, clo = rc.second;
                        if(row-1>=0 && grid[row-1][clo]=='1')
                        {
                            myQueue.push({row-1,clo});
                            grid[row-1][clo]='0';
                        }
                        if(clo-1>=0 && grid[row][clo-1]=='1')
                        {
                            myQueue.push({row,clo-1});
                            grid[row][clo-1]='0';
                        }
                        if(row+1<r && grid[row+1][clo]=='1')
                        {
                            myQueue.push({row+1,clo});
                            grid[row+1][clo]='0';
                        }
                        if(clo+1<w && grid[row][clo+1]=='1')
                        {
                            myQueue.push({row,clo+1});
                            grid[row][clo+1]='0';
                        }
                    }
                 }
            }
        }
        return res;
    }
};
class Solution {
public:
    bool helper(vector<string>&board,int r,int c)
    {
        int n=board.size();
        //row
        for(int i=0;i<c;i++)
            if(board[r][i]=='Q')
                return false;
        for(int j=0;j<r;j++)
            if(board[j][c]=='Q')
                return false;
        int x=r-1,y=c-1;
        while(x>=0 && y>=0)
        {
            if(board[x][y]=='Q')
                return false;
            x--;y--;
        }
        x=r-1,y=c+1;
        while(x>=0 && y<n)
        {
            if(board[x][y]=='Q')
                return false;
            x--;
            y++;
        }
        return true;
    }
    void solve(vector<string> &board,int i,int n,vector<vector<string>> &res)
    {
        if(i==n)
        {
            res.push_back(board);
            return;
        }
        for(int j=0;j<n;j++)
        {
           bool isSafe=helper(board,i,j);
            if(isSafe)
            {
                board[i][j]='Q';
                solve(board,i+1,n,res);
                board[i][j]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> res;
        solve(board,0,n,res);
        return res;
    }
};
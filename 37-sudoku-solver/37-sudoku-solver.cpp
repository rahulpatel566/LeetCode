class Solution {
public:
    bool helper(vector<vector<char>>& board,int r,int c,char ch)
    {
        //chack row and col
        for(int i=0;i<9;i++)
        {
            if(board[r][i]==ch || board[i][c]==ch)
                return false;
        }
        //check 3*3 grid
        int sx=(r/3)*3,sy=(c/3)*3;
        for(int i=sx;i<sx+3;i++)
        {
           for(int j=sy;j<sy+3;j++)
           {
               if(board[i][j]==ch)
                return false;
           }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int i,int j)
    {
        //base case
        if(i==9)
            return true;
        if(j==9)
            return solve(board,i+1,0);
        if(board[i][j]!='.')
            return solve(board,i,j+1);
        //time to fill the grid
        for(char n='1';n<='9';n++)
        {
            bool isSafe=helper(board,i,j,n);
            if(isSafe)
            {
                board[i][j]=n;
                if(solve(board,i,j+1))
                   return true;
                board[i][j]='.';
            }
          
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};
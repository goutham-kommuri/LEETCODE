class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<int> path;
        vector<vector<int>> board(n,vector<int>(n,0));
        solve(board,n,0,output,path);
        return output;        
    }

    void solve(vector<vector<int>>& board,int& n,int row,vector<vector<string>>& output,vector<int> path){
        if(row==n){
            make_ans(output,path,n);
            return;
        }
        for(int i=0;i<n;i++){
            board[row][i]=1;
            if(isSafe(board,row,i,n)){
                path.push_back(i);
                solve(board,n,row+1,output,path);
                path.pop_back();
            }
            board[row][i]=0;
        }
        return;
    }

    bool isSafe(vector<vector<int>>& board,int row,int col,int n){
        //straight line upward
        int x=row-1;
        int y=col;
        while(x>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
        }
        //diagonaly left
        x=row-1;
        y=col-1;
        while(y>=0 && x>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        //diagoally right
        x=row-1;
        y=col+1;
        while(y<n && x>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y++;
        }

        return true;
    }

    void make_ans(vector<vector<string>>& output,vector<int> path,int n){
        vector<string> ans;
        for(auto i:path){
            string temp(n,'.');
            temp[i]='Q';
            ans.push_back(temp);
        }
        output.push_back(ans);

    }
};
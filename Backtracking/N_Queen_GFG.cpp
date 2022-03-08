    void backtrack(vector<int> &temp, int n, vector<int> &LR, vector<int> &LD, vector<int> &UD, vector<vector<int>> &ans, int col)
    {
        if(col > n) return;
        if(col == n){
            ans.push_back(temp);
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(LD[n-1 + col-row] == 0 && UD[row+col] == 0 && LR[row] == 0) {
                temp.push_back(row+1);
                LD[n-1 + col-row] = 1;
                UD[row+col] = 1;
                LR[row] = 1;
                
                backtrack(temp, n, LR, LD, UD, ans, col+1 );
                
                temp.pop_back();
                LD[n-1 + col-row] = 0;
                UD[row+col] = 0;
                LR[row] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> B(n, vector<int>(n, 0));
        vector<int> LR(n, 0), LD(2*n - 1, 0), UD(2*n - 1, 0), temp;
        vector<vector<int>> ans;
        backtrack(temp, n, LR, LD, UD, ans, 0);
        return ans;
    }

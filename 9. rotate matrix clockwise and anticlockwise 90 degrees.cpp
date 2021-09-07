// code to rotate the matrix to anti-clock wise 90 degrees.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        
        // transpose
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // column reverse code below
        int k;
        for(int i = 0; i < n; i++){
            k = n-1;
            for(int j = 0; j < k; j++){
                swap(matrix[j][i], matrix[k][i]);
                k--;
            }
        }
        
    }
};


// code to rotate the matrix to clock wise 90 degrees.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        
        // transpose
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // row reverse code below
        int k;
        for(int i = 0; i < n; i++){
            k = n-1;
            for(int j = 0; j < k; j++){
                swap(matrix[i][j], matrix[i][k]);
                k--;
            }
        }
        
        // or row reverse code 
        
        // for(int i = 0; i<n; i++){
        //     reverse(matrix[i].begin(), matrix[i].end());
        // }
        
        
    }
};

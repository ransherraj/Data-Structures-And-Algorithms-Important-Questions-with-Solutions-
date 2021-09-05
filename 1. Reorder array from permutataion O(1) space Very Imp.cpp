class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i] += n * (nums[nums[i]] % n);
        }
        
        for(int j = 0; j < n; j++){
            nums[j] /= n;
        }
        return nums;
    }
};

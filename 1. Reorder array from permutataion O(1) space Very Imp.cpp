//O(1) space solution

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



//O(n) space solution
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums);
        int j = 0;
        for(auto i : nums){
            ans[j++] = nums[i];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (unsigned int i = 0; i < nums.size(); ++i){
            for (unsigned int j = i+1; j < nums.size(); ++j){
                if (nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        } 
        
        return result;
    }
        
    

};
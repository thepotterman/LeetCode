class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        int from_first = 1;
        int from_last = 1;
        for(int i = 0; i < n - 1; ++i) {
            from_first *= nums[i];
            from_last *= nums[n - 1 - i];
            answer[1 + i] *= from_first;
            answer[n - 2 - i] *= from_last;
        }
        return answer;
    }
};

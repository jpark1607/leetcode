/* Problem 303. Range Sum Query - Immutable
 * https://leetcode.com/submissions/detail/592050200/
 * 1. 문제:
 *   vector의 범위 합을 보여주는 class를 만들어라.
 *
 * 2. 아이디어:
 *   처음부터 i까지의 모든 부분합을 저장해 놓는다.
 * */
class NumArray {
private:
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        int i, size = nums.size();

        prefixSum.push_back(nums[0]);

        for (i = 1; i < size; i++)
            prefixSum.push_back(prefixSum[i - 1] + nums[i]);
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return prefixSum[right];
        else
            return prefixSum[right] - prefixSum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
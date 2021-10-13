/* Problem 46. Permutations
 * https://leetcode.com/submissions/detail/570604389/
 * 1. 문제:
 *   주어진 vector의 인자들로 순열의 모든 경우의 수를 만들어라.
 *
 * 2. 아이디어:
 *   쓴 수만 임시로 -99로 변경하고, recursive로 들어간다.
 * */
class Solution {
public:
    void makePartPerm(vector<vector<int> > &res, vector<int> nums, vector<int> list, int cnt) {
        int i;
        int size = nums.size();

        if (cnt == size) {
            res.push_back(list);
            return;
        }

        list.push_back(0);

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != -99) {
                list[cnt] = nums[i];
                nums[i] = -99;
                makePartPerm(res, nums, list, cnt + 1);
                nums[i] = list[cnt];
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums) {
        int size = nums.size();
        vector<vector<int> > res;
        vector<int> list;

        makePartPerm(res, nums, list, 0);

        return res;
    }
};
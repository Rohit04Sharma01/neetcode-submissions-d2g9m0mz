class Solution {
private:
    bool solve(int idx,
               vector<int>& nums,
               vector<int>& sides,
               int target) {

        if (idx == nums.size()) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }

        for (int i = 0; i < 4; i++) {

            // cannot exceed target
            if (sides[i] + nums[idx] > target)
                continue;

            // symmetry pruning
            if (i > 0 &&
                sides[i] == sides[i - 1])
                continue;

            sides[i] += nums[idx];

            if (solve(idx + 1,
                      nums,
                      sides,
                      target))
                return true;

            sides[i] -= nums[idx];
        }

        return false;
    }

public:
    bool makesquare(vector<int>& nums) {

        int perimeter =
            accumulate(nums.begin(),
                       nums.end(),
                       0);

        if (perimeter % 4 != 0)
            return false;

        int target = perimeter / 4;

        sort(nums.rbegin(),
             nums.rend());

        // largest stick impossible
        if (nums[0] > target)
            return false;

        vector<int> sides(4, 0);

        return solve(0,
                     nums,
                     sides,
                     target);
    }
};
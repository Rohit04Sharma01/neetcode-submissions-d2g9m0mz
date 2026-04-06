class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = -1;
        int cand2 = -1;
        int vote1 = 0;
        int vote2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (cand1 == nums[i]) vote1 += 1;
            else if (cand2 == nums[i]) vote2 += 1;
            else if (!vote1) { cand1 = nums[i]; vote1++; }
            else if (!vote2) { cand2 = nums[i]; vote2++; }
            else { vote1 -=1; vote2 -=1; }
        }
        vote1 = vote2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == cand1) vote1++;
            else if (nums[i] == cand2) vote2++;
        }

        vector<int> r;
        if (vote1 > n/3) r.push_back(cand1);
        if (vote2 > n/3) r.push_back(cand2);

        return r;
    }
};
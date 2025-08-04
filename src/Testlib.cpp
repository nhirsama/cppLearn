#include "bits/stdc++.h"
class Solution {
public:
    int subarraysWithKDistinct(std::vector<int> &nums, int k) {
        int n = nums.size();
        int ans = 0, cur = 0;
        std::vector<int> cnt(n + 1);
        for (int l = 0, r = 0; r < n;) {
            cnt[nums[r]]++;
            if (cnt[nums[r]] == 1) cur++;
            while (l < r && cur > k) {
                cnt[nums[l]]--;
                if (!cnt[nums[l]]) cur--;
                l++;
            }
            while (0 < l && cur < k) {
                cnt[nums[l - 1]]++;
                if (cnt[nums[l - 1]] == 1) cur++;
                l--;
            }
            while (0 < l && cur == k) {
                if (cnt[nums[l - 1]] == 0) break;
                cnt[nums[l - 1]]++;
                l--;
            }
            while (l < r && cur == k) {
                ans++;
                if (cnt[nums[l]] == 1) break;
                cnt[nums[l]]--;
                l++;
            }
            std::cout << l << ' ' << r << std::endl;
            r++;
        }
        return ans;
    }
};

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    for (auto &i: nums) {
        std::cin >> i;
    }
    Solution t;
    std::cout << t.subarraysWithKDistinct(nums, k);
}
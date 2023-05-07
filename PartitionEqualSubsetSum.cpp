https://leetcode.com/problems/partition-equal-subset-sum/description/

1. hashmap
bool canPartition(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2) return false;

    const int target = totalSum / 2;
    unordered_set<int> memo = {0};

    for (const int& number : nums) {
        vector<int> possibleSums(memo.begin(), memo.end());
        for (const int& possibleSum : possibleSums) {
            memo.insert(possibleSum + number);
        }
    }
    return memo.count(target);
}

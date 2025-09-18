class Solution {
public:
    int lcm(int x, int y) {
        long long f = (long long)x * (long long)y;
        long long z = std::gcd(x, y);
        long long p = f / z;
        return (int)p;
    }

    std::vector<int> replaceNonCoprimes(std::vector<int>& nums) {
        std::map<std::pair<int, int>, int> currGcd;
        int l = 0, r = 0;
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        std::pair<int, int> currPair = {l, r};
        currGcd[{l, r}] = nums[0];
        std::map<int, std::pair<int, int>> rightEnd;
        rightEnd[r] = currPair;

        while (true) {
            int j = r + 1;
            bool last = false;
            if (j < n && std::gcd(currGcd[currPair], nums[j]) > 1) {
                currGcd[{l, j}] = lcm(currGcd[currPair], nums[j]);
                rightEnd[j] = {l, j};
                currPair = {l, j};
                r++;
            } else if (j < n && std::gcd(currGcd[currPair], nums[j]) == 1) {
                currPair = {j, j};
                currGcd[currPair] = nums[j];
                l = j;
                rightEnd[j] = {j, j};
                r++;
            } else {
                rightEnd[j - 1] = {currPair.first, j - 1};
                last = true;
            }

            while (true) {
                int left = currPair.first;
                if (left > 0) {
                    int right = left - 1;
                    std::pair<int, int> lastPair = rightEnd[right];
                    if (std::gcd(currGcd[lastPair], currGcd[currPair]) > 1) {
                        currGcd[{lastPair.first, currPair.second}] = lcm(currGcd[lastPair], currGcd[currPair]);
                        currPair.first = lastPair.first;
                        rightEnd[currPair.second] = currPair;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            if (last) break;
        }

        std::vector<int> ans;
        int currRight = n - 1;

        while (currRight >= 0) {
            std::pair<int, int> bestPair = rightEnd[currRight];
            ans.push_back(currGcd[bestPair]);
            currRight = bestPair.first - 1;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

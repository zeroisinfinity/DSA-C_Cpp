class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;
        if (amount == 0) return 1;
        if (coins.empty()) return 0;

        // ---- GCD shortcut ----
        int g = 0;
        for (int c : coins) g = std::gcd(g, c);
        if (amount % g != 0) return 0;   // cannot ever form 'amount'

        // ---- Your odd-amount parity shortcut ----
        bool hasEven = false;
        bool hasAmountOdd = false;   // odd coin equal to 'amount'
        if (amount % 2 != 0) {
            for (int l : coins) {
                if (l % 2 == 0) {
                    hasEven = true;
                } else {
                    if (l != amount) {   // some other odd coin exists
                        hasEven = false; // kill shortcut
                        break;
                    } else {
                        hasAmountOdd = true;
                    }
                }
            }
        }
        // all coins even + maybe an odd 'amount' coin, nothing else odd
        if (hasEven && hasAmountOdd) return 1; // only {amount} works
        if (hasEven && !hasAmountOdd) return 0; // all-even coins, odd amount

        // ---- Standard Coin Change II DP ----
        for (int cn : coins) {
            for (int s = cn; s <= amount; ++s) {
                dp[s] += dp[s - cn];
            }
        }

        return (int)dp[amount];
    }
};


class Solution {
public:
    // LCM of two numbers
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
    // Count how many DISTINCT valid amounts are <= x
    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;
        // We use bitmask to generate ALL NON-EMPTY SUBSETS of coins.
        //
        // Example: coins = [2, 3, 5]
        //
        // 001 -> {2}
        // 010 -> {3}
        // 011 -> {2,3}
        // 100 -> {5}
        // 101 -> {2,5}
        // 110 -> {3,5}
        // 111 -> {2,3,5}
        //
        // Total non-empty subsets = 2^n - 1

        for (int mask = 1; mask < (1 << n); mask++) {

            // L will store the LCM of the coins
            // present in the current subset.
            long long L = 1;

            // Number of coins present in this subset
            int bits = 0;

            for (int i = 0; i < n; i++) {

                // Check whether the i-th coin is present
                // in the current subset.
                //
                // Example:
                // mask = 101
                // i = 0 -> coin is present
                // i = 1 -> coin is NOT present
                // i = 2 -> coin is present
                if (mask & (1 << i)) {

                    bits++;

                    // We need LCM because we are finding
                    // numbers that are multiples of ALL
                    // coins in this subset.
                    //
                    // Example:
                    // subset {2,3}
                    // common multiples = 6,12,18,...
                    // LCM(2,3) = 6

                    L = lcm(L, coins[i]);

                    // If LCM itself is greater than x,
                    // then there cannot be ANY common multiple
                    // <= x.
                    //
                    // Example:
                    // L = 30, x = 20
                    // Multiples of 30: 30,60,90,...
                    // None are <= 20.
                    //
                    // Therefore this subset contributes 0.
                }
            }
            // INCLUSION-EXCLUSION PRINCIPLE
            //
            // Union of sets:
            //
            // + Single sets
            // - Pair intersections
            // + Triple intersections
            // - Four-way intersections
            // ...
            //
            // So:
            // odd number of coins in subset -> ADD
            // even number of coins in subset -> SUBTRACT
            if (bits % 2 == 1) {
                // Number of multiples of L <= x
                // is x / L
                ans += x / L;
            } else {
                ans -= x / L;
            }
        }
        return ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        // Binary Search on the ANSWER.
        //
        // low  = smallest possible amount
        // high = minCoin * k
        //
        // Why minCoin * k?
        //
        // Suppose minCoin = 3.
        // Using only coin 3, we already have:
        //
        // 3, 6, 9, 12, ... , 3*k
        //
        // So the k-th valid amount can NEVER be
        // greater than 3*k.
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            // count(mid) tells us:
            //
            // "How many DISTINCT valid amounts
            //  are <= mid?"
            //
            // We compare this count with k.
            if (count(mid, coins) >= k) {
                // We already have at least k amounts
                // by the time we reach mid.
                //
                // Therefore answer can be mid
                // OR somewhere smaller.
                high = mid;
            } else {
                // We don't have k amounts yet.
                //
                // Therefore answer must be greater than mid.
                low = mid + 1;
            }
        }
        // low == high
        // This is the smallest amount for which
        // count(amount) >= k.
        return low;
    }
};
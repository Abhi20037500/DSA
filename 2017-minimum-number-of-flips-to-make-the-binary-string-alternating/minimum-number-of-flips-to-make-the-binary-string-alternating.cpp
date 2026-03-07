class Solution {
public:
    int minFlips(string s) {
        int n = s.length(), t1 = 0, t2 = 0;
        
        // Count initial mismatches for both possible alternating patterns
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' == i % 2) t1++;
            else t2++;
        }

        // For even n, rotations don't change the minimum flip count
        if (n % 2 == 0) return min(t1, t2);

        int ans = min(t1, t2), c1 = 0, c2 = 0;
        // For odd n, simulate rotations by shifting the "cut" point
        for (int i = 0; i < n - 1; i++) {
            if (s[i] - '0' == i % 2) c1++;
            else c2++;

            // Use the parity shift property: prefix mismatches with P1 
            // become mismatches with P2 after wrapping around an odd-length string.
            ans = min({ans, (t1 - c1) + c2, (t2 - c2) + c1});
        }
        
        return ans;
    }
};
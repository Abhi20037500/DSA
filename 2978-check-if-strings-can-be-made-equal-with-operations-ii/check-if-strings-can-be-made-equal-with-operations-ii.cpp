class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string s1Even = "", s1Odd = "";
        string s2Even = "", s2Odd = "";
        
        // Extract characters
        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                s1Even += s1[i];
                s2Even += s2[i];
            } else {
                s1Odd += s1[i];
                s2Odd += s2[i];
            }
        }
        
        // Sort and compare
        sort(s1Even.begin(), s1Even.end());
        sort(s2Even.begin(), s2Even.end());
        sort(s1Odd.begin(), s1Odd.end());
        sort(s2Odd.begin(), s2Odd.end());
        
        return (s1Even == s2Even) && (s1Odd == s2Odd);
    }
};
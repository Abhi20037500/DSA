class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int m = 0;
        int palindromicStrStartInd = 0;
        int maxPalindromicLen = 0;
        while(m < n){
            int l = m-1;
            int h = m+1;
            int len = 1;
            while(l >= 0 && h < n){
                if(s[l] != s[h]) break;
                len+=2;
                l--;
                h++;
            }
            if(len > maxPalindromicLen){
                maxPalindromicLen = len;
                palindromicStrStartInd = l+1;
            }
            l = m;
            h = m+1;
            len = 0;
            while(l >= 0 && h < n){
                if(s[l] != s[h]) break;
                len+=2;
                l--;
                h++;
            }
            if(len > maxPalindromicLen){
                maxPalindromicLen = len;
                palindromicStrStartInd = l+1;
            }
            m++;

        } 

        return s.substr(palindromicStrStartInd, maxPalindromicLen);  
    }
};
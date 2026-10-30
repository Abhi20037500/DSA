class Solution {
public:
    vector<string> ans;
    string path = "";
    void rec(int i, string num, map<char, string> mp) {
        if (path.size() == num.size()) {
            ans.push_back(path);
            return;
        }
        for (int j = 0; j <mp[num[i]].size(); j++) {
            path += mp[num[i]][j];
            rec(i + 1, num, mp);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        rec(0,digits,mp);
        return ans;
    }
};
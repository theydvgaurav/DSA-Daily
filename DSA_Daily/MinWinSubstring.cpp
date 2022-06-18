class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t) return s;
        unordered_map<char, int> mp, temp;
        for(int i = 0; i < t.size(); i++) 
            mp[t[i]]++;
        int i = 0, j = 0, ans = INT_MAX, count = mp.size();
        string answer = "";
        while(j < s.size()) {
            if(mp.find(s[j]) != mp.end()) { 
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
            }
            if(count == 0) {
                if(ans > j - i + 1) {
                    ans = j - i + 1;
                    answer = s.substr(i, j - i + 1);
                }
                while(count == 0) {
                    if(mp.find(s[i]) == mp.end()) {
                        i++;
                    if(ans > j - i + 1) {
                        ans = j - i + 1;
                        answer = s.substr(i, j - i + 1);
                    }
                    }
                    else {
                        mp[s[i]]++;
                        if(mp[s[i]] > 0) {
                            i++;
                            count++;
                        }
                        else {
                        i++;
                        if(ans > j - i + 1) {
                            ans = j - i + 1;
                            answer = s.substr(i, j - i + 1);
                        }
                        }
                    }
                }
            }
            j++;
        }
        return answer;
    }
};

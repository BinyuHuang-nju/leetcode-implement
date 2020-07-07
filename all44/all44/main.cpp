#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution1 {  // true, but time exceeds limitation 1416/1809
public:
    bool isMatch(string s, string p) {
        int sl = s.length(), pl = p.length();
        if (sl == 0 && pl == 0)
            return true;
        if (pl == 0)
            return false;
        if (sl == 0) {
            for (int i = 0; i < pl; i++)
                if (p[i] != '*')
                    return false;
            return true;
        }
        return match(s, p, 0, 0, sl, pl);
    }
    bool match(string s, string p, int sb, int pb, int sl, int pl) {
        while (sb < sl && pb < pl) {
            if (s[sb] != p[pb])
                break;
            sb++;
            pb++;
        }
        if (sb == sl && pb == pl)
            return true;
        else if (pb == pl)
            return false;
        else if (sb == sl) {
            for (int i = pb; i < pl; i++)
                if (p[i] != '*')
                    return false;
            return true;
        }
        // 1. a-? : true and continue  2. a-*  choose 3. a-b false and return
        if (p[pb] == '?')
            return match(s, p, sb + 1, pb + 1, sl, pl);
        else if (p[pb] == '*') {
            for (int i = sb; i <= sl; i++)
                if (match(s, p, i, pb + 1, sl, pl))
                    return true;
            return false;
        }
        return false;
    }
};

class Solution2 { // true, but time exceeds limitation 1657/1809
public:
    bool isMatch(string s, string p) {
        int sl = s.length(), pl = p.length();
        if (sl == 0 && pl == 0)
            return true;
        if (pl == 0)
            return false;
        if (sl == 0) {
            for (int i = 0; i < pl; i++)
                if (p[i] != '*')
                    return false;
            return true;
        }
        return match(s, p, 0, 0, sl - 1, pl - 1);
    }
    bool match(string s, string p, int sb, int pb, int sl, int pl) {
        while (sb <= sl && pb <= pl) {
            if (s[sb] != p[pb])
                break;
            sb++;
            pb++;
        }
        while (sb <= sl && pb <= pl) {
            if (s[sl] != p[pl])
                break;
            sl--;
            pl--;
        }
        if (sb > sl&& pb > pl)
            return true;
        else if (pb > pl) {
            if (p[pl] == '*')
                return true;
            return false;
        }
        else if (sb > sl) {
            for (int i = pb; i <= pl; i++)
                if (p[i] != '*')
                    return false;
            return true;
        }
        // 1. a-? : true and continue  2. a-*  choose 3. a-b false and return
        if (p[pb] == '?')
            return match(s, p, sb + 1, pb + 1, sl, pl);
        else if (p[pl] == '?')
            return match(s, p, sb, pb, sl - 1, pl - 1);
        else if (p[pb] != '*' || p[pl] != '*')
            return false;
        else{
            for (int i = sb; i <= sl; i++)
                if (match(s, p, i, pb + 1, sl, pl))
                    return true;
            return false;
        }
        return false;
    }
};

class Solution3 {  //pass
public:
    bool isMatch(string s, string p) {
        int sl = s.length(), pl = p.length();
        if (sl == 0 && pl == 0)
            return true;
        if (pl == 0)
            return false;
        if (sl == 0) {
            for (int i = 0; i < pl; i++)
                if (p[i] != '*')
                    return false;
            return true;
        }
        vector<vector<bool>> match(sl + 1, vector<bool>(pl + 1, false));
        match[0][0] = true;
        int i, j;
        for (i = 1; i < sl + 1; i++)
            match[i][0] = false;
        for (j = 1; j < pl + 1; j++)
            match[0][j] = match[0][j - 1] && (p[j - 1] == '*');
        for (i = 1; i < sl + 1; i++) {
            for (j = 1; j < pl + 1; j++) {
                if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                    match[i][j] = match[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    match[i][j] = match[i - 1][j] || match[i][j - 1];
                }
                else
                    match[i][j] = false;
            }
        }
        return match[sl][pl];
    }

};
int main() {
    string s = "aa", p = "*";
    Solution2 sol2;
    cout << sol2.isMatch(s, p);
    return 0;
}
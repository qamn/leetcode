class Solution {
public:
    bool isNumber(string s) {
        if (s.find_first_not_of(' ') == string::npos) {
            return false;
        }
        s = s.substr(s.find_first_not_of(' '), s.find_last_not_of(' ') - s.find_first_not_of(' ') + 1);
        bool hasDot = false;
        bool hasE = false;
        bool hasNumber = false;
        bool hasNumberAfterE = false;
        for (int i = 0; i < s.length(); i++) {
            char letter = s[i];
            if (letter >= '0' && letter <= '9') {
                hasNumber = true;
                if (hasE) {
                    hasNumberAfterE = true;
                }
            } else if (letter == '.') {
                if (hasDot || hasE) {
                    return false;
                }
                hasDot = true;
            } else if (letter == 'e') {
                if (hasE || !hasNumber) {
                    return false;
                }
                hasE = true;
            } else if (letter == '+' || letter == '-') {
                if (i != 0 && s[i - 1] != 'e') {
                    return false;
                }
            } else {
                return false;
            }
        }
        return (!(hasE ^ hasNumberAfterE)) && hasNumber;
    }
};
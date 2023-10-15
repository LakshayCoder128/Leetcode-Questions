var shortestBeautifulSubstring = function(s, k) {
    let ans = "";
    let len = 0;

    for (let i = 0; i < s.length; i++) {
        let cnt = 0;
        for (let j = i; j < s.length; j++) {
            if (s[j] === '1') {
                cnt++;
                if (cnt === k) {
                    if (len === 0) {
                        len = j - i + 1;
                    } else if (len > j - i + 1) {
                        len = j - i + 1;
                        break;
                    }
                }
            }
        }
    }

    for (let i = 0; i < s.length; i++) {
        let cnt = 0;
        for (let j = i; j < s.length; j++) {
            if (s[j] === '1') {
                cnt++;
                if (cnt === k) {
                    if (len === j - i + 1) {
                        if (!ans) {
                            ans = s.substring(i, i + len);
                        } else {
                            ans = ans.localeCompare(s.substring(i, i + len)) < 0 ? ans : s.substring(i, i + len);
                        }
                    }
                }
            }
        }
    }

    return ans;
};
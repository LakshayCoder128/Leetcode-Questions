/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isScramble = function (s1, s2) {
  let dp = new Map();

  function isScrambleHelper(s1, s2) {
    if (s1 === s2) {
      return true;
    }
    if (dp.has(s1 + s2)) {
      return dp.get(s1 + s2);
    }

    if (s1.split("").sort().join("") !== s2.split("").sort().join("")) {
      dp.set(s1 + s2, false);
      return false;
    }

    for (let i = 1; i < s1.length; i++) {
      if (
        (isScrambleHelper(s1.substring(0, i), s2.substring(0, i)) &&
          isScrambleHelper(s1.substring(i), s2.substring(i))) ||
        (isScrambleHelper(s1.substring(0, i), s2.substring(s1.length - i)) &&
          isScrambleHelper(s1.substring(i), s2.substring(0, s1.length - i)))
      ) {
        dp.set(s1 + s2, true);
        return true;
      }
    }
    dp.set(s1 + s2, false);
    return false;
  }

  return isScrambleHelper(s1, s2);
};

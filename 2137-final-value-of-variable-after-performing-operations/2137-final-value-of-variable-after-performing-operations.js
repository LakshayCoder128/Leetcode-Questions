var finalValueAfterOperations = function(operations) {
    let ans = 0;
    for (let operation of operations) {
        if (operation === "--X" || operation === "X--") {
            ans--;
        } else if (operation === "++X" || operation === "X++") {
            ans++;
        }
    }
    return ans;
};
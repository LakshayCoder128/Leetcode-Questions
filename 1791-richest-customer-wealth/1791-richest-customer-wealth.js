var maximumWealth = function(accounts) {
    let maxWealth = 0;
    for (let i = 0; i < accounts.length; i++) {
        let wealth = accounts[i].reduce((acc, val) => acc + val, 0);
        maxWealth = Math.max(maxWealth, wealth);
    }
    return maxWealth;
};
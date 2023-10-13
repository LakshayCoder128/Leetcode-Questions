var arraySign = function(nums) {
    let countNeg = 0;
    let countZero = 0;

    for (let num of nums) {
        if (num < 0) {
            countNeg--;
        } else if (num === 0) {
            countZero++;
        }
    }

    if (countZero >= 1) {
        return 0;
    }

    return countNeg % 2 === 0 ? 1 : -1;
};
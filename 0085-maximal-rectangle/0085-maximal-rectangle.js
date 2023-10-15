/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalRectangle = function(matrix) {
    
};function largestRectangleArea(heights) {
    const stack = [];
    let maxArea = 0;
    const n = heights.length;
    for (let i = 0; i <= n; i++) {
        while (stack.length > 0 && (i === n || heights[stack[stack.length - 1]] >= heights[i])) {
            const height = heights[stack.pop()];
            const width = stack.length === 0 ? i : i - stack[stack.length - 1] - 1;
            maxArea = Math.max(maxArea, width * height);
        }
        stack.push(i);
    }
    return maxArea;
}

function maximalAreaOfSubMatrixOfAll1(matrix, n, m) {
    let maxArea = 0;
    const height = new Array(m).fill(0);
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (matrix[i][j] === '1') {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }
        const area = largestRectangleArea(height);
        maxArea = Math.max(maxArea, area);
    }
    return maxArea;
}

var maximalRectangle = function(matrix) {
    return maximalAreaOfSubMatrixOfAll1(matrix, matrix.length, matrix[0].

length);
}
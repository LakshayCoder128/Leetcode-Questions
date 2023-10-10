var find132pattern = function(nums) {
    let least = Number.MIN_SAFE_INTEGER;
    const st = [];

    for (let i = nums.length - 1; i >= 0; i--) {
        if (nums[i] < least) return true;
        while (st.length > 0 && nums[i] > st[st.length - 1]) {
            least = st.pop();
        }
        st.push(nums[i]);
    }

    return false;
};
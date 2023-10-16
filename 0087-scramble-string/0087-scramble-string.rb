# @param {String} s1
# @param {String} s2
# @return {Boolean}
def is_scramble(s1, s2)
    dp = {}
    
    def is_scramble_helper(s1, s2, dp)
        return true if s1 == s2
        return dp[[s1, s2]] if dp.include?([s1, s2])
        
        return false if s1.chars.sort.join != s2.chars.sort.join
        
        res = false
        for i in 1...s1.length
            if (is_scramble_helper(s1[0...i], s2[0...i], dp) && is_scramble_helper(s1[i...s1.length], s2[i...s2.length], dp)) || 
               (is_scramble_helper(s1[0...i], s2[s1.length - i...s2.length], dp) && is_scramble_helper(s1[i...s1.length], s2[0...s1.length - i], dp))
                res = true
                break
            end
        end
        
        dp[[s1, s2]] = res
        return res
    end
    
    is_scramble_helper(s1, s2, dp)
end
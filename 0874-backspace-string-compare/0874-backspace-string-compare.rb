def backspace_compare(s, t)
    i, j = s.length - 1, t.length - 1
    skip_s, skip_t = 0, 0

    while i >= 0 || j >= 0
        while i >= 0
            if s[i] == '#'
                skip_s += 1
                i -= 1
            elsif skip_s > 0
                skip_s -= 1
                i -= 1
            else
                break
            end
        end

        while j >= 0
            if t[j] == '#'
                skip_t += 1
                j -= 1
            elsif skip_t > 0
                skip_t -= 1
                j -= 1
            else
                break
            end
        end

        if i >= 0 && j >= 0 && s[i] != t[j]
            return false
        end

        if (i >= 0) != (j >= 0)
            return false
        end

        i -= 1
        j -= 1
    end

    return true
end
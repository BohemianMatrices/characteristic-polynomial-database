characteristic_height := proc(p::polynom, $)
    return max(map(abs, [coeffs(p)]));
end proc:

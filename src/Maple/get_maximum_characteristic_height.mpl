get_maximum_characteristic_height := proc(L, $)
    # L is an Array of polynomials
    return(max(map(characteristic_height, L)));
end proc:
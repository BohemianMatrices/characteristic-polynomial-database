count_determinants := proc(polys, v::name, $)::nonnegint;
    
    return nops(convert(map(coeff, polys, v, 0), set));
    
end proc:
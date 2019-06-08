get_maximum_determinant := proc(polys, v::name, $)::nonnegint;
    
    return max(map(abs, map(coeff, polys, v, 0)));
    
end proc:
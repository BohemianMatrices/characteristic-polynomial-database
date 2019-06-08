count_unimodular := proc(polys, counts, v::name, $)::nonnegint;

    local const_coeff, unimodular_poly_idx;
    
    # Seach for matrices with constant coefficient (i.e. determinant) of 0
    const_coeff := map(abs, map(coeff, polys, v, 0));
    
    unimodular_poly_idx := ListTools:-SearchAll(1, const_coeff);
    
    if unimodular_poly_idx = 0 then
        return 0;
    else
        return(add(counts[[unimodular_poly_idx]]));
    end if;

end proc:

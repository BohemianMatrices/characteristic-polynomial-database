count_singular := proc(polys, counts, v::name, $)::nonnegint;

    local const_coeff, singular_poly_idx;
    
    # Seach for matrices with constant coefficient (i.e. determinant) of 0
    const_coeff := map(coeff, polys, v, 0);
    
    singular_poly_idx := ListTools:-SearchAll(0, const_coeff);
    
    if singular_poly_idx = 0 then
        return 0;
    else
        return(add(counts[[singular_poly_idx]]));
    end if;

end proc:
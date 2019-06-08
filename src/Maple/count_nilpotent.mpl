count_nilpotent := proc(polys, counts, v::name, d::posint, $)::nonnegint;

    local nilpotent_poly_idx;
    
    # Seach for v^d in the array of char polys
    nilpotent_poly_idx := ListTools:-Search(v^d, convert(polys, list));
    
    if nilpotent_poly_idx = 0 then
        return 0;
    else
        return(counts[nilpotent_poly_idx]);
    end if;

end proc:
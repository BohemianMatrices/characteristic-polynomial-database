with(RegularChains):
with(SemiAlgebraicSetTools):

count_eigenvalues := proc(P, {count_real::truefalse := true}, $)
    
    local polys, p, p_factors, num_eigenvalues, R, num_real;
    
    polys := convert(map(make_poly_square_free, P), set):
    p := mul(polys):
    p_factors := map(make_poly_square_free, map(a -> a[1], factors(p)[2])):
    num_eigenvalues := add(map(degree, p_factors)):
    
    if count_real then
        R := PolynomialRing([x]):
        num_real := add(map(RealRootCounting, map(a -> [a], p_factors), [], [], [], R)):
        return (num_eigenvalues, num_real);
    else
        return num_eigenvalues;
    end if;

end proc:

is_non_derogatory := proc(A)
    
    local charPoly, minPoly;
    
    # Compute characteristic and minimal polynomials
    charPoly := expand(LinearAlgebra:-CharacteristicPolynomial(A, 'x'));
    minPoly := expand(LinearAlgebra:-MinimalPolynomial(A, 'x'));
    
    return evalb(abs(normal(charPoly/minPoly)) = 1);
    
end proc:

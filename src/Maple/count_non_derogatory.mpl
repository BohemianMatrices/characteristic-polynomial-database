# ----------------------------------------------------------------------- #
# AUTHOR .... Steven E. Thornton                                          #
# EMAIL ..... sthornt7@uwo.ca                                             #
# UPDATED ... Jul. 21/2018                                                #
#                                                                         #
# This function will count the number of non-derogatory matrices          #
# (charPoly == minPoly) for a class of matrices.                          #
#                                                                         #
# INPUT                                                                   #
#   g .............. Function that takes an integer 1 <= i <= num_matrices#
#                    and returns a unique matrix from the class for each  #
#                    integer.                                             #
#   n .............. Dimension of matrix                                  #
#   num_matrices ... Number of matrices in the class                      #
#                                                                         #
# OUTPUT                                                                  #
#   The number of non-derogatory matrices.                                #
# ----------------------------------------------------------------------- #
count_non_derogatory := proc(g, n, num_matrices::posint, $)::nonnegint;
    
    local count, A, i, charPoly, minPoly;
    
    count := 0;
    
    A := Matrix(n, n);
    
    for i to num_matrices do
        
        # Get the ith matrix
        g(A, i);
        
        if is_non_derogatory(A) then
            count := count + 1;
        end if;
        
    end do;
    
    return count;
    
end proc:

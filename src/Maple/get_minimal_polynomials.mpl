# ----------------------------------------------------------------------- #
# AUTHOR .... Steven E. Thornton                                          #
# EMAIL ..... sthornt7@uwo.ca                                             #
# UPDATED ... Jul. 24/2018                                                #
#                                                                         #
# This function will compute the set of all minimal polynomials a set of  #
# matrices.                                                               #
#                                                                         #
# INPUT                                                                   #
#   g .............. Function that takes an integer 1 <= i <= num_matrices#
#                    and returns a unique matrix from the class for each  #
#                    integer.                                             #
#   n .............. Dimension of matrix                                  #
#   v .............. Variable to use for the minimal polynomials          #
#   num_matrices ... Number of matrices in the class                      #
#                                                                         #
# OPTIONS                                                                 #
#   print_freq ... Default = 10,000                                       #
#                  How often to print a message                           #
#   output ....... Default = "table"                                      #
#                  Either "table" or "set"                                #
#                                                                         #
# OUTPUT                                                                  #
#   If output = "table":                                                  #
#       A table is returned where the keys are the minimal polynomials    #
#       and the values are their densities.                               #
#   If output = "set":                                                    #
#       A set of the minimal polynomials is returned.                     #
# ----------------------------------------------------------------------- #
get_minimal_polynomials := proc(g,
                                n::posint,
                                v::name,
                              num_matrices::posint,
                             {print_freq::posint := 10000,
                              output::string := "table"}, 
                              $)::{table, set};

    local T, i, A, p;

    if output = "table" then

        T := table();
        
        A := Matrix(n, n);
        
        for i to num_matrices do
            if modp(i, print_freq) = 0 then
                printf("%d of %d\n", i, num_matrices);
            end if;
            
            # Get the ith matrix
            g(A, i);
            
            # Compute its minimal polynomial
            p := expand(LinearAlgebra:-MinimalPolynomial(A, v));
            
            if assigned(T[p]) then
                T[p] := T[p] + 1;
            else
                T[p] := 1;
            end if;

        end do;

    elif output = "set" then

        T := {};
        
        A := Matrix(n, n);

        for i to num_matrices do

            if modp(i, print_freq) = 0 then
                printf("%d of %d\n", i, num_matrices);
            end if;
            
            # Get the ith matrix
            g(A, i);
            
            # Compute its minimal polynomial
            p := expand(LinearAlgebra:-MinimalPolynomial(A, v));
            
            T := `union`(T, {p});

        end do;

    else
        error("Incorrect output option type. Expected Table or Set.");
    end if;

    return T;

end proc:


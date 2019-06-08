# ----------------------------------------------------------------------- #
# AUTHOR .... Steven E. Thornton                                          #
# EMAIL ..... sthornt7@uwo.ca                                             #
# UPDATED ... Sept. 24/2018                                               #
#                                                                         #
# This function will count the number of distinct Jordan canonical forms  #
# (JCF), up to permutations of the Jordan blocks, in a family of Bohemian #
# matrices.                                                               #
#                                                                         #
# INPUT                                                                   #
#   g .............. Function that takes an integer 1 <= i <= num_matrices#
#                    and returns a unique matrix from the class for each  #
#                    integer.                                             #
#   n .............. Dimension of matrix                                  #
#   num_matrices ... Number of matrices in the class                      #
#                                                                         #
# OUTPUT                                                                  #
#   The number of JCFs.                                                   #
# ----------------------------------------------------------------------- #
count_jcf := proc(g, n, num_matrices::posint, {print_freq::posint := 10000}, $)::nonnegint;

    local A, ff_table, i, idx_list, F, F_list;

    A := Matrix(n, n);

    # Table to hold Frobenius forms and frequency
    ff_table := table();

    for i to num_matrices do
        if modp(i, print_freq) = 0 then
            printf("%d of %d\n", i, num_matrices);
        end if;


        g(A, i);
        F := LinearAlgebra:-FrobeniusForm(A);
        F_list := convert(F, list);
        ff_table[F_list] := ff_table[F_list]+1;
    end do;

    idx_list := [indices(ff_table, 'nolist')];
    return nops(idx_list);

end proc:

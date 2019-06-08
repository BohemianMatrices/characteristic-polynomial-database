# ---------------------------------------------------------------------------- #
# Compute all minimal polynomials.                                             #
#                                                                              #
# Matrix size .......... nxn                                                   #
# Population ........... {-1, 0}                                               #
# Number of entries .... nxn = n*(n-1)/2                                       #
# Number of matrices ... 2^(n*(n-1)/2)                                         #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/get_minimal_polynomials.mpl"):
read("../../Maple/UH_matrix_at_index_1_Subdiag_0_diag.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 2:
max_matrix_dimension := 7:

# Population of entries
P := [-1, 0]:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    printf("Computing all minimal polynomials of %dx%d matrices\n", n, n);
    num_entries := n*(n-1)/2;
    num_matrices := nops(P)^num_entries;
    g := (A, i) -> UH_matrix_at_index_1_Subdiag_0_diag(A, i, n, P):
    min_poly_table := get_minimal_polynomials(g, n, x, num_matrices, output="table", print_freq=10000):
    
    # Save
    fd := fopen(sprintf("../Data/MinPolys_%dx%d.csv", n, n), WRITE):
    
    for p in [indices(min_poly_table, 'nolist')] do
        count := min_poly_table[p];
        fprintf(fd, "%d", count);
        for d from n to 0 by -1 do
            fprintf(fd, ", %d", coeff(p, x, d));
        end do;
        fprintf(fd, "\n");
    end do;
    fclose(fd):
    
end do:

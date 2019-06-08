# ---------------------------------------------------------------------------- #
# Get the number of matrices for rank 0 through n for nxn matrices             #
#                                                                              #
# Matrix size .......... nxn                                                   #
# Population ........... {-1, 1}                                               #
# Number of entries .... nxn = n*(n+1)/2                                       #
# Number of matrices ... 2^(n*(n+1)/2)                                         #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/get_rank_table.mpl"):
read("../../Maple/UH_matrix_at_index_1_subdiag.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 2:
max_matrix_dimension := 6:

# Population of entries
P := [-1, 1]:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    num_entries := n*(n+1)/2;
    num_matrices := nops(P)^num_entries;
    g := (A, i) -> UH_matrix_at_index_1_subdiag(A, i, n, P):
    rank_table := get_rank_table(g, n, num_matrices):
    
    printf("Matrix Size: %dx%d\n", n, n):
    for i from 0 to n do
        printf("Number of rank %d matrices = %d\n", i, rank_table[i]):
    end do:
    printf("\n"):
    
end do:

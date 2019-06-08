# ---------------------------------------------------------------------------- #
# Count the number of non-derogatory matrices. i.e. the number of matrices     #
# where its characteristic polynomial and minimal polynomial are equal.        #
#                                                                              #
# Matrix size .......... nxn                                                   #
# Population ........... {-1, 0}                                               #
# Number of entries .... nxn = n^2                                             #
# Number of matrices ... 2^(n^2)                                               #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/is_non_derogatory.mpl"):
read("../../../src/Maple/count_non_derogatory.mpl"):
read("../../Maple/matrix_at_index.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 1:
max_matrix_dimension := 5:

# Population of entries
P := [-1, 0]:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    num_entries := n^2;
    num_matrices := nops(P)^num_entries;
    g := (A, i) -> matrix_at_index(A, i, n, P):
    num_non_derogatory := count_non_derogatory(g, n, num_matrices):
    printf("Number of %dx%d non-derogatory matrices = %d\n", n, n, num_non_derogatory):
end do:

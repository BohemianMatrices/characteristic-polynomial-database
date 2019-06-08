# ---------------------------------------------------------------------------- #
# Count the number of distinct Jordan canonical forms (JCF), up to             #
# permutations of the Jordan blocks.                                           #
#                                                                              #
# Main diagonal fixed at 0                                                     #
# Matrix size .......... nxn                                                   #
# Population ........... {-1, 0}                                               #
# Number of entries .... nxn - n = n*(n-1)                                     #
# Number of matrices ... 2^(n*(n-1))                                           #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/count_jcf.mpl"):
read("../../Maple/matrix_at_index_0_diag.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 2:
max_matrix_dimension := 5:

# Population of entries
P := [-1, 0]:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    num_entries := n*(n-1);
    num_matrices := nops(P)^num_entries;
    g := (A, i) -> matrix_at_index_0_diag(A, i, n, P):
    num_jcf := count_jcf(g, n, num_matrices):
    printf("Number of %dx%d JCFs = %d\n", n, n, num_jcf):
end do:

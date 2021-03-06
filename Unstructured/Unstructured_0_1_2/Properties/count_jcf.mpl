# ---------------------------------------------------------------------------- #
# Count the number of distinct Jordan canonical forms (JCF), up to             #
# permutations of the Jordan blocks.                                           #
#                                                                              #
# Matrix size .......... nxn                                                   #
# Population ........... {0, 1, 2}                                             #
# Number of entries .... nxn = n^2                                             #
# Number of matrices ... 3^(n^2)                                               #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/count_jcf.mpl"):
read("../../Maple/matrix_at_index.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 1:
max_matrix_dimension := 4:

# Population of entries
P := [0, 1, 2]:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    num_entries := n^2;
    num_matrices := nops(P)^num_entries;
    g := (A, i) -> matrix_at_index(A, i, n, P):
    num_jcf := count_jcf(g, n, num_matrices, print_freq=100000):
    printf("Number of %dx%d JCFs = %d\n", n, n, num_jcf):
end do:

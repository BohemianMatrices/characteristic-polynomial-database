# ---------------------------------------------------------------------------- #
# Count the number of distinct Jordan canonical forms (JCF), up to             #
# permutations of the Jordan blocks.                                           #
#                                                                              #
# Diagonal entries fixed at 0.                                                 #
# Matrix size .......... nxn                                                   #
# Population ........... {0, 1}                                                #
# Number of entries .... nxn = n*(n-1)/2                                       #
# Number of matrices ... 2^(n*(n-1)/2)                                         #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/count_jcf.mpl"):
read("../../Maple/UH_matrix_at_index_1_Subdiag_0_diag.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 2:
max_matrix_dimension := 7:

# Population of entries
P := [0, 1]:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    num_entries := n*(n-1)/2;
    num_matrices := nops(P)^num_entries;
    g := (A, i) -> UH_matrix_at_index_1_Subdiag_0_diag(A, i, n, P):
    num_jcf := count_jcf(g, n, num_matrices):
    printf("Number of %dx%d JCFs = %d\n", n, n, num_jcf):
end do:

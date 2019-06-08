# ---------------------------------------------------------------------------- #
# Count the number of distinct determinants.                                   #
#                                                                              #
# Matrix size .......... nxn                                                   #
# Population ........... {0, 1}                                                #
# Number of entries .... nxn = n^2                                             #
# Number of matrices ... 2^(n^2)                                               #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/read_poly_data.mpl"):
read("../../../src/Maple/count_determinants.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 1:
max_matrix_dimension := 6:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    poly_filename := sprintf("../Data/CharPolys_%dx%d.csv", n, n):
    polys := read_poly_data(poly_filename, x, keepCount=false):
    num_det := count_determinants(polys, x):
    printf("Number of distinct determinants for %dx%d matrices is %d\n", n, n, num_det):
end do:

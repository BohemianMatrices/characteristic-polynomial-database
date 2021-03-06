# ---------------------------------------------------------------------------- #
# Find the maximum (absolute) determinant.                                     #
#                                                                              #
# Main diagonal fixed at 0                                                     #
# Matrix size .......... nxn                                                   #
# Population ........... {0, 1}                                                #
# Number of entries .... nxn - n = n*(n-1)                                     #
# Number of matrices ... 2^(n*(n-1))                                           #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/read_poly_data.mpl"):
read("../../../src/Maple/get_maximum_determinant.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 2:
max_matrix_dimension := 6:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    poly_filename := sprintf("../Data/CharPolys_%dx%d.csv", n, n):
    polys := read_poly_data(poly_filename, x, keepCount=false):
    max_det := get_maximum_determinant(polys, x):
    printf("Maximum absolute determinant for %dx%d matrices is %d\n", n, n, max_det):
end do:

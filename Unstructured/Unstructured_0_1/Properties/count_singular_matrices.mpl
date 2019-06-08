# ---------------------------------------------------------------------------- #
# Count the number of singluar matrices. i.e. matrices with a determinant of 0 #
#                                                                              #
# Matrix size .......... nxn                                                   #
# Population ........... {0, 1}                                                #
# Number of entries .... nxn = n^2                                             #
# Number of matrices ... 2^(n^2)                                               #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/read_poly_data.mpl"):
read("../../../src/Maple/count_singular.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 1:
max_matrix_dimension := 6:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    poly_filename := sprintf("../Data/CharPolys_%dx%d.csv", n, n):
    polys, counts := read_poly_data(poly_filename, x, keepCount=true):
    num_singular := count_singular(polys, counts, x):
    printf("Number of singular %dx%d matrices is %d\n", n, n, num_singular):
end do:

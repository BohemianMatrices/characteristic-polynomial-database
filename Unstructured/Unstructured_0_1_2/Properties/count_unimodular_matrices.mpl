# ---------------------------------------------------------------------------- #
# Count the number of unimodular matrices. i.e. matrices with a determinant of #
# +/- 1                                                                        #
#                                                                              #
# Matrix size .......... nxn                                                   #
# Population ........... {0, 1, 2}                                             #
# Number of entries .... nxn = n^2                                             #
# Number of matrices ... 3^(n^2)                                               #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/read_poly_data.mpl"):
read("../../../src/Maple/count_unimodular.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 1:
max_matrix_dimension := 5:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    poly_filename := sprintf("../Data/CharPolys_%dx%d.csv", n, n):
    polys, counts := read_poly_data(poly_filename, x, keepCount=true):
    num_unimodular := count_unimodular(polys, counts, x):
    printf("Number of unimodular %dx%d matrices is %d\n", n, n, num_unimodular):
end do:

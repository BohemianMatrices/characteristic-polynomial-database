# ---------------------------------------------------------------------------- #
# Count the number of unimodular matrices. i.e. matrices with a determinant of #
# +/- 1                                                                        #
#                                                                              #
# Main diagonal fixed at 0                                                     #
# Matrix size .......... nxn                                                   #
# Population ........... {-1, 0, 1}                                            #
# Number of entries .... nxn - n = n*(n-1)                                     #
# Number of matrices ... 3^(n*(n-1))                                           #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/read_poly_data.mpl"):
read("../../../src/Maple/count_unimodular.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 2:
max_matrix_dimension := 5:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    poly_filename := sprintf("../Data/CharPolys_%dx%d.csv", n, n):
    polys, counts := read_poly_data(poly_filename, x, keepCount=true):
    num_unimodular := count_unimodular(polys, counts, x):
    printf("Number of unimodular %dx%d matrices is %d\n", n, n, num_unimodular):
end do:

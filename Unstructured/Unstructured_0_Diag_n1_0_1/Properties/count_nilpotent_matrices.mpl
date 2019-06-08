# ---------------------------------------------------------------------------- #
# Count the number of nilpotent matrices. i.e. matrices with characteristic    #
# polynomial x^n.                                                              #
#                                                                              #
# Main diagonal fixed at 0                                                     #
# Matrix size .......... nxn                                                   #
# Population ........... {-1, 0, 1}                                            #
# Number of entries .... nxn - n = n*(n-1)                                     #
# Number of matrices ... 3^(n*(n-1))                                           #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/read_poly_data.mpl"):
read("../../../src/Maple/count_nilpotent.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 2:
max_matrix_dimension := 6:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    poly_filename := sprintf("../Data/CharPolys_%dx%d.csv", n, n):
    polys, counts := read_poly_data(poly_filename, x, keepCount=true):
    num_nilpotent := count_nilpotent(polys, counts, x, n):
    printf("Number of nilpotent %dx%d matrices is %d\n", n, n, num_nilpotent):
end do:

# ---------------------------------------------------------------------------- #
# Count the number of:                                                         #
#   - distinct eigenvalues,                                                    #
#   - distinct real eigenvalues, and                                           #
#   - distinct purely complex eigenvalues.                                     #
#                                                                              #
# Matrix size .......... nxn                                                   #
# Population ........... {0, 1}                                                #
# Number of entries .... nxn = n*(n+1)/2                                       #
# Number of matrices ... 2^(n*(n+1)/2)                                         #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/make_poly_square_free.mpl"):
read("../../../src/Maple/read_poly_data.mpl"):
read("../../../src/Maple/count_eigenvalues.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 2:
max_matrix_dimension := 7:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    poly_filename := sprintf("../Data/CharPolys_%dx%d.csv", n, n):
    polys := read_poly_data(poly_filename, x, keepCount=false):
    (num_eig, num_real_eig) := count_eigenvalues(polys, count_real=true):
    printf("Matrix Size: %dx%d\n", n, n):
    printf("Number of Distinct Eigenvalues = %d\n", num_eig):
    printf("Number of Distinct Real Eigenvalues = %d\n", num_real_eig):
    printf("Number of Distinct Purely Complex Eigenvalues = %d\n", num_eig - num_real_eig):
    printf("\n"):
end do:

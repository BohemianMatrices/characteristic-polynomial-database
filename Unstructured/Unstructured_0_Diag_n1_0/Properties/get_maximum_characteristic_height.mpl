# ---------------------------------------------------------------------------- #
# Get the maximal characteristic height. i.e. the maximal height of the        #
# characteristic polynomials.                                                  #
#                                                                              #
# Main diagonal fixed at 0                                                     #
# Matrix size .......... nxn                                                   #
# Population ........... {-1, 0}                                               #
# Number of entries .... nxn - n = n*(n-1)                                     #
# Number of matrices ... 2^(n*(n-1))                                           #
# ---------------------------------------------------------------------------- #

# Load required functions
read("../../../src/Maple/read_poly_data.mpl"):
read("../../../src/Maple/characteristic_height.mpl"):
read("../../../src/Maple/get_maximum_characteristic_height.mpl"):

# Min/max matrix dimension to run
min_matrix_dimension := 2:
max_matrix_dimension := 6:

# Compute
for n from min_matrix_dimension to max_matrix_dimension do
    poly_filename := sprintf("../Data/CharPolys_%dx%d.csv", n, n):
    polys := read_poly_data(poly_filename, x, keepCount=false):
    max_char_height := get_maximum_characteristic_height(polys):
    printf("Maximum Characteristic Height for %dx%d is %d\n", n, n, max_char_height):
end do:

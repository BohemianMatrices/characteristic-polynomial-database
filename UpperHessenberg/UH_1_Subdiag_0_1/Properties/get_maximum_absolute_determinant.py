import sys
sys.path.append('../../../src/Python/')

from maximum_absolute_determinant import maximum_absolute_determinant

n_min = 2
n_max = 8

for n in range(n_min, n_max+1):
    char_poly_file = '../Data/CharPolys_{}x{}.csv'.format(n, n)
    d_max = maximum_absolute_determinant(char_poly_file, in_memory=False)
    print('Maximum absolute determinant for {}x{} matrices is {}'.format(n, n, d_max))

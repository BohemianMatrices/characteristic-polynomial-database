import sys
sys.path.append('../../../src/Python/')

from maximum_characteristic_height import maximum_characteristic_height

n_min = 2
n_max = 9

for n in range(n_min, n_max+1):
    char_poly_file = '../Data/CharPolys_{}x{}.csv'.format(n, n)
    h_max = maximum_characteristic_height(char_poly_file, in_memory=False)
    print('Maximum characteristic height for {}x{} matrices is {}'.format(n, n, h_max))
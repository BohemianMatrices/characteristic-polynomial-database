import sys
sys.path.append('../../../src/Python/')

from count_determinants import count_determinants

n_min = 2
n_max = 9

for n in range(n_min, n_max+1):
    char_poly_file = '../Data/CharPolys_{}x{}.csv'.format(n, n)
    n_det = count_determinants(char_poly_file, in_memory=False)
    print('Number of distinct determinants for {}x{} matrices is {}'.format(n, n, n_det))

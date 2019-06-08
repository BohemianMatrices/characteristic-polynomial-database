import sys
sys.path.append('../../../src/Python/')

from count_singular import count_singular

n_min = 2
n_max = 8

for n in range(n_min, n_max+1):
    char_poly_file = '../Data/CharPolys_{}x{}.csv'.format(n, n)
    d_max = count_singular(char_poly_file, in_memory=False)
    print('Number of singular {}x{} matrices is {}'.format(n, n, d_max))

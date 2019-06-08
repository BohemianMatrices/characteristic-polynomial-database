import sys
sys.path.append('../../../src/Python/')

from count_nilpotent import count_nilpotent

n_min = 2
n_max = 7

for n in range(n_min, n_max+1):
    char_poly_file = '../Data/CharPolys_{}x{}.csv'.format(n, n)
    n_nil = count_nilpotent(char_poly_file, in_memory=False)
    print('Number of nilpotent {}x{} matrices is {}'.format(n, n, n_nil))

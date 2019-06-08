import numpy as np

def maximum_absolute_determinant(char_poly_file, in_memory=True):

    if in_memory:

        # Load determinants
        dets = np.genfromtxt(char_poly_file, delimiter=',', skip_header=1, dtype=np.int64)[:,-1]

        # Find max
        return np.abs(dets).max()

    else:
        d_max = 0
        with open(char_poly_file) as f:
            next(f) # Skip header
            for line in f:
                c = int(line.split(',')[-1])
                d_max = max(d_max, abs(c))
        return d_max

import numpy as np

def count_singular(char_poly_file, in_memory=True):

    if in_memory:

        # Load characteristic polynomials
        char_polys = np.genfromtxt(char_poly_file, delimiter=',', skip_header=1, dtype=np.int64)
        counts = char_polys[:,0]
        dets = char_polys[:,-1]
        return np.sum(counts[dets == 0])

    else:
        n_singular = 0
        with open(char_poly_file) as f:
            next(f) # Skip header
            for line in f:
                data = line.split(',')
                det = int(data[-1])
                count = int(data[0])
                if det == 0:
                    n_singular += count
        return n_singular

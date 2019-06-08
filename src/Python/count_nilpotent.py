import numpy as np

def count_nilpotent(char_poly_file, in_memory=True):

    if in_memory:

        # Load characteristic polynomials
        char_polys = np.genfromtxt(char_poly_file, delimiter=',', skip_header=1, dtype=np.int64)
        counts = char_polys[:,0]
        char_polys = char_polys[:,2:]  # Characteristic polynomials excluding lc
        nil_rows = np.any(char_polys, axis=1)
        nil_rows = ~nil_rows
        return np.sum(counts[nil_rows])

    else:
        n_nil = 0
        with open(char_poly_file) as f:
            next(f)  # Skip header
            for line in f:
                data = line.split(',')
                char_poly = data[2:]
                char_poly = np.array([int(c) for c in char_poly])
                count = int(data[0])
                if np.sum(np.abs(char_poly)) == 0:
                    n_nil += count
        return n_nil

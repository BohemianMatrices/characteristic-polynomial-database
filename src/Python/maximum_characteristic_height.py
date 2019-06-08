import numpy as np

def maximum_characteristic_height(char_poly_file, in_memory=True):

    if in_memory:

        # Load characteristic polynomials
        char_polys = np.genfromtxt(char_poly_file, delimiter=',', skip_header=1, dtype=np.int64)[:,1:]

        # Compute absolute value of coefficients
        char_polys = np.abs(char_polys)

        # Find max characteristic height
        return char_polys.max()

    else:
        h_max = 0
        with open(char_poly_file) as f:
            next(f) # Skip header
            for line in f:
                c = line.split(',')[1:]
                c = [int(b) for b in c]
                c = np.array(c)
                c = np.abs(c)
                h_max = max(h_max, c.max())
        return h_max

import numpy as np

def count_determinants(char_poly_file, in_memory=True):

    if in_memory:

        # Load determinants
        dets = np.genfromtxt(char_poly_file, delimiter=',', skip_header=1, dtype=np.int64)[:,-1]

        # Count unique values
        return np.unique(dets).shape[0]

    else:
        det_vals = set([])
        with open(char_poly_file) as f:
            next(f) # Skip header
            for line in f:
                d = int(line.split(',')[-1])
                det_vals.add(d)
        return len(det_vals)

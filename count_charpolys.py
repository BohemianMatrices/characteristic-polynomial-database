import glob
import subprocess

def file_len(fname):
    p = subprocess.Popen(['wc', '-l', fname], stdout=subprocess.PIPE,
                                              stderr=subprocess.PIPE)
    result, err = p.communicate()
    if p.returncode != 0:
        raise IOError(err)
    return int(result.strip().split()[0])-1

def count_matrices(filename):
    num_matrices = 0
    with open(filename) as f:
        next(f)  # Skip header
        for line in f:
            num_matrices += int(line.split(',')[0])
    return num_matrices

# Count characteristic polynomials
num_charpolys = 0
for filename in glob.iglob('**/CharPolys_*.csv', recursive=True):
    num_charpolys += file_len(filename)

# Count minimal polynomials
num_minpolys = 0
for filename in glob.iglob('**/MinPolys_*.csv', recursive=True):
    num_minpolys += file_len(filename)

# Count matrices
num_matrices = 0
for filename in glob.iglob('**/CharPolys_*.csv', recursive=True):
    num_matrices += count_matrices(filename)

print("Number of characteristic polynomials = {}".format(num_charpolys))
print("Number of minimal polynomials = {}".format(num_minpolys))
print("Number of matrices = {}".format(num_matrices))

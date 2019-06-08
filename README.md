# Characteristic Polynomial Database

__The Characteristic Polynomial Database should be accessed through the Bohemian Matrices website at [BohemianMatrices.com/cpdb](http://www.bohemianmatrices.com/cpdb/). Data has been removed from the repository.__

This repository contains characteristic polynomials and properties of a variety of families of Bohemian matrices. All source files are available within the repository for reproducing the results. Currently the database contains __1,762,728,065__ characteristic polynomials from __2,366,960,967,336__ matrices.

## Bohemian Families

Below is the summary of the families of Bohemian matrices currently available in the repository. We are actively adding more families and more properties.

### [Unstructured](Unstructured)
Matrices with no structure. For example, 5x5 matrices with entries from the set {-1, 0, +1}.

### [Upper Hessenberg](UpperHessenberg)
Upper Hessenberg matrices with subdiagonal entries fixed at 1.

### [Upper Hessenberg Toeplitz](UpperHessenbergToeplitz)
__Coming Soon!__ Upper Hessenberg matrices with a Toeplitz structure with subdiagonal entries fixed at either -1 or 1.

## Data Files

The files containing characteristic polynomials are CSV files with no header. They all follow the naming convention `CharPolys_nxn.csv` where `n` is the dimension of the matrix they come from. Each row within the CSV files is of the form

`count, c_{n-1}, c_{n-2}, ..., c_0`

where `count` is the number of times the characteristic polynomial appears in the family. `c_{n-1}` to `c_0` are the coefficients of the characteristic polynomial beginning with the degree n-1 coefficient down to the constant coefficient. The leading coefficient (`c_n`) is omitted from the files as this will always be equal to 1.

A Maple function `read_poly_data` has been provided in the [src/Maple](src/Maple) directory for loading the polynomials (and optionally their counts) into Maple. See the header in the file for details on its usage.

## To Do
- Add families
    - Upper Hessenberg Toeplitz
    - Symmetric
    - Upper Triangular
    - Circulant
    - Tridiagonal
    - Toeplitz
    - Hankel
- Convert Maple scripts to SymPy
- Add plots of eigenvalues
- Add random samples of characteristic polynomials for large classes
- Add sequences to OEIS
- ~~Add leading coefficient to characteristic polynomials~~
- Add gcd-free bases sets
- Add sets of invariant factors
- Add properties:
    - Smallest positive integer that is not a determinant (see A013588)
    - Number of different values taken by permanent of matrix (see A087983)
    - Number of matrices such that all eigenvalues are real
    - Number of matrices such that some eigenvalues are strictly complex (see A098148)
    - Number of matrices with det(A) = 1 (see A086264)
    - Number of matrices that are diagonalizable over the complex numbers
    - Number of positive definite matrices
    - Number of matrices with real and positive eigenvalues
    - Number of primitive matrices
    - Number of matrices with 0 permanent
    - Number of idenpotent matrices (eigenvalues are all roots of unity)
    - Number of neutral matrices (matrices whose eigenvalues all have 0 real part)
    - Number of neutral characteristic polynomials (polynomials whose roots all have 0 real part)

### Unstructured
- Compute properties:
    - ~~Number of Distinct Jordan Canonical Forms~~
    - Number of Normal Matrices
    - Number of Rhapsodic Matrices
    - Number of Totally Unimodular Matrices
    - Number of Type I Stable Matrices
    - Number of Type II Stable Matrices

### Upper Hessenberg
- Compute properties:
    - ~~Number of Distinct Jordan Canonical Forms~~
    - Number of Normal Matrices
    - Number of Rhapsodic Matrices
    - Number of Totally Unimodular Matrices
    - Number of Type I Stable Matrices
    - Number of Type II Stable Matrices

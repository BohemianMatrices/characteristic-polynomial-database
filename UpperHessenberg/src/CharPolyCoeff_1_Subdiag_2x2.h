#include <vector>

#ifndef CHARPOLYCOEFF2_H
#define CHARPOLYCOEFF2_H

// 2x2 Matrices
void get2x2_1_subdiag_coeffs(std::vector<int> &c, std::vector<int> &A);
int get2x2_1_subdiag_c0(std::vector<int> &A);
int get2x2_1_subdiag_c1(std::vector<int> &A);

/**************************************************************************
* 2x2 MATRICES
*************************************************************************/
void get2x2_1_subdiag_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get2x2_1_subdiag_c0(A);
    c[1] = get2x2_1_subdiag_c1(A);
}

int get2x2_1_subdiag_c0(std::vector<int> &A) {
    return A[2] * A[0] - A[1];
}

int get2x2_1_subdiag_c1(std::vector<int> &A) {
    return -A[2] - A[0];;
}

#endif

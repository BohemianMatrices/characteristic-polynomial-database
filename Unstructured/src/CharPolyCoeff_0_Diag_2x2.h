#include <vector>

#ifndef CHARPOLYCOEFF2_H
#define CHARPOLYCOEFF2_H

// 2x2 Matrices
void get2x2_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A);
int get2x2_0_diag_c0(std::vector<int> &A);
int get2x2_0_diag_c1(std::vector<int> &A);

/**************************************************************************
* 2x2 MATRICES
*************************************************************************/
void get2x2_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get2x2_0_diag_c0(A);
    c[1] = get2x2_0_diag_c1(A);
}

int get2x2_0_diag_c0(std::vector<int> &A) {
    return -A[1] * A[0];
}

int get2x2_0_diag_c1(std::vector<int> &A) {
    return 0;
}

#endif

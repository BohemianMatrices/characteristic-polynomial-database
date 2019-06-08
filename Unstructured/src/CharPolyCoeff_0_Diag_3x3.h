#include <vector>

#ifndef CHARPOLYCOEFF3_H
#define CHARPOLYCOEFF3_H

// 3x3 Matrices
void get3x3_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A);
int get3x3_0_diag_c0(std::vector<int> &A);
int get3x3_0_diag_c1(std::vector<int> &A);
int get3x3_0_diag_c2(std::vector<int> &A);

/**************************************************************************
* 4x4 MATRICES
*************************************************************************/
void get3x3_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get3x3_0_diag_c0(A);
    c[1] = get3x3_0_diag_c1(A);
    c[2] = get3x3_0_diag_c2(A);
}

int get3x3_0_diag_c0(std::vector<int> &A) {
    return -A[4] * A[0] * A[3] - A[5] * A[2] * A[1];
}

int get3x3_0_diag_c1(std::vector<int> &A) {
    return -A[2] * A[0] - A[4] * A[1] - A[5] * A[3];
}

int get3x3_0_diag_c2(std::vector<int> &A) {
    return 0;
}

#endif

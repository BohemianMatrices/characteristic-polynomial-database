#include <vector>

#ifndef CHARPOLYCOEFF4_H
#define CHARPOLYCOEFF4_H

// 4x4 Matrices
void get4x4_1_subdiag_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A);
int get4x4_1_subdiag_0_diag_c0(std::vector<int> &A);
int get4x4_1_subdiag_0_diag_c1(std::vector<int> &A);
int get4x4_1_subdiag_0_diag_c2(std::vector<int> &A);
int get4x4_1_subdiag_0_diag_c3(std::vector<int> &A);

/**************************************************************************
* 4x4 MATRICES
*************************************************************************/
void get4x4_1_subdiag_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get4x4_1_subdiag_0_diag_c0(A);
    c[1] = get4x4_1_subdiag_0_diag_c1(A);
    c[2] = get4x4_1_subdiag_0_diag_c2(A);
    c[3] = get4x4_1_subdiag_0_diag_c3(A);
}

int get4x4_1_subdiag_0_diag_c0(std::vector<int> &A) {
    return A[5] * A[0] - A[2];
}

int get4x4_1_subdiag_0_diag_c1(std::vector<int> &A) {
    return -A[4] - A[1];
}

int get4x4_1_subdiag_0_diag_c2(std::vector<int> &A) {
    return -A[5] - A[3] - A[0];
}

int get4x4_1_subdiag_0_diag_c3(std::vector<int> &A) {
    return 0;
}

#endif

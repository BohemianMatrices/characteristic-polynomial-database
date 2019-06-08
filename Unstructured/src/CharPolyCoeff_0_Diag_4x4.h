#include <vector>

#ifndef CHARPOLYCOEFF4_H
#define CHARPOLYCOEFF4_H

// 4x4 Matrices
void get4x4_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A);
int get4x4_0_diag_c0(std::vector<int> &A);
int get4x4_0_diag_c1(std::vector<int> &A);
int get4x4_0_diag_c2(std::vector<int> &A);
int get4x4_0_diag_c3(std::vector<int> &A);

/**************************************************************************
* 4x4 MATRICES
*************************************************************************/
void get4x4_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get4x4_0_diag_c0(A);
    c[1] = get4x4_0_diag_c1(A);
    c[2] = get4x4_0_diag_c2(A);
    c[3] = get4x4_0_diag_c3(A);
}

int get4x4_0_diag_c0(std::vector<int> &A) {
    return A[0] * A[3] * A[8] * A[11] - A[0] * A[4] * A[8] * A[9] - A[0] * A[5] * A[6] * A[11] - A[1] * A[3] * A[8] * A[10] + A[1] * A[5] * A[6] * A[10] - A[1] * A[5] * A[7] * A[9] - A[2] * A[3] * A[7] * A[11] - A[2] * A[4] * A[6] * A[10] + A[2] * A[4] * A[7] * A[9];
}

int get4x4_0_diag_c1(std::vector<int> &A) {
    return -A[6] * A[0] * A[4] - A[0] * A[5] * A[9] - A[7] * A[3] * A[1] - A[1] * A[8] * A[9] - A[2] * A[3] * A[10] - A[2] * A[6] * A[11] - A[4] * A[8] * A[10] - A[5] * A[7] * A[11];
}

int get4x4_0_diag_c2(std::vector<int> &A) {
    return -A[0] * A[3] - A[6] * A[1] - A[9] * A[2] - A[7] * A[4] - A[10] * A[5] - A[11] * A[8];
}

int get4x4_0_diag_c3(std::vector<int> &A) {
    return 0;
}

#endif

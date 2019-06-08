#include <vector>

#ifndef CHARPOLYCOEFF4_H
#define CHARPOLYCOEFF4_H

// 4x4 Matrices
void get4x4_1_subdiag_coeffs(std::vector<int> &c, std::vector<int> &A);
int get4x4_1_subdiag_c0(std::vector<int> &A);
int get4x4_1_subdiag_c1(std::vector<int> &A);
int get4x4_1_subdiag_c2(std::vector<int> &A);
int get4x4_1_subdiag_c3(std::vector<int> &A);

/**************************************************************************
* 4x4 MATRICES
*************************************************************************/
void get4x4_1_subdiag_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get4x4_1_subdiag_c0(A);
    c[1] = get4x4_1_subdiag_c1(A);
    c[2] = get4x4_1_subdiag_c2(A);
    c[3] = get4x4_1_subdiag_c3(A);
}

int get4x4_1_subdiag_c0(std::vector<int> &A) {
    return A[0] * A[4] * A[7] * A[9] - A[0] * A[4] * A[8] - A[0] * A[5] * A[9] - A[1] * A[7] * A[9] + A[0] * A[6] + A[1] * A[8] + A[2] * A[9] - A[3];
}

int get4x4_1_subdiag_c1(std::vector<int> &A) {
    return -A[0] * A[4] * A[7] - A[0] * A[4] * A[9] - A[0] * A[7] * A[9] - A[4] * A[7] * A[9] + A[5] * A[0] + A[8] * A[0] + A[1] * A[7] + A[1] * A[9] + A[8] * A[4] + A[5] * A[9] - A[2] - A[6];
}

int get4x4_1_subdiag_c2(std::vector<int> &A) {
    return A[0] * A[4] + A[0] * A[7] + A[0] * A[9] + A[4] * A[7] + A[4] * A[9] + A[7] * A[9] - A[1] - A[5] - A[8];
}

int get4x4_1_subdiag_c3(std::vector<int> &A) {
    return -A[9] - A[7] - A[4] - A[0];
}

#endif

#include <vector>

#ifndef CHARPOLYCOEFF6_H
#define CHARPOLYCOEFF6_H

// 6x6 Matrices
void get6x6_1_subdiag_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A);
int get6x6_1_subdiag_0_diag_c0(std::vector<int> &A);
int get6x6_1_subdiag_0_diag_c1(std::vector<int> &A);
int get6x6_1_subdiag_0_diag_c2(std::vector<int> &A);
int get6x6_1_subdiag_0_diag_c3(std::vector<int> &A);
int get6x6_1_subdiag_0_diag_c4(std::vector<int> &A);
int get6x6_1_subdiag_0_diag_c5(std::vector<int> &A);

/**************************************************************************
* 6x6 MATRICES
*************************************************************************/
void get6x6_1_subdiag_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get6x6_1_subdiag_0_diag_c0(A);
    c[1] = get6x6_1_subdiag_0_diag_c1(A);
    c[2] = get6x6_1_subdiag_0_diag_c2(A);
    c[3] = get6x6_1_subdiag_0_diag_c3(A);
    c[4] = get6x6_1_subdiag_0_diag_c4(A);
    c[5] = get6x6_1_subdiag_0_diag_c5(A);
}

int get6x6_1_subdiag_0_diag_c0(std::vector<int> &A) {
    return -A[0] * A[9] * A[14] + A[0] * A[11] + A[13] * A[1] + A[2] * A[14] - A[4];
}

int get6x6_1_subdiag_0_diag_c1(std::vector<int> &A) {
    return A[10] * A[0] + A[13] * A[0] + A[12] * A[1] + A[14] * A[1] + A[13] * A[5] + A[14] * A[6] - A[3] - A[8];
}

int get6x6_1_subdiag_0_diag_c2(std::vector<int> &A) {
    return A[0] * A[9] + A[0] * A[12] + A[0] * A[14] + A[5] * A[12] + A[5] * A[14] + A[9] * A[14] - A[2] - A[7] - A[11];
}

int get6x6_1_subdiag_0_diag_c3(std::vector<int> &A) {
    return -A[13] - A[10] - A[6] - A[1];
}

int get6x6_1_subdiag_0_diag_c4(std::vector<int> &A) {
    return -A[14] - A[12] - A[9] - A[5] - A[0];
}

int get6x6_1_subdiag_0_diag_c5(std::vector<int> &A) {
    return 0;
}

#endif

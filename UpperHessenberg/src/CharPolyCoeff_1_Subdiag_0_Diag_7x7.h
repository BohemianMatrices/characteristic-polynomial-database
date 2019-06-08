#include <vector>

#ifndef CHARPOLYCOEFF7_H
#define CHARPOLYCOEFF7_H

// 7x7 Matrices
void get7x7_1_subdiag_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A);
int get7x7_1_subdiag_0_diag_c0(std::vector<int> &A);
int get7x7_1_subdiag_0_diag_c1(std::vector<int> &A);
int get7x7_1_subdiag_0_diag_c2(std::vector<int> &A);
int get7x7_1_subdiag_0_diag_c3(std::vector<int> &A);
int get7x7_1_subdiag_0_diag_c4(std::vector<int> &A);
int get7x7_1_subdiag_0_diag_c5(std::vector<int> &A);
int get7x7_1_subdiag_0_diag_c6(std::vector<int> &A);

/**************************************************************************
* 7x7 MATRICES
*************************************************************************/
void get7x7_1_subdiag_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get7x7_1_subdiag_0_diag_c0(A);
    c[1] = get7x7_1_subdiag_0_diag_c1(A);
    c[2] = get7x7_1_subdiag_0_diag_c2(A);
    c[3] = get7x7_1_subdiag_0_diag_c3(A);
    c[4] = get7x7_1_subdiag_0_diag_c4(A);
    c[5] = get7x7_1_subdiag_0_diag_c5(A);
    c[6] = get7x7_1_subdiag_0_diag_c6(A);
}

int get7x7_1_subdiag_0_diag_c0(std::vector<int> &A) {
    return -A[0] * A[11] * A[19] - A[0] * A[12] * A[20] - A[1] * A[15] * A[20] + A[0] * A[14] + A[1] * A[17] + A[2] * A[19] + A[3] * A[20] - A[5];
}

int get7x7_1_subdiag_0_diag_c1(std::vector<int> &A) {
    return -A[0] * A[11] * A[18] - A[0] * A[11] * A[20] - A[0] * A[15] * A[20] - A[6] * A[15] * A[20] + A[0] * A[13] + A[0] * A[17] + A[16] * A[1] + A[19] * A[1] + A[2] * A[18] + A[2] * A[20] + A[6] * A[17] + A[19] * A[7] + A[8] * A[20] - A[4] - A[10];
}

int get7x7_1_subdiag_0_diag_c2(std::vector<int> &A) {
    return A[12] * A[0] + A[16] * A[0] + A[19] * A[0] + A[15] * A[1] + A[18] * A[1] + A[20] * A[1] + A[16] * A[6] + A[19] * A[6] + A[18] * A[7] + A[20] * A[7] + A[19] * A[11] + A[20] * A[12] - A[3] - A[9] - A[14];
}

int get7x7_1_subdiag_0_diag_c3(std::vector<int> &A) {
    return A[11] * A[0] + A[15] * A[0] + A[18] * A[0] + A[20] * A[0] + A[15] * A[6] + A[18] * A[6] + A[20] * A[6] + A[18] * A[11] + A[20] * A[11] + A[20] * A[15] - A[2] - A[8] - A[13] - A[17];
}

int get7x7_1_subdiag_0_diag_c4(std::vector<int> &A) {
    return -A[19] - A[16] - A[12] - A[7] - A[1];
}

int get7x7_1_subdiag_0_diag_c5(std::vector<int> &A) {
    return -A[20] - A[18] - A[15] - A[11] - A[6] - A[0];
}

int get7x7_1_subdiag_0_diag_c6(std::vector<int> &A) {
    return 0;
}

#endif

#include <vector>

#ifndef CHARPOLYCOEFF8_H
#define CHARPOLYCOEFF8_H

// 8x8 Matrices
void get8x8_1_subdiag_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A);
int get8x8_1_subdiag_0_diag_c0(std::vector<int> &A);
int get8x8_1_subdiag_0_diag_c1(std::vector<int> &A);
int get8x8_1_subdiag_0_diag_c2(std::vector<int> &A);
int get8x8_1_subdiag_0_diag_c3(std::vector<int> &A);
int get8x8_1_subdiag_0_diag_c4(std::vector<int> &A);
int get8x8_1_subdiag_0_diag_c5(std::vector<int> &A);
int get8x8_1_subdiag_0_diag_c6(std::vector<int> &A);
int get8x8_1_subdiag_0_diag_c7(std::vector<int> &A);

/**************************************************************************
* 8x8 MATRICES
*************************************************************************/
void get8x8_1_subdiag_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get8x8_1_subdiag_0_diag_c0(A);
    c[1] = get8x8_1_subdiag_0_diag_c1(A);
    c[2] = get8x8_1_subdiag_0_diag_c2(A);
    c[3] = get8x8_1_subdiag_0_diag_c3(A);
    c[4] = get8x8_1_subdiag_0_diag_c4(A);
    c[5] = get8x8_1_subdiag_0_diag_c5(A);
    c[6] = get8x8_1_subdiag_0_diag_c6(A);
    c[7] = get8x8_1_subdiag_0_diag_c7(A);
}

int get8x8_1_subdiag_0_diag_c0(std::vector<int> &A) {
    return A[0] * A[13] * A[22] * A[27] - A[0] * A[13] * A[24] - A[0] * A[14] * A[26] - A[0] * A[15] * A[27] - A[1] * A[18] * A[26] - A[1] * A[19] * A[27] - A[2] * A[22] * A[27] + A[0] * A[17] + A[1] * A[21] + A[2] * A[24] + A[3] * A[26] + A[4] * A[27] - A[6];
}

int get8x8_1_subdiag_0_diag_c1(std::vector<int> &A) {
    return -A[0] * A[13] * A[23] - A[0] * A[13] * A[26] - A[0] * A[14] * A[25] - A[0] * A[14] * A[27] - A[0] * A[18] * A[26] - A[0] * A[19] * A[27] - A[1] * A[18] * A[25] - A[1] * A[18] * A[27] - A[1] * A[22] * A[27] - A[7] * A[18] * A[26] - A[7] * A[19] * A[27] - A[8] * A[22] * A[27] + A[0] * A[16] + A[0] * A[21] + A[1] * A[20] + A[1] * A[24] + A[2] * A[23] + A[2] * A[26] + A[3] * A[25] + A[3] * A[27] + A[7] * A[21] + A[8] * A[24] + A[9] * A[26] + A[10] * A[27] - A[5] - A[12];
}

int get8x8_1_subdiag_0_diag_c2(std::vector<int> &A) {
    return -A[0] * A[13] * A[22] - A[0] * A[13] * A[25] - A[0] * A[13] * A[27] - A[0] * A[18] * A[25] - A[0] * A[18] * A[27] - A[0] * A[22] * A[27] - A[7] * A[18] * A[25] - A[7] * A[18] * A[27] - A[7] * A[22] * A[27] - A[13] * A[22] * A[27] + A[0] * A[15] + A[0] * A[20] + A[0] * A[24] + A[19] * A[1] + A[23] * A[1] + A[26] * A[1] + A[2] * A[22] + A[2] * A[25] + A[2] * A[27] + A[7] * A[20] + A[7] * A[24] + A[23] * A[8] + A[26] * A[8] + A[9] * A[25] + A[9] * A[27] + A[13] * A[24] + A[26] * A[14] + A[15] * A[27] - A[4] - A[11] - A[17];
}

int get8x8_1_subdiag_0_diag_c3(std::vector<int> &A) {
    return A[14] * A[0] + A[19] * A[0] + A[23] * A[0] + A[26] * A[0] + A[18] * A[1] + A[22] * A[1] + A[25] * A[1] + A[27] * A[1] + A[19] * A[7] + A[23] * A[7] + A[26] * A[7] + A[22] * A[8] + A[25] * A[8] + A[27] * A[8] + A[23] * A[13] + A[26] * A[13] + A[25] * A[14] + A[27] * A[14] + A[26] * A[18] + A[27] * A[19] - A[3] - A[10] - A[16] - A[21];
}

int get8x8_1_subdiag_0_diag_c4(std::vector<int> &A) {
    return A[13] * A[0] + A[18] * A[0] + A[22] * A[0] + A[25] * A[0] + A[27] * A[0] + A[18] * A[7] + A[22] * A[7] + A[25] * A[7] + A[27] * A[7] + A[22] * A[13] + A[25] * A[13] + A[27] * A[13] + A[25] * A[18] + A[27] * A[18] + A[27] * A[22] - A[2] - A[9] - A[15] - A[20] - A[24];
}

int get8x8_1_subdiag_0_diag_c5(std::vector<int> &A) {
    return -A[26] - A[23] - A[19] - A[14] - A[8] - A[1];
}

int get8x8_1_subdiag_0_diag_c6(std::vector<int> &A) {
    return -A[27] - A[25] - A[22] - A[18] - A[13] - A[7] - A[0];
}

int get8x8_1_subdiag_0_diag_c7(std::vector<int> &A) {
    return 0;
}

#endif

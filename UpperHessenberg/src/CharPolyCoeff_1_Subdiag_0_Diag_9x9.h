#include <vector>

#ifndef CHARPOLYCOEFF9_H
#define CHARPOLYCOEFF9_H

// 9x9 Matrices
void get9x9_1_subdiag_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A);
int get9x9_1_subdiag_0_diag_c0(std::vector<int> &A);
int get9x9_1_subdiag_0_diag_c1(std::vector<int> &A);
int get9x9_1_subdiag_0_diag_c2(std::vector<int> &A);
int get9x9_1_subdiag_0_diag_c3(std::vector<int> &A);
int get9x9_1_subdiag_0_diag_c4(std::vector<int> &A);
int get9x9_1_subdiag_0_diag_c5(std::vector<int> &A);
int get9x9_1_subdiag_0_diag_c6(std::vector<int> &A);
int get9x9_1_subdiag_0_diag_c7(std::vector<int> &A);
int get9x9_1_subdiag_0_diag_c8(std::vector<int> &A);

/**************************************************************************
* 9x9 MATRICES
*************************************************************************/
void get9x9_1_subdiag_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get9x9_1_subdiag_0_diag_c0(A);
    c[1] = get9x9_1_subdiag_0_diag_c1(A);
    c[2] = get9x9_1_subdiag_0_diag_c2(A);
    c[3] = get9x9_1_subdiag_0_diag_c3(A);
    c[4] = get9x9_1_subdiag_0_diag_c4(A);
    c[5] = get9x9_1_subdiag_0_diag_c5(A);
    c[6] = get9x9_1_subdiag_0_diag_c6(A);
    c[7] = get9x9_1_subdiag_0_diag_c7(A);
    c[8] = get9x9_1_subdiag_0_diag_c8(A);
}

int get9x9_1_subdiag_0_diag_c0(std::vector<int> &A) {
    return  A[0] * A[15] * A[26] * A[34] + A[0] * A[15] * A[27] * A[35] + A[0] * A[16] * A[30] * A[35] + A[1] * A[21] * A[30] * A[35] - A[0] * A[15] * A[29] - A[0] * A[16] * A[32] - A[0] * A[17] * A[34] - A[0] * A[18] * A[35] - A[1] * A[21] * A[32] - A[1] * A[22] * A[34] - A[1] * A[23] * A[35] - A[2] * A[26] * A[34] - A[2] * A[27] * A[35] - A[3] * A[30] * A[35] + A[0] * A[20] + A[1] * A[25] + A[2] * A[29] + A[3] * A[32] + A[4] * A[34] + A[5] * A[35] - A[7];
}

int get9x9_1_subdiag_0_diag_c1(std::vector<int> &A) {
    return A[0] * A[19] + A[1] * A[24] + A[2] * A[28] + A[3] * A[31] + A[4] * A[33] - A[0] * A[15] * A[28] - A[0] * A[16] * A[31] - A[1] * A[21] * A[31] - A[0] * A[17] * A[33] - A[1] * A[22] * A[33] - A[2] * A[26] * A[33] - A[6] - A[14] + A[0] * A[15] * A[26] * A[33] - A[0] * A[16] * A[34] - A[0] * A[22] * A[34] - A[1] * A[21] * A[34] - A[1] * A[26] * A[34] - A[8] * A[22] * A[34] - A[9] * A[26] * A[34] - A[0] * A[17] * A[35] - A[0] * A[23] * A[35] - A[1] * A[22] * A[35] - A[1] * A[27] * A[35] - A[2] * A[26] * A[35] - A[2] * A[30] * A[35] - A[8] * A[23] * A[35] - A[9] * A[27] * A[35] - A[10] * A[30] * A[35] - A[0] * A[15] * A[32] - A[0] * A[21] * A[32] - A[8] * A[21] * A[32] + A[0] * A[25] + A[8] * A[25] + A[1] * A[29] + A[9] * A[29] + A[2] * A[32] + A[10] * A[32] + A[3] * A[34] + A[11] * A[34] + A[4] * A[35] + A[12] * A[35] + A[0] * A[15] * A[26] * A[35] + A[0] * A[15] * A[30] * A[35] + A[0] * A[21] * A[30] * A[35] + A[8] * A[21] * A[30] * A[35];
}

int get9x9_1_subdiag_0_diag_c2(std::vector<int> &A) {
    return -A[0] * A[15] * A[27] - A[0] * A[15] * A[31] - A[0] * A[15] * A[34] - A[0] * A[16] * A[30] - A[0] * A[16] * A[33] - A[0] * A[16] * A[35] - A[0] * A[21] * A[31] - A[0] * A[21] * A[34] - A[0] * A[22] * A[33] - A[0] * A[22] * A[35] - A[0] * A[26] * A[34] - A[0] * A[27] * A[35] - A[1] * A[21] * A[30] - A[1] * A[21] * A[33] - A[1] * A[21] * A[35] - A[1] * A[26] * A[33] - A[1] * A[26] * A[35] - A[1] * A[30] * A[35] - A[8] * A[21] * A[31] - A[8] * A[21] * A[34] - A[8] * A[22] * A[33] - A[8] * A[22] * A[35] - A[8] * A[26] * A[34] - A[8] * A[27] * A[35] - A[9] * A[26] * A[33] - A[9] * A[26] * A[35] - A[9] * A[30] * A[35] - A[15] * A[26] * A[34] - A[15] * A[27] * A[35] - A[16] * A[30] * A[35] + A[0] * A[18] + A[0] * A[24] + A[0] * A[29] + A[1] * A[23] + A[1] * A[28] + A[1] * A[32] + A[2] * A[27] + A[2] * A[31] + A[2] * A[34] + A[3] * A[30] + A[3] * A[33] + A[3] * A[35] + A[8] * A[24] + A[8] * A[29] + A[9] * A[28] + A[9] * A[32] + A[10] * A[31] + A[10] * A[34] + A[11] * A[33] + A[11] * A[35] + A[15] * A[29] + A[16] * A[32] + A[17] * A[34] + A[18] * A[35] - A[5] - A[13] - A[20];
}

int get9x9_1_subdiag_0_diag_c3(std::vector<int> &A) {
    return -A[0] * A[15] * A[26] - A[0] * A[15] * A[30] - A[0] * A[15] * A[33] - A[0] * A[15] * A[35] - A[0] * A[21] * A[30] - A[0] * A[21] * A[33] - A[0] * A[21] * A[35] - A[0] * A[26] * A[33] - A[0] * A[26] * A[35] - A[0] * A[30] * A[35] - A[8] * A[21] * A[30] - A[8] * A[21] * A[33] - A[8] * A[21] * A[35] - A[8] * A[26] * A[33] - A[8] * A[26] * A[35] - A[8] * A[30] * A[35] - A[15] * A[26] * A[33] - A[15] * A[26] * A[35] - A[15] * A[30] * A[35] - A[21] * A[30] * A[35] + A[0] * A[17] + A[0] * A[23] + A[0] * A[28] + A[0] * A[32] + A[22] * A[1] + A[27] * A[1] + A[31] * A[1] + A[34] * A[1] + A[2] * A[26] + A[2] * A[30] + A[2] * A[33] + A[2] * A[35] + A[8] * A[23] + A[8] * A[28] + A[8] * A[32] + A[27] * A[9] + A[31] * A[9] + A[34] * A[9] + A[10] * A[30] + A[10] * A[33] + A[10] * A[35] + A[15] * A[28] + A[15] * A[32] + A[31] * A[16] + A[34] * A[16] + A[17] * A[33] + A[17] * A[35] + A[21] * A[32] + A[34] * A[22] + A[23] * A[35] - A[4] - A[12] - A[19] - A[25];
}

int get9x9_1_subdiag_0_diag_c4(std::vector<int> &A) {
    return A[0] * A[16] + A[0] * A[22] + A[0] * A[27] + A[0] * A[31] + A[0] * A[34] + A[1] * A[21] + A[1] * A[26] + A[1] * A[30] + A[1] * A[33] + A[1] * A[35] + A[8] * A[22] + A[8] * A[27] + A[8] * A[31] + A[8] * A[34] + A[9] * A[26] + A[9] * A[30] + A[9] * A[33] + A[9] * A[35] + A[15] * A[27] + A[15] * A[31] + A[15] * A[34] + A[16] * A[30] + A[16] * A[33] + A[16] * A[35] + A[21] * A[31] + A[21] * A[34] + A[22] * A[33] + A[22] * A[35] + A[26] * A[34] + A[27] * A[35] - A[3] - A[11] - A[18] - A[24] - A[29];
}

int get9x9_1_subdiag_0_diag_c5(std::vector<int> &A) {
    return A[15] * A[0] + A[21] * A[0] + A[26] * A[0] + A[30] * A[0] + A[33] * A[0] + A[35] * A[0] + A[21] * A[8] + A[26] * A[8] + A[30] * A[8] + A[33] * A[8] + A[35] * A[8] + A[26] * A[15] + A[30] * A[15] + A[33] * A[15] + A[35] * A[15] + A[30] * A[21] + A[33] * A[21] + A[35] * A[21] + A[33] * A[26] + A[35] * A[26] + A[35] * A[30] - A[2] - A[10] - A[17] - A[23] - A[28] - A[32];

}

int get9x9_1_subdiag_0_diag_c6(std::vector<int> &A) {
    return -A[34] - A[31] - A[27] - A[22] - A[16] - A[9] - A[1];
}

int get9x9_1_subdiag_0_diag_c7(std::vector<int> &A) {
    return -A[35] - A[33] - A[30] - A[26] - A[21] - A[15] - A[8] - A[0];
}

int get9x9_1_subdiag_0_diag_c8(std::vector<int> &A) {
    return 0;
}

#endif

#include <vector>

#ifndef CHARPOLYCOEFF5_H
#define CHARPOLYCOEFF5_H

// 5x5 Matrices
void get5x5_1_subdiag_coeffs(std::vector<int> &c, std::vector<int> &A);
int get5x5_1_subdiag_c0(std::vector<int> &A);
int get5x5_1_subdiag_c1(std::vector<int> &A);
int get5x5_1_subdiag_c2(std::vector<int> &A);
int get5x5_1_subdiag_c3(std::vector<int> &A);
int get5x5_1_subdiag_c4(std::vector<int> &A);

/**************************************************************************
* 5x5 MATRICES
*************************************************************************/
void get5x5_1_subdiag_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get5x5_1_subdiag_c0(A);
    c[1] = get5x5_1_subdiag_c1(A);
    c[2] = get5x5_1_subdiag_c2(A);
    c[3] = get5x5_1_subdiag_c3(A);
    c[4] = get5x5_1_subdiag_c4(A);
}

int get5x5_1_subdiag_c0(std::vector<int> &A) {
    return -A[0] * A[5] * A[9] * A[12] * A[14] + A[0] * A[5] * A[9] * A[13] + A[0] * A[5] * A[10] * A[14] + A[0] * A[6] * A[12] * A[14] + A[1] * A[9] * A[12] * A[14] - A[0] * A[5] * A[11] - A[0] * A[6] * A[13] - A[0] * A[7] * A[14] - A[1] * A[9] * A[13] - A[1] * A[10] * A[14] - A[2] * A[12] * A[14] + A[0] * A[8] + A[1] * A[11] + A[2] * A[13] + A[3] * A[14] - A[4];
}

int get5x5_1_subdiag_c1(std::vector<int> &A) {
    return A[0] * A[5] * A[9] * A[12] + A[0] * A[5] * A[9] * A[14] + A[0] * A[5] * A[12] * A[14] + A[0] * A[9] * A[12] * A[14] + A[5] * A[9] * A[12] * A[14] - A[0] * A[5] * A[10] - A[0] * A[5] * A[13] - A[0] * A[6] * A[12] - A[0] * A[6] * A[14] - A[0] * A[9] * A[13] - A[0] * A[10] * A[14] - A[1] * A[9] * A[12] - A[1] * A[9] * A[14] - A[1] * A[12] * A[14] - A[5] * A[9] * A[13] - A[5] * A[10] * A[14] - A[6] * A[12] * A[14] + A[0] * A[7] + A[0] * A[11] + A[1] * A[10] + A[1] * A[13] + A[2] * A[12] + A[2] * A[14] + A[5] * A[11] + A[6] * A[13] + A[7] * A[14] - A[3] - A[8];
}

int get5x5_1_subdiag_c2(std::vector<int> &A) {
    return -A[0] * A[5] * A[9] - A[0] * A[5] * A[12] - A[0] * A[5] * A[14] - A[0] * A[9] * A[12] - A[0] * A[9] * A[14] - A[0] * A[12] * A[14] - A[5] * A[9] * A[12] - A[5] * A[9] * A[14] - A[5] * A[12] * A[14] - A[9] * A[12] * A[14] + A[6] * A[0] + A[10] * A[0] + A[13] * A[0] + A[1] * A[9] + A[1] * A[12] + A[1] * A[14] + A[10] * A[5] + A[13] * A[5] + A[6] * A[12] + A[6] * A[14] + A[13] * A[9] + A[10] * A[14] - A[2] - A[7] - A[11];
}

int get5x5_1_subdiag_c3(std::vector<int> &A) {
    return A[5] * A[0] + A[9] * A[0] + A[12] * A[0] + A[14] * A[0] + A[9] * A[5] + A[12] * A[5] + A[14] * A[5] + A[12] * A[9] + A[14] * A[9] + A[14] * A[12] - A[1] - A[6] - A[10] - A[13];
}

int get5x5_1_subdiag_c4(std::vector<int> &A) {
    return -A[14] - A[12] - A[9] - A[5] - A[0];
}

#endif

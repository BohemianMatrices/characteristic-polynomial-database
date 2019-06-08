#include <vector>

#ifndef CHARPOLYCOEFF4_H
#define CHARPOLYCOEFF4_H

// 4x4 Matrices
void get4x4_coeffs(std::vector<int> &c, std::vector<int> &A);
int get4x4_c0(std::vector<int> &A);
int get4x4_c1(std::vector<int> &A);
int get4x4_c2(std::vector<int> &A);
int get4x4_c3(std::vector<int> &A);

/**************************************************************************
* 4x4 MATRICES
*************************************************************************/
void get4x4_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get4x4_c0(A);
    c[1] = get4x4_c1(A);
    c[2] = get4x4_c2(A);
    c[3] = get4x4_c3(A);
}

int get4x4_c0(std::vector<int> &A) {
    return A[0] * A[5] * A[10] * A[15] - A[0] * A[5] * A[11] * A[14] - A[0] * A[6] * A[9] * A[15] + A[0] * A[6] * A[11] * A[13] + A[0] * A[7] * A[9] * A[14] - A[0] * A[7] * A[10] * A[13] - A[1] * A[4] * A[10] * A[15] + A[1] * A[4] * A[11] * A[14] + A[1] * A[6] * A[8] * A[15] - A[1] * A[6] * A[11] * A[12] - A[1] * A[7] * A[8] * A[14] + A[1] * A[7] * A[10] * A[12] + A[2] * A[4] * A[9] * A[15] - A[2] * A[4] * A[11] * A[13] - A[2] * A[5] * A[8] * A[15] + A[2] * A[5] * A[11] * A[12] + A[2] * A[7] * A[8] * A[13] - A[2] * A[7] * A[9] * A[12] - A[3] * A[4] * A[9] * A[14] + A[3] * A[4] * A[10] * A[13] + A[3] * A[5] * A[8] * A[14] - A[3] * A[5] * A[10] * A[12] - A[3] * A[6] * A[8] * A[13] + A[3] * A[6] * A[9] * A[12];
}

int get4x4_c1(std::vector<int> &A) {
    return -A[0] * A[5] * A[10] - A[0] * A[5] * A[15] + A[0] * A[6] * A[9] + A[0] * A[7] * A[13] - A[0] * A[10] * A[15] + A[0] * A[11] * A[14] + A[1] * A[4] * A[10] + A[1] * A[4] * A[15] - A[1] * A[6] * A[8] - A[1] * A[7] * A[12] - A[2] * A[4] * A[9] + A[2] * A[5] * A[8] + A[2] * A[8] * A[15] - A[2] * A[11] * A[12] - A[3] * A[4] * A[13] + A[3] * A[5] * A[12] - A[3] * A[8] * A[14] + A[3] * A[10] * A[12] - A[5] * A[10] * A[15] + A[5] * A[11] * A[14] + A[6] * A[9] * A[15] - A[6] * A[11] * A[13] - A[7] * A[9] * A[14] + A[7] * A[10] * A[13];
}

int get4x4_c2(std::vector<int> &A) {
    return A[0] * A[5] + A[0] * A[10] + A[0] * A[15] - A[1] * A[4] - A[2] * A[8] - A[3] * A[12] + A[5] * A[10] + A[5] * A[15] - A[6] * A[9] - A[7] * A[13] + A[10] * A[15] - A[11] * A[14];
}

int get4x4_c3(std::vector<int> &A) {
    return -A[15] - A[10] - A[5] - A[0];
}

#endif

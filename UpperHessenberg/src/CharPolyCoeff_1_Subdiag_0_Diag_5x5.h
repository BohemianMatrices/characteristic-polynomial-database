#include <vector>

#ifndef CHARPOLYCOEFF5_H
#define CHARPOLYCOEFF5_H

// 5x5 Matrices
void get5x5_1_subdiag_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A);
int get5x5_1_subdiag_0_diag_c0(std::vector<int> &A);
int get5x5_1_subdiag_0_diag_c1(std::vector<int> &A);
int get5x5_1_subdiag_0_diag_c2(std::vector<int> &A);
int get5x5_1_subdiag_0_diag_c3(std::vector<int> &A);
int get5x5_1_subdiag_0_diag_c4(std::vector<int> &A);

/**************************************************************************
* 5x5 MATRICES
*************************************************************************/
void get5x5_1_subdiag_0_diag_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get5x5_1_subdiag_0_diag_c0(A);
    c[1] = get5x5_1_subdiag_0_diag_c1(A);
    c[2] = get5x5_1_subdiag_0_diag_c2(A);
    c[3] = get5x5_1_subdiag_0_diag_c3(A);
    c[4] = get5x5_1_subdiag_0_diag_c4(A);
}

int get5x5_1_subdiag_0_diag_c0(std::vector<int> &A) {
    return A[8] * A[0] + A[9] * A[1] - A[3];
}

int get5x5_1_subdiag_0_diag_c1(std::vector<int> &A) {
    return A[7] * A[0] + A[9] * A[0] + A[9] * A[4] - A[2] - A[6];
}

int get5x5_1_subdiag_0_diag_c2(std::vector<int> &A) {
    return -A[8] - A[5] - A[1];
}

int get5x5_1_subdiag_0_diag_c3(std::vector<int> &A) {
    return -A[9] - A[7] - A[4] - A[0];
}

int get5x5_1_subdiag_0_diag_c4(std::vector<int> &A) {
    return 0;
}

#endif

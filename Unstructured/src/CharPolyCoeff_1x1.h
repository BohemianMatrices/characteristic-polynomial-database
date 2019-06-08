#include <vector>

#ifndef CHARPOLYCOEFF1_H
#define CHARPOLYCOEFF1_H

// 1x1 Matrices
void get1x1_coeffs(std::vector<int> &c, std::vector<int> &A);
int get1x1_c0(std::vector<int> &A);

/**************************************************************************
* 5x5 MATRICES
*************************************************************************/
void get1x1_coeffs(std::vector<int> &c, std::vector<int> &A) {
    c[0] = get1x1_c0(A);
}

int get1x1_c0(std::vector<int> &A) {
    return -A[0];
}

#endif

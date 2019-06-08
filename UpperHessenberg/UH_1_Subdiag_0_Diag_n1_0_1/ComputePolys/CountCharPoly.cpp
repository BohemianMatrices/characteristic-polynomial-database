#include <iostream>
#include <cstdint>
#include <cmath>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>

#include "CharPolyCoeff_1_Subdiag_0_Diag_2x2.h"
#include "CharPolyCoeff_1_Subdiag_0_Diag_3x3.h"
#include "CharPolyCoeff_1_Subdiag_0_Diag_4x4.h"
#include "CharPolyCoeff_1_Subdiag_0_Diag_5x5.h"
#include "CharPolyCoeff_1_Subdiag_0_Diag_6x6.h"
#include "CharPolyCoeff_1_Subdiag_0_Diag_7x7.h"
#include "ComputeCharPolys.h"

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

// Populate the matrix with {-1, 0, 1}
void inline get_entries(uint64_t i, std::vector<int> &A, uint64_t num_entries) {
    
    uint64_t kk = i;
    
    for (uint64_t j = 0; j < num_entries; j++)
    {
        A[j] = kk ? ((kk % 3) - 1) : -1;
        kk /= 3;
    }
}

int main() {
    
    // Matrix Size .... 2x2
    // Entries ........ {-1, 0, 1}
    // Num entries .... 2*1/2 = 1
    // Num matrices ... 3^1 = 3
    std::cout << "------------------------" << std::endl;
    std::cout << "2x2 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get2x2_1_subdiag_0_diag_coeffs, get_entries, 1, 3, 2, "../Data/CharPolys_2x2.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 3x3
    // Entries ........ {-1, 0, 1}
    // Num entries .... 3*2/2 = 3
    // Num matrices ... 3^3 = 27
    std::cout << "------------------------" << std::endl;
    std::cout << "3x3 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get3x3_1_subdiag_0_diag_coeffs, get_entries, 3, 27, 3, "../Data/CharPolys_3x3.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 4x4
    // Entries ........ {-1, 0, 1}
    // Num entries .... 4*3/2 = 6
    // Num matrices ... 3^6 = 729
    std::cout << "------------------------" << std::endl;
    std::cout << "4x4 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get4x4_1_subdiag_0_diag_coeffs, get_entries, 6, 729, 4, "../Data/CharPolys_4x4.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 5x5
    // Entries ........ {-1, 0, 1}
    // Num entries .... 5*4/2 = 10
    // Num matrices ... 3^10 = 59049
    std::cout << "------------------------" << std::endl;
    std::cout << "5x5 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get5x5_1_subdiag_0_diag_coeffs, get_entries, 10, 59049, 5, "../Data/CharPolys_5x5.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 6x6
    // Entries ........ {-1, 0, 1}
    // Num entries .... 6*5/2 = 15
    // Num matrices ... 3^15 = 14348907
    std::cout << "------------------------" << std::endl;
    std::cout << "6x6 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get6x6_1_subdiag_0_diag_coeffs, get_entries, 15, 14348907, 6, "../Data/CharPolys_6x6.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 7x7
    // Entries ........ {-1, 0, 1}
    // Num entries .... 7*6/2 = 21
    // Num matrices ... 3^21 = 10460353203
    std::cout << "------------------------" << std::endl;
    std::cout << "7x7 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get7x7_1_subdiag_0_diag_coeffs, get_entries, 21, 10460353203, 7, "../Data/CharPolys_7x7.csv");
    std::cout << std::endl;
    
}


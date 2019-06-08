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
#include "CharPolyCoeff_1_Subdiag_0_Diag_8x8.h"
#include "CharPolyCoeff_1_Subdiag_0_Diag_9x9.h"
#include "ComputeCharPolys.h"

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

// Populate the matrix with {0, 1}
void inline get_entries(uint64_t i, std::vector<int> &A, uint64_t num_entries) {
    
    uint64_t kk = i;
    
    for (uint64_t j = 0; j < num_entries; j++)
    {
        A[j] = kk % 2;
        kk /= 2;
    }
}

int main() {
    
    // Matrix Size .... 2x2
    // Entries ........ {0, 1}
    // Num entries .... 2*1/2 = 1
    // Num matrices ... 2^1 = 2
    std::cout << "------------------------" << std::endl;
    std::cout << "2x2 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get2x2_1_subdiag_0_diag_coeffs, get_entries, 1, 2, 2, "../Data/CharPolys_2x2.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 3x3
    // Entries ........ {0, 1}
    // Num entries .... 3*2/2 = 3
    // Num matrices ... 2^3 = 8
    std::cout << "------------------------" << std::endl;
    std::cout << "3x3 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get3x3_1_subdiag_0_diag_coeffs, get_entries, 3, 8, 3, "../Data/CharPolys_3x3.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 4x4
    // Entries ........ {0, 1}
    // Num entries .... 4*3/2 = 6
    // Num matrices ... 2^6 = 64
    std::cout << "------------------------" << std::endl;
    std::cout << "4x4 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get4x4_1_subdiag_0_diag_coeffs, get_entries, 6, 64, 4, "../Data/CharPolys_4x4.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 5x5
    // Entries ........ {0, 1}
    // Num entries .... 5*4/2 = 10
    // Num matrices ... 2^10 = 1024
    std::cout << "------------------------" << std::endl;
    std::cout << "5x5 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get5x5_1_subdiag_0_diag_coeffs, get_entries, 10, 1024, 5, "../Data/CharPolys_5x5.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 6x6
    // Entries ........ {0, 1}
    // Num entries .... 6*5/2 = 15
    // Num matrices ... 2^15 = 32768
    std::cout << "------------------------" << std::endl;
    std::cout << "6x6 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get6x6_1_subdiag_0_diag_coeffs, get_entries, 15, 32768, 6, "../Data/CharPolys_6x6.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 7x7
    // Entries ........ {0, 1}
    // Num entries .... 7*6/2 = 21
    // Num matrices ... 2^21 = 2097152
    std::cout << "------------------------" << std::endl;
    std::cout << "7x7 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get7x7_1_subdiag_0_diag_coeffs, get_entries, 21, 2097152, 7, "../Data/CharPolys_7x7.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 8x8
    // Entries ........ {0, 1}
    // Num entries .... 8*7/2 = 28
    // Num matrices ... 2^28 = 268435456
    std::cout << "------------------------" << std::endl;
    std::cout << "8x8 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get8x8_1_subdiag_0_diag_coeffs, get_entries, 28, 268435456, 8, "../Data/CharPolys_8x8.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 9x9
    // Entries ........ {0, 1}
    // Num entries .... 9*8/2 = 36
    // Num matrices ... 2^36 = 68719476736
    std::cout << "------------------------" << std::endl;
    std::cout << "9x9 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get9x9_1_subdiag_0_diag_coeffs, get_entries, 36, 68719476736, 9, "../Data/CharPolys_9x9.csv");
    std::cout << std::endl;
}


#include <iostream>
#include <cstdint>
#include <cmath>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>

#include "CharPolyCoeff_1_Subdiag_2x2.h"
#include "CharPolyCoeff_1_Subdiag_3x3.h"
#include "CharPolyCoeff_1_Subdiag_4x4.h"
#include "CharPolyCoeff_1_Subdiag_5x5.h"
#include "CharPolyCoeff_1_Subdiag_6x6.h"
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
    // Num entries .... 2*3/2 = 3
    // Num matrices ... 3^3 = 27
    std::cout << "------------------------" << std::endl;
    std::cout << "2x2 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get2x2_1_subdiag_coeffs, get_entries, 3, 27, 2, "../Data/CharPolys_2x2.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 3x3
    // Entries ........ {-1, 0, 1}
    // Num entries .... 3*4/2 = 6
    // Num matrices ... 3^6 = 729
    std::cout << "------------------------" << std::endl;
    std::cout << "3x3 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get3x3_1_subdiag_coeffs, get_entries, 6, 729, 3, "../Data/CharPolys_3x3.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 4x4
    // Entries ........ {-1, 0, 1}
    // Num entries .... 4*5/2 = 10
    // Num matrices ... 3^10 = 59049
    std::cout << "------------------------" << std::endl;
    std::cout << "4x4 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get4x4_1_subdiag_coeffs, get_entries, 10, 59049, 4, "../Data/CharPolys_4x4.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 5x5
    // Entries ........ {-1, 0, 1}
    // Num entries .... 5*6/2 = 15
    // Num matrices ... 3^15 = 14348907
    std::cout << "------------------------" << std::endl;
    std::cout << "5x5 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get5x5_1_subdiag_coeffs, get_entries, 15, 14348907, 5, "../Data/CharPolys_5x5.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 6x6
    // Entries ........ {-1, 0, 1}
    // Num entries .... 6*7/2 = 21
    // Num matrices ... 3^21 = 10460353203
    std::cout << "------------------------" << std::endl;
    std::cout << "6x6 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get6x6_1_subdiag_coeffs, get_entries, 21, 10460353203, 6, "../Data/CharPolys_6x6.csv");
    std::cout << std::endl;
    
}


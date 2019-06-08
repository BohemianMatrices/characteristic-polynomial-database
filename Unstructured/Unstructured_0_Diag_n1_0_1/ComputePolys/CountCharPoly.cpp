#include <iostream>
#include <cstdint>
#include <cmath>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>

#include "CharPolyCoeff_0_Diag_2x2.h"
#include "CharPolyCoeff_0_Diag_3x3.h"
#include "CharPolyCoeff_0_Diag_4x4.h"
#include "CharPolyCoeff_0_Diag_5x5.h"
#include "ComputeCharPolys.h"

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

// Populate the matrix with {-1, 0, 1}
void inline get_entries(uint64_t i, std::vector<int> &A, uint64_t num_entries) {
    
    uint64_t kk = i;
    
    // Populate the matrix
    for (uint64_t j = 0; j < num_entries; j++)
    {
        A[j] = kk ? ((kk % 3) - 1) : -1;
        kk /= 3;
    }
    
}


int main() {
    
    // Matrix Size .... 2x2
    // Entries ........ {-1, 0, 1}
    // Num entries .... 2x2 - 2 = 2
    // Num matrices ... 3^(2x2 - 2) = 3^2 = 9
    std::cout << "------------------------" << std::endl;
    std::cout << "2x2 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get2x2_0_diag_coeffs, get_entries, 2, 9, 2, "../Data/CharPolys_2x2.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 3x3
    // Entries ........ {-1, 0, 1}
    // Num entries .... 3x3 - 3 = 6
    // Num matrices ... 3^(3x3 - 3) = 3^6 = 729
    std::cout << "------------------------" << std::endl;
    std::cout << "3x3 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get3x3_0_diag_coeffs, get_entries, 6, 729, 3, "../Data/CharPolys_3x3.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 4x4
    // Entries ........ {-1, 0, 1}
    // Num entries .... 4x4 - 4 = 12
    // Num matrices ... 3^(4x4 - 4) = 3^12 = 531441
    std::cout << "------------------------" << std::endl;
    std::cout << "4x4 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get4x4_0_diag_coeffs, get_entries, 12, 531441, 4, "../Data/CharPolys_4x4.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 5x5
    // Entries ........ {-1, 0, 1}
    // Num entries .... 5x5 - 5 = 20
    // Num matrices ... 3^(5x5 - 5) = 3^20 = 3486784401
    std::cout << "------------------------" << std::endl;
    std::cout << "5x5 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get5x5_0_diag_coeffs, get_entries, 20, 3486784401, 5, "../Data/CharPolys_5x5.csv");
    std::cout << std::endl;
    
}


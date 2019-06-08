#include <iostream>
#include <cstdint>
#include <cmath>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>

#include "CharPolyCoeff_1x1.h"
#include "CharPolyCoeff_2x2.h"
#include "CharPolyCoeff_3x3.h"
#include "CharPolyCoeff_4x4.h"
#include "CharPolyCoeff_5x5.h"
#include "ComputeCharPolys.h"

// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //
// -------------------------------------------------------------------------- //

// Populate the matrix with {0, 1, 2}
void inline get_entries(uint64_t i, std::vector<int> &A, uint64_t num_entries) {

    uint64_t kk = i;

    // Populate the matrix
    for (uint64_t j = 0; j < num_entries; j++)
    {
        A[j] = kk % 3;
        kk /= 3;
    }
    
}


int main() {
    
    // Matrix Size .... 1x1
    // Entries ........ {0, 1, 2}
    // Num entries .... 1x1 = 1
    // Num matrices ... 3^(1x1) = 3^1 = 3
    std::cout << "------------------------" << std::endl;
    std::cout << "1x1 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get1x1_coeffs, get_entries, 1, 3, 1, "../Data/CharPolys_1x1.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 2x2
    // Entries ........ {0, 1, 2}
    // Num entries .... 2x2 = 4
    // Num matrices ... 3^(2x2) = 3^4 = 81
    std::cout << "------------------------" << std::endl;
    std::cout << "2x2 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get2x2_coeffs, get_entries, 4, 81, 2, "../Data/CharPolys_2x2.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 3x3
    // Entries ........ {0, 1, 2}
    // Num entries .... 3x3 = 9
    // Num matrices ... 3^(3x3) = 3^9 = 19683
    std::cout << "------------------------" << std::endl;
    std::cout << "3x3 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get3x3_coeffs, get_entries, 9, 19683, 3, "../Data/CharPolys_3x3.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 4x4
    // Entries ........ {0, 1, 2}
    // Num entries .... 4x4 = 16
    // Num matrices ... 3^(4x4) = 3^16 = 43046721
    std::cout << "------------------------" << std::endl;
    std::cout << "4x4 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get4x4_coeffs, get_entries, 16, 43046721, 4, "../Data/CharPolys_4x4.csv");
    std::cout << std::endl;
    
    // Matrix Size .... 5x5
    // Entries ........ {0, 1, 2}
    // Num entries .... 5x5 = 25
    // Num matrices ... 3^(5x5) = 3^25 = 847288609443
    std::cout << "------------------------" << std::endl;
    std::cout << "5x5 Matrices" << std::endl;
    std::cout << "------------------------" << std::endl;
    compute_char_polys(get5x5_coeffs, get_entries, 25, 847288609443, 5, "../Data/CharPolys_5x5.csv");
    std::cout << std::endl;
    
}


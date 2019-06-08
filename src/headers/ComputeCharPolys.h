#include <iostream>
#include <cstdint>
#include <cmath>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <sys/time.h>

#ifndef COMPUTECHARPOLYS_H
#define COMPUTECHARPOLYS_H

typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

void compute_char_polys(void char_poly_fun(std::vector<int> &c,
                                           std::vector<int> &A),
                        void get_matrix_entries(uint64_t i,
                                                std::vector<int> &A,
                                                uint64_t num_entries),
                        const uint64_t num_entries,
                        const uint64_t num_matrices,
                        const uint64_t matrix_size,
                        const char *file_name) {

    // Start time
    timestamp_t t0 = get_timestamp();

    // Map for storing characteristic polynomials and counts
    std::map<std::vector<int>, uint64_t> charPolys;

    // Array for the coefficients of the characteristic polynomial
    std::vector<int> c(matrix_size);

    // Array for the entries of the matrix
    std::vector<int> A(num_entries);

    // Used in loops
    uint64_t j;

    // Iterate through all matrices
    for (uint64_t k = 0; k < num_matrices; k++)
    {

        // Print a message every 100 million matrices
        if(k % 100000000 == 0 && k > 0)
        {
            if (k < 1000000000) {
                printf("\n%llu00 million\n", k/100000000);
            } else {
                printf("\n%.1f billion\n", k/1000000000.0);
            }
            printf("# of char polys: %lu\n", charPolys.size());
        }

        // Populate the matrix
        get_matrix_entries(k, A, num_entries);

        // Get the coefficients of the characteristic polynomial
        char_poly_fun(c, A);

        // Update the map of counts
        if (charPolys.find(c) == charPolys.end()) {
          charPolys[c] = 1;
        } else {
          charPolys[c]++;
        }

    }

    // Save the characteristic polynomials
    printf("Writing characteristic polynomials To %s\n", file_name);
    FILE * pFile;
    pFile = fopen(file_name, "w");

    // Print the header
    fprintf(pFile, "count");

    // Print the leading coefficient
    fprintf(pFile, ",c_%llu", matrix_size);

    // Print the coefficients
    for (j = matrix_size; j-- > 0; ) {
        fprintf(pFile, ",c_%llu", j);
    }
    fprintf(pFile, "\n");

    // Write to file
    for (auto const& x : charPolys)
    {
        // Print count to file
        fprintf(pFile, "%llu", x.second);

        // Print the leading coefficient
        fprintf(pFile, ",1");

        // Print the coefficients
        for (j = matrix_size; j-- > 0; ) {
            fprintf(pFile, ",%d", x.first[j]);
        }

        fprintf(pFile, "\n");

    }

    fclose(pFile);

    // End time
    timestamp_t t1 = get_timestamp();

    // Total time in seconds
    double secs = (t1 - t0) / 1000000.0L;

    std::cout << "Execution Time = " << secs << "s" << std::endl;

}

#endif

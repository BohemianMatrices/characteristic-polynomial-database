# ----------------------------------------------------------------------- #
# AUTHOR .... Steven E. Thornton                                          #
# EMAIL ..... sthornt7@uwo.ca                                             #
# UPDATED ...  Oct. 27/2018                                               #
#                                                                         #
# Read in polynomials from a text file where each line of the file is of  #
# the form:                                                               #
#   count, c_n, ..., c_1, c_0                                             #
# where count is the number of times the polynomial in the current line   #
# appears. c_0, c_1, ..., c_n are the coefficients of the polynomial      #
#where the polynomial takes the form:                                     #
#   c0 + c1x + c2x^2 + ... + cn x^n                                       #
#                                                                         #
# INPUT                                                                   #
#   filename ..... Name (and location) of file.                           #
#   v ............ Variable for the output polynomials.                   #
#   keepCount .... Optional, false by default.                            #
#                  See output.                                            #
#   delimiter2 ... Optional, "," by default.                              #
#                  Character that separates the entries in the file.      #
#                                                                         #
# OUTPUT                                                                  #
#   If keepCount = true:                                                  #
#       Two arrays, the first contains the polynomials and the second     #
#       contains their counts.                                            #
#   If keepCount = false:                                                 #
#       An array of polynomials                                           #
#                                                                         #
# ASSUMPTIONS                                                             #
#   - The values in the file are all assumed to be integers.              #
# ----------------------------------------------------------------------- #
read_poly_data := proc(filename::string,
                     v::symbol,
                    {keepCount::truefalse := false,
                     delimiter2::string := ","}, $)

    local data::Matrix,
      numPolys::posint,
             n::posint,
   outputPolys::Array,
         count::Array,
             i::posint,
             j::posint,
             p::polynom;

    # Read the file into a matrix
    data := ImportMatrix(filename, 'delimiter' = delimiter2,
                                   'datatype' = integer,
                                   'skiplines'=1);

    # Number of polynomials
    numPolys := LinearAlgebra:-RowDimension(data);

    # Degree of the polynomials
    n := LinearAlgebra:-ColumnDimension(data) - 2;

    # Array for polynomial output
    outputPolys := Array(1..numPolys, 'datatype'=polynom(integer, v));

    # Array for count output
    if keepCount then
        count := Array(1..numPolys, 'datatype'=nonnegint);
    end if;

    for i to numPolys do
        p := 0;
        for j from n by -1 to 0 do
            p := p + v^j*data[i, n-j+2]
        end do;

        outputPolys[i] := p;

        if keepCount then
            count[i] := data[i,1];
        end if:

    end do;

    if keepCount then
        return outputPolys, count;
    else
        return outputPolys;
    end if;

end proc:

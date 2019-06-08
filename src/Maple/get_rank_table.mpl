get_rank_table := proc(g,
                       n::posint,
                       num_matrices::posint,
                       {print_freq::posint := 10000},
                       $)::table;
    
    local rank_array, A, i, r, rank_table;
    
    # Initialize array for ranks
    rank_array := Array(0..n, fill=0);
    
    # Initialize matrix
    A := Matrix(n, n);
    
    for i to num_matrices do
        # Get the ith matrix
        g(A, i);
        
        # Compute rank
        r := LinearAlgebra:-Rank(A);
        
        # Update array
        rank_array[r] := rank_array[r] + 1;
        
    end do;
    
    rank_table := convert(rank_array, table);
    for i from 0 to n do
        if not i in {op(ListTools:-Flatten([indices(rank_table)]))} then
            rank_table[i] := 0;
        end if;
    end do;
    
    return rank_table;
    
end proc:
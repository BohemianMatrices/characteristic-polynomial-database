# ---------------------------------------------------------------------------- #
# Fill a matrix with entries from a set/list.
# Main diagonal fixed at 0.
# Mapping from i to A
# Inplace
# ---------------------------------------------------------------------------- #
matrix_at_index_0_diag := proc(A, i, n, S, $)
    local cc, r, c, nn;
    cc := i;
    nn := nops(S);
    for r to n do
        for c to n do
            if r <> c then
                A[r, c] := S[irem(cc, nn)+1];
                cc := iquo(cc, nn);
            end if;
        end do;
    end do;
    return NULL;
end proc;

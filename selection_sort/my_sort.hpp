// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful


template<class CONT>
void my_selection_sort( CONT begin,CONT end) {
    for (auto i = begin; i != end; ++i) {
        auto min = i;
        for (auto j = i; j != end; ++j) {
            if (*j < *min) {
                min = j;
            }
        }
        auto tmp = *i;
        *i = *min;
        *min = tmp;
    }
}

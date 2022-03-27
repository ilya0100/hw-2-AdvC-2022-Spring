#include "utils.hpp"


bool arraycmp(const Array &l, const Array &r) {
    if (l.size != r.size) {
        return false;
    }
    
    for (size_t i = 0; i < l.size; ++i) {
        if (l.data[i] != r.data[i]) {
            return false;
        }
    }
    
    return true;
}

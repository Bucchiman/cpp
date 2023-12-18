/*
 * FileName:     operations
 * Author: 8ucchiman
 * CreatedDate:  2023-02-28 19:43:47 +0900
 * LastModified: 2023-02-28 20:04:16 +0900
 * Reference: 8ucchiman.jp
 */

#include <iostream>
#include <stdlib.h>


bool compare_and_swap(uint64_t* p, uint64_t val, uint64_t newval) {
    /*
     * compare and swap function
     */
    if (*p != val) {
        return false;
    }
    *p = newval;
    return true;
}

bool cas(uint64_t* p, uint64_t val, uint64_t newval) {
    return __sync_bool_compare_and_swap(p, val, newval);
}

bool test_and_set(bool* p) {
    if (*p) {
        return true;
    }
    else {
        *p = true;
        return false;
    }
}

bool tas(bool* p) {
    return __sync_lock_test_and_set(p, 1);
}

bool tas_release(volatile bool* p) {
    return __sync_lock_release(p);
}

int main(void){
    uint64_t* sample;
    uint64_t value;
    sample = (uint64_t*) malloc(sizeof(uint64_t));
    std::cin >> *sample;
    std::cin >> value;
    cas(sample, value, 17);
    std::cout << *sample;
    free(sample);
    return 0;
}

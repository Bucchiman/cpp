/*
 * FileName:     hello_world
 * Author: 8ucchiman
 * CreatedDate:  2023-03-28 10:21:45 +0900
 * LastModified: 2023-03-28 10:22:48 +0900
 * Reference:    https://www.cc.u-tokyo.ac.jp/events/lectures/03/kosyu-openmp_c.pdf
 */

#include <iostream>
#include <omp.h>

int main(void){
    #pragma omp parallel
    {
        std::cout << "Hello World!" << std::endl;
    }
    return 0;
}

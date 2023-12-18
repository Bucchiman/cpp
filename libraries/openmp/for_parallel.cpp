/*
 * FileName:     for_parallel
 * Author:       8ucchiman
 * CreatedDate:  2023-05-19 16:33:33
 * LastModified: 2023-03-28 10:34:14 +0900
 * Reference:    https://www.cc.u-tokyo.ac.jp/events/lectures/03/kosyu-openmp_c.pdf
 * Description:  ---
 */


#include <iostream>
#include <omp.h>


int main(int argc, char* argv[]){
    int i, a[100];
    #pragma omp parallel
    {
        #pragma omp for
        for(i=0; i<100; i++) {
            a[i] = 0;
        }
    }
}

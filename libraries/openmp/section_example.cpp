/*
 * FileName:     section_example
 * Author:       8ucchiman
 * CreatedDate:  2023-05-19 16:38:57
 * LastModified: 2023-03-28 10:34:14 +0900
 * Reference:    https://www.cc.u-tokyo.ac.jp/events/lectures/03/kosyu-openmp_c.pdf
 * Description:  ---
 */


#include <stdio.h>
#include <iostream>


int main(int argc, char* argv[]){
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            printf("Hello 1\n");

            #pragma omp section
            printf("Hello 2\n");

            #pragma omp section
            {
                printf("Hello 3\n");
                printf("Hello 3\n");
            }
        }
    }
    return 0;
}


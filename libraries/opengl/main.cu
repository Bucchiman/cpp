/*
 * FileName:     main
 * Author:       8ucchiman
 * CreatedDate:  2023-05-17 16:45:17
 * LastModified: 2023-02-26 13:30:39 +0900
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


#include <stdio.h>
#include <GL/glut.h>
//#include "glew.h"

#define MACRO
#define cudaCheckErrors(msg) \
    do { \
        cudaError_t __err = cudaGetLastError(); \
        if (__err != cudaSuccess) { \
            fprintf(stderr, "Fatal error: %s (%s at %s: %d)\n", \
                    msg, cudaGetErrorString(__err), \
                    __FILE__, __LINE__); \
            fprintf(stderr, "*** FAILED - ABORTING\n"); \
            exit(1); \
        } \
    } while (0)

__global__ void hoge(void *arguments) {

}

void display(void) {
}


#ifdef MACRO
int main(int argc, char* argv[]){
    glutInit();
    //glewCreate
    return 0;
}
#endif


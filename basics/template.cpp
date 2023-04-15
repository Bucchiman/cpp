/*
 * FileName:     template
 * Author: 8ucchiman
 * CreatedDate:  2023-03-23 22:39:59 +0900
 * LastModified: 2023-03-23 22:42:50 +0900
 * Reference: https://qiita.com/hal1437/items/b6deb22a88c76eeaf90c
 */

#include <iostream>


template<typename T>
T Add(T a, T b) {
    return a+b;
}

int main(void){
    std::cout << Add(2, 4) << std::endl;
    return 0;
}

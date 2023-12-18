/*
 * FileName:     myclass
 * Author: 8ucchiman
 * CreatedDate:  2023-03-17 10:38:02 +0900
 * LastModified: 2023-03-17 10:43:15 +0900
 * Reference: 8ucchiman.jp
 */

#include <iostream>


class Bucchiman {
    private:
        std::string name;
    public:
        Bucchiman(std::string s) {
            name = s;
        }

    void say_hello() {
        std::cout << "Hello, I'm 8ucchiman" << std::endl;
    }
};

int main(void){
    Bucchiman bucchiman("bucchiman");
    bucchiman.say_hello();
    return 0;
}



#include<iostream>
int main(){
    for(int y = 0; y < 16; y++){
        for(int x = 0; x < 32; x++){
            std::cout<<((x/4 + y/2) % 2 == 0 ? '#': ' ');
        }
        std::cout<<std::endl;
    }
    return 0;
}
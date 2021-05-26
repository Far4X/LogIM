#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "SpyPointerGroup.h"
#include "SpyPointer.h"

int main(){
    int a = 0;
    int b;
    std::cout << "OUIIIIII" << std::endl;
    std::ofstream flux("Logs.LogIM");
    SpyPointerGroup mainGroup(flux, 8);
    SpyPointer a_surveillor(&a, std::string("A_surv"), mainGroup);
    SpyPointer b_surveillor(&b, std::string("B_surv"), mainGroup);
    for (int i(0); i < 15; i++){
        a++;
        b = a*a;
        mainGroup.makeLog();
    }
    return 0;
}
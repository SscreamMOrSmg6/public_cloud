#include <iostream>
int main() {
    double rayon;
    double surface;
    const double pi = 3.14;
    std::cin >> rayon;
    surface = rayon * rayon * pi;
    std::cout << "enter the rayon in input tab"  << std::endl;
    std::cout << "the surface is: " << surface << std::endl;
    return 0;
    // USE https://ide.judge0.com/ !!!
}
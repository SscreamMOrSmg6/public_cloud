#include <iostream>
#include <cmath>
#include <cstring>
#include <chrono>
#include <thread>

int main() {
    float A = 0, B = 0;
    float i, j;
    int k;
    const int width = 80;
    const int height = 22;

    float z[1760];
    char b[1760];

    std::cout << "\x1b[2J"; // Clear screen

    while (true) {
        std::memset(b, 32, 1760); // Fill with spaces
        std::memset(z, 0, 7040);  // Depth buffer

        for (j = 0; j < 6.28; j += 0.07) {
            for (i = 0; i < 6.28; i += 0.02) {
                float c = std::sin(i);
                float d = std::cos(j);
                float e = std::sin(A);
                float f = std::sin(j);
                float g = std::cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = std::cos(i);
                float m = std::cos(B);
                float n = std::sin(B);
                float t = c * h * g - f * e;

                int x = (int)(width / 2 + 30 * D * (l * h * m - t * n));
                int y = (int)(height / 2 + 15 * D * (l * h * n + t * m));
                int o = x + width * y;
                int N = (int)(8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n));

                if (height > y && y > 0 && x > 0 && width > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        std::cout << "\x1b[H"; // Reset cursor
        for (k = 0; k < 1760; k++) {
            std::cout << (k % width ? b[k] : '\n');
        }

        A += 0.04;
        B += 0.08;
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }

    return 0;
}

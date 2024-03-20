#include <iostream>
#include <sys/utsname.h>

int main() {
    utsname u{};
    if (uname(&u) != 0) {
        return 1;
    }
    std::cout << "Docker container running correctly: " << u.nodename << std::endl;
    return 0;
}
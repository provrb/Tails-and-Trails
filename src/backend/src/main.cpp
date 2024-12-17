#include <pybind11/pybind11.h>
#include <iostream>

#ifdef DEPLOY

// when building dll

PYBIND11_MODULE(my_module, m) {
    // link modules for python
}

#elif defined(TEST)

// when i need a console to print
// easier to debug and run

int main() {
    
}

#endif

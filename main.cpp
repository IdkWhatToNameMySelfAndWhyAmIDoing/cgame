#include "first_app.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

int main()
{
    lve::FirstApp app{};
    try
    {
        app.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    
    std::cout << "Sucessfull" << std::endl;
    return EXIT_SUCCESS;
}
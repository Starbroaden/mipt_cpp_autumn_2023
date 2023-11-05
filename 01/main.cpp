#include "HW1.hpp"

int main()
{
    std::string text1{"Ashcraft"};
    std::string text2{"Ashcroft"};  
    std::string upg1 = convertTextToSound(text1);
    std::string upg2 = convertTextToSound(text2);
    std::cout << upg1 << std::endl << upg2;
    assert(isEqual(text1, text2));
    return 0;
}
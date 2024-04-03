#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>

#include "./cksystem/cksystem.hpp"

int main()
{
    
    cksystem::io ioHandler;

    std::string usrfile;

    std::string usr_result = ioHandler.execute("");
    std::string ref_result = ioHandler.execute("");

    if(!(usr_result.empty()) || !(ref_result.empty()))
    {
        if(usr_result == ref_result)
        {
            std::cout << usrfile << "\t\t<====================> [Pass]\n";
        }
    }

    return 0;
}
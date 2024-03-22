#ifndef CKHW_HPP_INCLUDED
#define CKHW_HPP_INCLUDED

    #include <iostream>
    #include <stdexcept>
    #include <string>

    #if __cplusplus > 199711L
        #include <cstdio>
        #include <memory>
        #include <array>
    #else
        #include <stdio.h>
    #endif

    namespace ckhw{
        class sys{

            public:
                std::string read_exec(const char* cmd);
        };
    }
#endif
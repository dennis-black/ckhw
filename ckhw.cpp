#include "ckhw.hpp"


// Method Found by marsh(Feb 19 2024) & waqas(Jan 26 2005)
// Link: "https://stackoverflow.com/questions/478898/how-do-i-execute-a-command-and-get-the-output-of-the-command-within-c-using-po"

#if __cplusplus > 199711L

    std::string ckhw::sys::read_exec(const char* cmd) {

        std::array<char, 128> buf_;
        std::string res_;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);

        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buf_.data(), static_cast<int>(buf_.size()), pipe.get()) != nullptr) {
            res_ += buf_.data();
        }

        return res_;
    }
#else

    std::string ckhw::sys::read_exec(const char* cmd){
        
        char buffer[128];
        std::string res_ = "";    
        
        FILE* Pipe = popen(cmd, "r");
        if (!Pipe) throw std::runtime_error("popen() failed!");
        
        try {

            while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
                result += buffer;
            }
        } catch (...) {
      
            pclose(Pipe);
            throw;
        }
        pclose(Pipe);

        return result;
    }
#endif
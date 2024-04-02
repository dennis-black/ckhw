#include "ckhw.hpp"

// ckhw::ckSystem::ioexecute() Method Found by marsh(Feb 19 2024) & waqas(Jan 26 2005)
// Link: "https://stackoverflow.com/questions/478898/how-do-i-execute-a-command-and-get-the-output-of-the-command-within-c-using-po"

#if __cplusplus > 199711L

    std::string cksystem::io::ioexecute(const char* command_)
    {
        std::array<char, 128> buf_;
        std::string res_;
        std::unique_ptr<FILE, decltype(&pclose)> pipe_(popen(command_, "r"), pclose);

        if(!pipe_)
        {
            throw std::runtime_error("popen() failed!");
        }
        
        while(fgets(buf_.data(), static_cast<int>(buf_.size()), pipe_.get()) != nullptr)
        {
            res_ += buf_.data();
        }

        return res_;
    }
#else

    std::string cksystem::io::ioexecute(const char* command_)
    {    
        char buf_[128];
        std::string res_ = "";    
        
        FILE* pipe_ = popen(command_, "r");
        if (!pipe_) throw std::runtime_error("popen() failed!");
        
        try{
        
            while (fgets(buf_, sizeof(buf_), pipe_) != NULL)
            {
                res_ += buf_;
            }
        }catch (...){

            pclose(pipe_);
            throw;
        }
        pclose(pipe_);

        return res_;
    }
#endif


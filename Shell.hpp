#pragma once
#include "Circuit.hpp"
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <csignal>
#include <memory>
#include <functional>

namespace nts
{
    class Shell
    {
        private :
            std::shared_ptr<nts::Circuit> circuit;
    
            void executeCommand(const std::string &command);
            void runLoop();
            void setInputValue(const std::string &command);
        public :
            Shell(std::shared_ptr<nts::Circuit> circuit);
            ~Shell();
            void run();
            static class Error : public std::exception {
                private:
                    std::string message;
                public:
                    Error(const std::string &message) {
                        this->message = std::string(message);
                    };
                    ~Error() {};
                    const char *what() const noexcept override;
            } err;
    };
    extern volatile sig_atomic_t stop_loop;
}

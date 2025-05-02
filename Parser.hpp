#pragma once

#include "Circuit.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>

namespace nts
{
    namespace parse
    {
        enum State
        {
            null,
            chipsets,
            links
        };
    
        class Parser
        {
            private :
                std::ifstream _stream;
                std::stringstream _line;
                int _argNumber = 0;
                parse::State _parseState = null;
            public :
                Parser();
                ~Parser();
                void openFile(const std::string &filepath);
                void getNextLine();
                std::string parseLine();
                bool isNewSection();
                parse::State getParseState() const {
                    return this->_parseState;
                }
                void buildCircuit(std::shared_ptr<nts::Circuit> &circuit);
                static class Error : public std::exception
                {
                    private :
                        std::string message;
                    public :
                    Error(const std::string &message) {
                        this->message = std::string(message);
                    }
                    ~Error() {};
                    const char *what() const noexcept override;
                } err;
        };
    }
}


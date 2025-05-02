#pragma once
#include "IComponent.hpp"
#include "AComponent.hpp"
#include "AndComponent.hpp"
#include "ClockComponent.hpp"
#include "FalseComponent.hpp"
#include "InputComponent.hpp"
#include "NotComponent.hpp"
#include "OrComponent.hpp"
#include "OutputComponent.hpp"
#include "TrueComponent.hpp"
#include "XorComponent.hpp"
#include "Component4001.hpp"
#include "Component4011.hpp"
#include "Component4071.hpp"
#include "Component4030.hpp"
#include "Component4069.hpp"
#include "Component4081.hpp"
#include "Component4008.hpp"

#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <sstream>

namespace nts
{
    class Factory
    {
        public:
        Factory();
        ~Factory();
        std::shared_ptr<nts::IComponent> create(std::string &type, std::string &name);

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
}
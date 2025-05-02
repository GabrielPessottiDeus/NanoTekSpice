#pragma once
#include "AComponent.hpp"

namespace nts
{
    class InputComponent : public AComponent
    {
        public:
        nts::Tristate _tmp;
        InputComponent(const std::string &name);
        ~InputComponent();
    
        void simulate(size_t tick);
        nts::Tristate compute(std::size_t pin);
        bool setInputValue(nts::Tristate value);
    };
}


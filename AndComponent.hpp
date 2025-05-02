#pragma once
#include "AComponent.hpp"

namespace nts
{
    class AndComponent : public AComponent
    {
        public:
        AndComponent(const std::string &name);
        ~AndComponent();
    
        nts::Tristate compute(std::size_t pin);
    };    
}


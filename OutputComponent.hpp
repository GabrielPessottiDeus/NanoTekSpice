#pragma once
#include "AComponent.hpp"

namespace nts
{
    class OutputComponent : public AComponent
    {
        public:
        OutputComponent(const std::string &name);
        ~OutputComponent();
    
        nts::Tristate compute(size_t pin) override;
        void setCarry(nts::Tristate carry);
    };
}


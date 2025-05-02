#pragma once
#include "AComponent.hpp"

namespace nts
{
    class FalseComponent : public AComponent
    {
        public:
        FalseComponent(const std::string &name);
        ~FalseComponent();

        nts::Tristate compute(size_t pin) override;
    };
}


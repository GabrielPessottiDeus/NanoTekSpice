#pragma once
#include "AComponent.hpp"

namespace nts
{
    class NotComponent : public AComponent
    {
        public:
        NotComponent(const std::string &name);
        ~NotComponent();

        nts::Tristate compute(std::size_t pin) override;
    };
}


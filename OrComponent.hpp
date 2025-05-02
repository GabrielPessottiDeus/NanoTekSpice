#pragma once
#include "AComponent.hpp"

namespace nts
{
    class OrComponent : public AComponent
    {
        public:
        OrComponent(const std::string &name);
        ~OrComponent();

        nts::Tristate compute(std::size_t pin) override;
    };
}

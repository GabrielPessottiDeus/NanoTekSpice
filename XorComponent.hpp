#pragma once
#include "AComponent.hpp"

namespace nts
{
    class XorComponent : public AComponent
    {
        public:
        XorComponent(const std::string &name);
        ~XorComponent();

        nts::Tristate compute(std::size_t pin) override;
    };
}

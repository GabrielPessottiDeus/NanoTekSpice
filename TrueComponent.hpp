#pragma once
#include "AComponent.hpp"

namespace nts
{
    class TrueComponent : public AComponent
    {
        public:
        TrueComponent(const std::string &name);
        ~TrueComponent();

        nts::Tristate compute(size_t pin) override;
    };
}

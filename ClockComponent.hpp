#pragma once
#include "AComponent.hpp"
#include "InputComponent.hpp"

namespace nts
{
    class ClockComponent : public InputComponent
    {
        public :
            ClockComponent(std::string const &name);
            ~ClockComponent();

            void simulate(std::size_t tick) override;
    };
}

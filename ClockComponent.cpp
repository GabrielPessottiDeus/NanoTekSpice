#include "ClockComponent.hpp"

namespace nts
{
    ClockComponent::ClockComponent(std::string const &name)
        : InputComponent(name) {}

    ClockComponent::~ClockComponent() {}

    void ClockComponent::simulate(std::size_t tick)
    {
        if (_pins[1] != nts::Undefined) {
            if (tick%2==0) 
                _pins[1] = nts::True;
            else
                _pins[1] = nts::False;
        }
    }
}
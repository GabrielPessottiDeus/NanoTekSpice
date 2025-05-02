#include "TrueComponent.hpp"


namespace nts
{
    TrueComponent::TrueComponent(const std::string &name) : AComponent(name, 1)
    {
        inPins = std::vector<size_t> {};
        outPins = std::vector<size_t> {1};
    }

    TrueComponent::~TrueComponent()
    {

    }

    nts::Tristate TrueComponent::compute(size_t pin)
    {
        (void)pin;
        _pins[1] = nts::True;
        return nts::True;
    }
}

#include "InputComponent.hpp"

namespace nts
{
    InputComponent::InputComponent(const std::string &name) : AComponent(name, 1)
    {
        inPins = std::vector<std::size_t> {};
        outPins = std::vector<std::size_t> {1};
        _tmp = nts::Undefined;
    }

    InputComponent::~InputComponent()
    {
    }

    void InputComponent::simulate(std::size_t tick) {
        (void)tick;
        _pins[1] = _tmp;
    }

    nts::Tristate InputComponent::compute(std::size_t pin)
    {
        (void)pin;
        return _pins[1];
    }

    bool InputComponent::setInputValue(nts::Tristate value)
    {
        _tmp = value;
        return _pins[1];
    }
}
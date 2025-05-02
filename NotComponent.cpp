#include "NotComponent.hpp"

namespace nts
{
    NotComponent::NotComponent(const std::string &name) : AComponent(name, 2)
    {
        inPins = std::vector<size_t> {1};
        outPins = std::vector<size_t> {2};
    }

    NotComponent::~NotComponent()
    {
    }

    nts::Tristate NotComponent::compute(size_t pin)
    {
        if (std::find(outPins.begin(), outPins.end(), pin) == outPins.end())
            return nts::Undefined;

        for(std::size_t inPin : inPins) {
            auto it = _links.find(inPin);
            if (it != _links.end() && it->second.first != nullptr) {
                _pins[inPin] = it->second.first->compute(it->second.second);
            }
        }
        if (_pins[1] == nts::True)
            _pins[2] = nts::False;
        else if (_pins[1] == nts::False)
            _pins[2] = nts::True;
        else
            _pins[2] = nts::Undefined;


        return _pins[pin];
    }
}
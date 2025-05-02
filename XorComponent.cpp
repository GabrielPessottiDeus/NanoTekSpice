#include "XorComponent.hpp"

namespace nts
{
    XorComponent::XorComponent(const std::string &name) : AComponent(name, 3)
    {
        inPins = std::vector<size_t> {1,2};
        outPins = std::vector<size_t> {3};
    }
    
    XorComponent::~XorComponent()
    {
    
    }

    nts::Tristate XorComponent::compute(size_t pin)
    {
        for(std::size_t inPin : inPins) {
            auto it = _links.find(inPin);
            if (it != _links.end() && it->second.first != nullptr) {
                _pins[inPin] = it->second.first->compute(it->second.second);
            }
        }
        if (_pins[1] == nts::Undefined || _pins[2] == nts::Undefined)
            _pins[3] = nts::Undefined;
        else if (_pins[1] == nts::True && _pins[2] == nts::True)
            _pins[3] = nts::False;
        else if (_pins[1] == nts::False && _pins[2] == nts::False)
            _pins[3] = nts::False;
        else
            _pins[3] = nts::True;

        if (std::find(outPins.begin(), outPins.end(), pin) != outPins.end())
            return _pins[pin];
        return nts::Undefined;
    }   
}


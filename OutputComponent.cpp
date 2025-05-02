#include "OutputComponent.hpp"

namespace nts
{
    OutputComponent::OutputComponent(const std::string &name) : AComponent(name, 1)
    {
        inPins = std::vector<size_t> {1};
        outPins = std::vector<size_t> {};
    }
    
    OutputComponent::~OutputComponent()
    {
        
    }

    nts::Tristate OutputComponent::compute(size_t pin)
    {
        for(std::size_t inPin : inPins) {
            auto it = _links.find(inPin);
            if (it != _links.end() && it->second.first != nullptr) {
                _pins[inPin] = it->second.first->compute(it->second.second);
            }
        }
        return _pins[pin];
    }

    void OutputComponent::setCarry(nts::Tristate carry)
    {
        _pins[1] = carry;
        Tristate a = _pins[1];
    }
}

#include "AComponent.hpp"
#include <unordered_map>
#include <memory>
#include <stdexcept>
#include <algorithm>

namespace nts
{
    AComponent::AComponent(const std::string &name, std::size_t numPin)
        : _name(name), _numPin(numPin)
    {
        for (size_t i = 1; i <= numPin; i++)
        {
            _pins[i] = nts::Undefined;
        }
    }

    AComponent::~AComponent() {}

    void AComponent::simulate(std::size_t tick)
    {
        return (void)tick;
    }

    void AComponent::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> &other, std::size_t otherPin)
    {
        if (std::find(inPins.begin(), inPins.end(), pin) != inPins.end())
        {
            _links[pin] = std::make_pair((other), otherPin);
        }
        else
        {
            return;
        }
    }

    nts::Tristate AComponent::getLink(std::size_t pin) const
    {
        auto it = _links.find(pin);
        if (it != _links.end() && it->second.first != nullptr)
        {
            return it->second.first->compute(it->second.second);
        }

        return nts::Undefined;
    }

    const char *AComponent::Error::what() const noexcept
    {
        return this->message.c_str();
    }
}
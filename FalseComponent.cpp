#include "FalseComponent.hpp"

namespace nts
{
    FalseComponent::FalseComponent(const std::string &name) : AComponent(name, 1)
    {
        inPins = std::vector<std::size_t> {};
        outPins = std::vector<std::size_t> {1};
        _pins[1] = nts::False;
        // std::cout<<"c"<<std::endl;
    }

    FalseComponent::~FalseComponent()
    {
    }

    nts::Tristate FalseComponent::compute(size_t pin)
    {
        (void)pin;
        
        return nts::False;
    }
}
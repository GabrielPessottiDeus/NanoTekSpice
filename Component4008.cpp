#include "Component4008.hpp"
#include "OutputComponent.hpp"
namespace nts
{
    Component4008::Component4008(const std::string &name) : AComponent(name, 15) {
        _sumGates = {
            {10, {6, 7}},
            {11, {4, 5}},
            {12, {2, 3}},
            {13, {1, 15}}
        };
        carry = nts::Undefined;
    }

    void Component4008::simulate(std::size_t tick) {
        (void)tick;
    }

    Tristate Component4008::compute(std::size_t pin) {
        if (_sumGates.find(pin) != _sumGates.end()) {
            auto [in1, in2] = _sumGates[pin];
            Tristate val1 = _links.count(in1) ? _links[in1]->compute(in1) : Undefined;
            Tristate val2 = _links.count(in2) ? _links[in2]->compute(in2) : Undefined;
            if(carry == Undefined)
                carry = _links.count(9) ? _links[9]->compute(in2) : Undefined;

            if (val1 == Undefined || val2 == Undefined || carry == Undefined) return Undefined;

            Tristate sum = static_cast<Tristate>((val1 == nts::True) ^ (val2 == nts::True) ^ (carry == nts::True)); // XOR para soma

            if (((val1 == nts::True) && (val2 == nts::True)) ||
                ((val1 == nts::True) && (carry == nts::True)) ||
                ((val2 == nts::True) && (carry == nts::True)) ||
                ((val1 == nts::True) && (val2 == nts::True) && (carry == nts::True))) {
                    carry = nts::True;
            } else {
                carry = nts::False;
            }

            if (_links.count(14) && _links[14]) {
                auto outputComp = std::dynamic_pointer_cast<OutputComponent>(_links[14]);
                if (outputComp) {
                    outputComp->setCarry(carry);
                }
            }

            return sum;
        }
        return Undefined;
    }

    void Component4008::setLink(std::size_t pin, std::shared_ptr<IComponent> &other, std::size_t otherPin) {
        _links[pin] = other;
    }
}
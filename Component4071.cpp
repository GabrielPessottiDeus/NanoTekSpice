#include "Component4071.hpp"

namespace nts
{
    Component4071::Component4071(const std::string &name) : AComponent(name, 3) {
        _orGates = {
            {3, {1, 2}},
            {4, {5, 6}},
            {10, {8, 9}},
            {11, {12, 13}}
        };
    }

    void Component4071::simulate(std::size_t tick) {
        (void)tick;
    }

    Tristate Component4071::compute(std::size_t pin) {
        if (_orGates.find(pin) != _orGates.end()) {
            auto [in1, in2] = _orGates[pin];
            Tristate val1 = _links.count(in1) ? _links[in1].first->compute(_links[in1].second) : Undefined;
            Tristate val2 = _links.count(in2) ? _links[in2].first->compute(_links[in2].second) : Undefined;

            if (val1 == True || val2 == True) {
                return True;
            }
            if (val1 == False && val2 == False) {
                return False;
            }
            return Undefined;
        }
        return Undefined;
    }

    void Component4071::setLink(std::size_t pin, std::shared_ptr<IComponent> &other, std::size_t otherPin) {
        _links[pin] = {other, otherPin};
    }
}
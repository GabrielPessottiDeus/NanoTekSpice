#include "Component4011.hpp"

namespace nts
{
    Component4011::Component4011(const std::string &name) : AComponent(name, 3) {
        _nandGates = {
            {3, {1, 2}},
            {4, {5, 6}},
            {10, {8, 9}},
            {11, {12, 13}}
        };
    }

    void Component4011::simulate(std::size_t tick) {
        (void)tick;
    }

    Tristate Component4011::compute(std::size_t pin) {
        if (_nandGates.find(pin) != _nandGates.end()) {
            auto [in1, in2] = _nandGates[pin];
            Tristate val1 = _links.count(in1) ? _links[in1].first->compute(_links[in1].second) : Undefined;
            Tristate val2 = _links.count(in2) ? _links[in2].first->compute(_links[in2].second) : Undefined;

            if (val1 == True && val2 == True) {
                return False;
            }
            if (val1 == False || val2 == False) {
                return True;
            }
            return Undefined;
        }
        return Undefined;
    }

    void Component4011::setLink(std::size_t pin, std::shared_ptr<IComponent> &other, std::size_t otherPin) {
        _links[pin] = {other, otherPin};
    }
}
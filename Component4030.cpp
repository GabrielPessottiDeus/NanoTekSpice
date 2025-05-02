#include "Component4030.hpp"
#include "AComponent.hpp"

namespace nts {
    Component4030::Component4030(const std::string &name) : AComponent(name,3) {
        _xorGates = {
            {3, {1, 2}},  // XOR Gate 1: inputs (1,2) -> output (3)
            {4, {5, 6}},  // XOR Gate 2: inputs (5,6) -> output (4)
            {10, {8, 9}}, // XOR Gate 3: inputs (8,9) -> output (10)
            {11, {12, 13}} // XOR Gate 4: inputs (12,13) -> output (11)
        };
    }

    void Component4030::simulate(std::size_t tick) {
        (void)tick; 
    }

    Tristate Component4030::compute(std::size_t pin) {
        if (_xorGates.find(pin) != _xorGates.end()) {
            auto [in1, in2] = _xorGates[pin];
            Tristate val1 = _links.count(in1) ? _links[in1].first->compute(_links[in1].second) : Undefined;
            Tristate val2 = _links.count(in2) ? _links[in2].first->compute(_links[in2].second) : Undefined;
            
            if (val1 == Undefined || val2 == Undefined) return Undefined;
            if (val1 == val2) return False;
            
            return True;
        }
        return Undefined;
    }

    void Component4030::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> &other, std::size_t otherPin) {
        _links[pin] = {other, otherPin};
    }
}

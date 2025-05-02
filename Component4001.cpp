#include "Component4001.hpp"
#include "AComponent.hpp"

namespace nts {
    Component4001::Component4001(const std::string &name) : AComponent(name,3) {
        _norGates = {
            {3, {1, 2}},  // NOR Gate 1: inputs (1,2) -> output (3)
            {4, {5, 6}},  // NOR Gate 2: inputs (5,6) -> output (4)
            {10, {8, 9}}, // NOR Gate 3: inputs (8,9) -> output (10)
            {11, {12, 13}} // NOR Gate 4: inputs (12,13) -> output (11)
        };
    }

    void Component4001::simulate(std::size_t tick) {
        (void)tick; // Avoid unused parameter warning
    }

    Tristate Component4001::compute(std::size_t pin) {
        if (_norGates.find(pin) != _norGates.end()) {
            auto [in1, in2] = _norGates[pin];
            Tristate val1 = _links.count(in1) ? _links[in1].first->compute(_links[in1].second) : Undefined;
            Tristate val2 = _links.count(in2) ? _links[in2].first->compute(_links[in2].second) : Undefined;
            
            if (val1 == True || val2 == True) return False;
            if (val1 == Undefined || val2 == Undefined) return Undefined;
            return True;
        }
        return Undefined;
    }

    void Component4001::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> &other, std::size_t otherPin) {
        _links[pin] = {other, otherPin};
    }
}

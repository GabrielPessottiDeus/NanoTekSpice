#include "Component4069.hpp"
#include "AComponent.hpp"

namespace nts {
    Component4069::Component4069(const std::string &name) : AComponent(name,2) {
        _notGates = {
            {2, {1,0}},  // not Gate 1: inputs (1) -> output (3)
            {4, {3,0}},  // not Gate 2: inputs (3) -> output (4)
            {6, {5,0}}, // not Gate 3: inputs (5) -> output (6)
            {8, {9,0}}, // not Gate 4: inputs (9) -> output (8)
            {10, {11,0}}, // not Gate 5: inputs (11) -> output (10)
            {12, {13,0}} // not Gate 6: inputs (13) -> output (12)

        };
    }

    void Component4069::simulate(std::size_t tick) {
        (void)tick; 
    }

    Tristate Component4069::compute(std::size_t pin) {
        if (_notGates.find(pin) != _notGates.end()) {
            auto [in1, in2] = _notGates[pin];
            Tristate val1 = _links.count(in1) ? _links[in1].first->compute(_links[in1].second) : Undefined;
            // Tristate val2 = _links.count(in2) ? _links[in2].first->compute(_links[in2].second) : Undefined;
            
            if (val1 == nts::Undefined) return nts::Undefined;
            if (val1 == nts::True) return nts::False;
            
            return nts::True;
        }
        return nts::Undefined;
    }

    void Component4069::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> &other, std::size_t otherPin) {
        _links[pin] = {other, otherPin};
    }
}

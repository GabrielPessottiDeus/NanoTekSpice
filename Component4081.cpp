#include "Component4081.hpp"
#include "AComponent.hpp"

namespace nts {
    Component4081::Component4081(const std::string &name) : AComponent(name,3) {
        _andGates = {
            {3, {1, 2}},  // and Gate 1: inputs (1,2) -> output (3)
            {4, {5, 6}},  // and Gate 2: inputs (5,6) -> output (4)
            {10, {8, 9}}, // and Gate 3: inputs (8,9) -> output (10)
            {11, {12, 13}} // and Gate 4: inputs (12,13) -> output (11)
        };
    }

    void Component4081::simulate(std::size_t tick) {
        (void)tick; 
    }

    Tristate Component4081::compute(std::size_t pin) {
        if (_andGates.find(pin) != _andGates.end()) {
            auto [in1, in2] = _andGates[pin];
            Tristate val1 = _links.count(in1) ? _links[in1].first->compute(_links[in1].second) : Undefined;
            Tristate val2 = _links.count(in2) ? _links[in2].first->compute(_links[in2].second) : Undefined;
            
            if (val1 == nts::False || val2 == nts::False) return False;
            if (val1 == nts::Undefined || val2 == nts::Undefined) return nts::Undefined;
            return True;
        }
        return Undefined;
    }

    void Component4081::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> &other, std::size_t otherPin) {
        _links[pin] = {other, otherPin};
    }
}

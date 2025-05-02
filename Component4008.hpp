#pragma once
#include "IComponent.hpp"
#include "AComponent.hpp"
#include <unordered_map>
#include <memory>

namespace nts
{
    class Component4008 : public AComponent
    {
        private :
            std::unordered_map<std::size_t, std::pair<std::size_t, std::size_t>> _sumGates;
            nts::Tristate carry = nts::Undefined;
            std::unordered_map<std::size_t, std::shared_ptr<IComponent>> _links;
        
        public :
            Component4008(const std::string &name);
            void simulate(std::size_t tick);
            Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, std::shared_ptr<IComponent> &other, std::size_t otherPin);
    };
}
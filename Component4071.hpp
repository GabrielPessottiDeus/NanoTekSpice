#pragma once
#include "IComponent.hpp"
#include "AComponent.hpp"
#include <unordered_map>
#include <vector>

namespace nts
{
    class Component4071 : public AComponent
    {
        private :
            std::unordered_map<std::size_t, std::pair<std::size_t, std::size_t>> _orGates;
            std::unordered_map<std::size_t, std::pair<std::shared_ptr<IComponent>, std::size_t>> _links;

        public :
            Component4071(const std::string &name);
            void simulate(std::size_t tick);
            Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> &other, std::size_t otherPin);
    };
}
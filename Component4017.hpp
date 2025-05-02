/*#pragma once
#include <IComponent.hpp>
#include <AComponent.hpp>
#include <array>
#include <memory>

namespace nts
{
    class Component4017 : public AComponent
    {
        private :
            std::array<Tristate, 10> _outputs;
            std::unordered_map<std::size_t, std::shared_ptr<IComponent>> _links;
            std::size_t _currentState;
        public :
            Component4017();
            void simulate(std::size_t tick);
            Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, std::shared_ptr<IComponent> &other, std::size_t otherPin);
    };
}*/
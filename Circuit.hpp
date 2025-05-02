#pragma once
#include "IComponent.hpp"
#include "AComponent.hpp"
#include "Factory.hpp"

namespace nts
{
    class Circuit : public AComponent {
        public :
            std::map<std::string, std::shared_ptr<nts::IComponent>> _components;
            std::vector<std::string> _inpComponents;
            std::vector<std::string> _outComponents;
            std::vector<std::string> _midComponents;
            Factory factory;
            int _tickCount = 0;

            Circuit();
            ~Circuit();

            void addComponent(std::string &type, std::string &name);
            void simulate(std::size_t tick);
            void display();
            nts::Tristate compute(std::size_t pin);
            std::shared_ptr<nts::IComponent> find(std::string &name);
            void setLink (std::size_t pin, std::shared_ptr<nts::IComponent> &other, std::size_t otherPin);
            void setLink(std::size_t pin1, const std::string &comp1, std::size_t pin2, const std::string &comp2);

            static class Error : public std::exception {
                private:
                    std::string message;
                public:
                    Error(const std::string &message) {
                        this->message = std::string(message);
                    };
                    ~Error() {};
                    const char *what() const noexcept override;
            } err;
    };
}
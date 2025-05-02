#pragma once

#include <iostream>
#include "IComponent.hpp"
#include <unordered_map>
#include <vector>
#include <memory>
#include <stdexcept>
#include <map>


namespace nts
{
    class AComponent : public IComponent
    {
        protected:
            std::string _name;
            std::unordered_map<std::size_t, std::pair<std::shared_ptr<nts::IComponent>, std::size_t>> _links;
            std::unordered_map<std::size_t, nts::Tristate> _pins;
            std::vector<size_t> inPins;
            std::vector<size_t> outPins;
            std::size_t _numPin;
            std::map<std::size_t, nts::Tristate> _newPins;

    
        public:
            AComponent(const std::string &name, std::size_t numPin);
            virtual ~AComponent();
            virtual nts::Tristate compute(std::size_t pin) = 0;
            void simulate(std::size_t tick) override;
            void setLink (std::size_t pin, std::shared_ptr<nts::IComponent> &other, std::size_t otherPin) override;
            nts::Tristate getLink(std::size_t pin) const;
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

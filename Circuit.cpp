#include "Circuit.hpp"

namespace nts
{
    Circuit::Circuit() : AComponent ("abacaxi", 0)
    {

    }

    Circuit::~Circuit()
    {

    }

    void Circuit::addComponent(std::string &type, std::string &name)
    {
        if (_components.find(name) != _components.end()) {
            throw Circuit::Error("ja tem pae"); //implement error 
        }

        std::shared_ptr<nts::IComponent> newComp = factory.create(type, name);
        _components.emplace(name, newComp);
        if (type == "input" || type == "clock") {
            _inpComponents.insert(_inpComponents.begin(), name);
        } else if (type == "output" || type == "logger") {
            _outComponents.insert(_outComponents.begin(), name);
        } else {
            _midComponents.insert(_midComponents.begin(), name);
        }
    }

    void Circuit::display()
    {
        std::sort(_inpComponents.begin(), _inpComponents.end());
        std::sort(_outComponents.begin(), _outComponents.end());
    
        std::cout << "tick: " << _tickCount << std::endl;
        std::cout << "input(s):" << std::endl;
        for (auto it = _inpComponents.begin(); it != _inpComponents.end(); it++) {
            if (_components.find(*it) != _components.end()) {
                nts::Tristate res = _components[*it]->compute(1);
                char st = res == nts::Undefined ? 'U' : res == 0 ? '0' : '1';
                std::cout << "  " << *it << ": " << st << std::endl;
            }
        }
        std::cout << "output(s):" << std::endl;
        for (auto it = _outComponents.begin(); it != _outComponents.end(); it++) {
            if (_components.find(*it) != _components.end()) {
                nts::Tristate res = _components[*it]->compute(1);
                char st = res == nts::Undefined ? 'U' : res == 0 ? '0' : '1';
                std::cout << "  " << *it << ": " << st << std::endl;
            }
        }
    }

    std::shared_ptr<nts::IComponent> Circuit::find(std::string &name)
    {
        if (_components.find(name) == _components.end()) {
            throw Circuit::Error("tem nao pae"); //implemment error
        }
        auto it = _components.find(name);
        return it->second;
    }

    const char *Circuit::Error::what() const noexcept
    {   
        return this->message.c_str();
    }


    void Circuit::setLink(std::size_t pin1, const std::string &comp1, std::size_t pin2, const std::string &comp2)
    {
        if (_components.find(comp1) == _components.end()) {
            throw Circuit::Error("Linking error: This component isn't in the circuit \"" + comp1 + "\"");
        }
        if (_components.find(comp2) == _components.end()) {
            throw Circuit::Error("Linking error: This component isn't in the circuit \"" + comp2 + "\"");
        }
        _components[comp1]->setLink(pin1, _components[comp2], pin2);
        _components[comp2]->setLink(pin2, _components[comp1], pin1);
        return;
    }

    void Circuit::simulate(std::size_t tick)
    {
        (void)tick;
        for (auto it = _inpComponents.begin(); it != _inpComponents.end(); it++) {
            if (_components.find(*it) != _components.end()) {
                _components[*it]->simulate(tick);
                _components[*it]->compute(tick);
            }
        }
        for (auto it = _outComponents.begin(); it != _outComponents.end(); it++) {
            if (_components.find(*it) != _components.end()) {
                _components[*it]->simulate(tick);
                _components[*it]->compute(tick);
            }
        }
    
        _tickCount++;
    }

    nts::Tristate Circuit::compute(std::size_t pin)
    {
        (void)pin;
        return nts::Tristate::Undefined;
    }

    void Circuit::setLink (std::size_t pin, std::shared_ptr<nts::IComponent> &other, std::size_t otherPin)
    {
        (void)pin;
        (void)other;
        (void)otherPin;
    }
}

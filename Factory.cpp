#include "Factory.hpp"

namespace nts{
    Factory::Factory()
    {

    }

    Factory::~Factory()
    {

    }

    std::shared_ptr<nts::IComponent> Factory::create(std::string &type, std::string &name)
    {
            if (type == "input")
                return (std::make_shared<InputComponent>(name));
            else if (type == "output")
                return (std::make_shared<OutputComponent>(name));    
            else if (type == "true")
                return (std::make_shared<TrueComponent>(name));    
            else if (type == "false")
                return (std::make_shared<FalseComponent>(name));
            else if (type == "not")
                return (std::make_shared<NotComponent>(name));    
            else if (type == "and")
                return (std::make_shared<AndComponent>(name));    
            else if (type == "or")
                return (std::make_shared<OrComponent>(name));
            else if (type == "xor")
                return (std::make_shared<XorComponent>(name));
            else if (type == "clock")
                return (std::make_shared<ClockComponent>(name));
            else if (type == "4001")
                return (std::make_shared<Component4001>(name));
            else if (type == "4011")
                return (std::make_shared<Component4011>(name));
            else if (type == "4071")
                return (std::make_shared<Component4071>(name));
            else if (type == "4030")
                return (std::make_shared<Component4030>(name));
            else if (type == "4069")
                return (std::make_shared<Component4069>(name));
            else if (type == "4081")
                return (std::make_shared<Component4081>(name));
            else if (type == "4008")
                return (std::make_shared<Component4008>(name));
            throw Factory::Error("nao criou"); 
    }

    const char *Factory::Error::what() const noexcept
    {   
        return this->message.c_str();
    }
}

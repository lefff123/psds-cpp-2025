#include <cstdint>
#include <stdexcept>
#include <iostream>


enum class CheckFlags : uint8_t {
    NONE = 0,
    TIME = (1 << 0),
    DATE = (1 << 1),
    USER = (1 << 2),
    CERT = (1 << 3),
    KEYS = (1 << 4),
    DEST = (1 << 5),
    ALL = TIME | DATE | USER | CERT | KEYS | DEST
};


// побитовое сравнение каждого флага и переданного числа. сравниваем,, приводя все к 8-ми битному инту
// пробовал сделать через switch, не получилось. удивился, что к CheckFlags обращаемся как к пространству имен


void PrintCheckFlags(CheckFlags flags) {
    uint8_t value = static_cast<uint8_t>(flags);
    
    if (value > 0b00111111) {  // Если установлены биты вне диапазона 0-5
        std::cout << "";
        return;
    }

    bool first=true;

    std::cout<<'[';

    if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::TIME))
    {
        std::cout<<"TIME";
        first=false;
    }
            
    if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::DATE))
    {
        if (!first) std::cout<<",";
        first = false;
        std::cout<<"DATE";
    }
            
    if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::USER))
    {
        if (!first) std::cout<<",";
        first = false;
        std::cout<<"USER";
    }
            
    if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::CERT))
    {
        if (!first) std::cout<<",";
        first = false;
        std::cout<<"CERT";
    }
            
    if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::KEYS))
    {
        if (!first) std::cout<<",";
        first = false;
        std::cout<<"KEYS";
    }
            
    if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::DEST))
    {
        if (!first) std::cout<<",";
        first = false;
        std::cout<<"DEST";
    }
    
        std::cout<<']';
    
    
    
    
}

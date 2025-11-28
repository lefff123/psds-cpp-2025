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
// пробовал сделать через switch, не получилось. удивился, что CheckFlags - тоже пространство имен. прикольно.=


void PrintCheckFlags(CheckFlags flags) {
    if (sizeof(flags)==sizeof(uint8_t)){
        std::cout<<"[NONE";
        
        if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::TIME))
            std::cout<<",TIME";
        if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::DATE))
            std::cout<<",DATE";
        if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::USER))
            std::cout<<",USER";
        if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::CERT))
            std::cout<<",CERT";
        if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::KEYS))
            std::cout<<",KEYS";
        if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::DEST))
            std::cout<<",DEST";
        if (static_cast<uint8_t>(flags)&static_cast<u_int8_t>(CheckFlags::ALL))
            std::cout<<",ALL";
        std::cout<<']'<<std::endl;
    }
    else{
        puts("[]");
    }
    
}

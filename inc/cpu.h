/**
 * @file cpu.h
 * @author Theo Davis
 * @brief API for cpu instructions operation.
 * @version 0.1
 * @date 2025-02-02
 * 
 */

#pragma once

#include <cstdint>
#include <cstdbool>

// 1 Byte bit field for flags register
struct FlagBits {
    unsigned char : 4;
    unsigned char carry: 1;
    unsigned char half_carry: 1;
    unsigned char subtract: 1;
    unsigned char zero: 1;
};

union Flags {
    uint8_t byte;
    struct FlagBits bits;
    union Flags& operator=(const unsigned char& rhs) { byte = (0xf0 & rhs); return *this; } // the 4 lsb shall always be 0
    bool operator==(const unsigned char& rhs) { return this->byte == rhs; }
    unsigned int operator|(const unsigned int rhs) { return this->byte | rhs; }    
    friend int operator|(const unsigned int& rhs, const Flags& lhs) { return rhs | lhs.byte; }
};


struct Registers {
    union Flags f;
    uint8_t a;
    uint8_t c;
    uint8_t b;
    uint8_t e;
    uint8_t d;
    uint8_t l;
    uint8_t h;
};

enum Instruction {
    ADD,
    SUB
};

enum Targets {
    a = 1,
    b = 3,
    c = 2,
    d = 5,
    e = 4,
    h = 7,
    l = 6
};

class CPU {
    private:
        struct Registers reg;

    public:

        /* ================================================================== */
        /* #region                         Registers                          */
        /* ================================================================== */

        uint8_t a() const;
        uint8_t& a();
        uint8_t f() const;
        Flags& f();
        uint8_t b() const;
        uint8_t& b();
        uint8_t c() const;
        uint8_t& c();
        uint8_t d() const;
        uint8_t& d();
        uint8_t e() const;
        uint8_t& e();
        uint8_t h() const;
        uint8_t& h();
        uint8_t l() const;
        uint8_t& l();

        uint16_t af() const;
        void set_af(uint16_t);
        uint16_t bc() const;
        uint16_t& bc();
        uint16_t de() const;
        uint16_t& de();
        uint16_t hl() const;
        uint16_t& hl();

        /* ================================================================== */
        /* #endregion                       Registers                         */
        /* ================================================================== */

};
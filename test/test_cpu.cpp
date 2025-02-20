/**
 * @file test_cpu.cpp
 * @author Theo Davis
 * @brief Test functions for cpu.cpp
 * @version 0.1
 * @date 2025-02-02
 * 
 */

#include <cassert>
#include <iostream>

#include "inc/cpu.h"

int main(void) {

    CPU cpu;

    /*
     * msb                                                  lsb
     * +--------+--------------------------------------------+
     * | 8 bits | zero, subtract, h_carry, carry, 0, 0, 0, 0 |
     * +--------+--------------------------------------------+
     *    a                           f
     */

    // Confirm the struct evaluates to the correct size of 8 bytes
    assert(sizeof(struct Registers) == 8);

    cpu.a() = 5;
    cpu.f() = 0xff;
    assert(cpu.a() == 5);
    assert(cpu.f() == 0xf0); // confirm that we can't write to the 4 lsb of f
    assert(cpu.af() == ((cpu.a() << 8) | cpu.f())); // Confirm we have the correct endianess

    cpu.set_af(0x01Af);
    assert(cpu.f() == 0xA0); // confirm that we can't write to the 4 lsb of f
    
    union Flags t;
    t.byte = 0;
    t.bits.zero = 1;
    assert(t.byte == 0x80); // confirm flags are in the correct bit position

    t.byte = 0;
    t.bits.subtract = 1;
    assert(t.byte == 0x40);

    t.byte = 0;
    t.bits.half_carry = 1;
    assert(t.byte == 0x20);

    t.byte = 0;
    t.bits.carry = 1;
    assert(t.byte == 0x10);



    cpu.b() = 7;
    cpu.c() = 8;
    assert(cpu.b() == 7);
    assert(cpu.c() == 8);
    assert(cpu.bc() == ((cpu.b() << 8) | cpu.c()));

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
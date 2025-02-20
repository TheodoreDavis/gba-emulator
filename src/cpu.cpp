/**
 * @file cpu.cpp
 * @author your name (you@domain.com)
 * @brief Code to emulate the cpu of the GBA
 * @version 0.1
 * @date 2025-02-02
 * 
 */

#include "inc/cpu.h"

/* ========================================================================== */
/* #region                             Registers                              */
/* ========================================================================== */

#define GET_REG_PAIR(_pair) (((uint16_t *) (&reg))[(_pair)])
#define AF 0
#define BC 1
#define DE 2
#define HL 3

uint8_t CPU::a() const {
    return reg.a;
}

uint8_t& CPU::a() {
    return reg.a;
}

uint8_t CPU::f() const {
    return reg.f.byte;
}

Flags& CPU::f() {
    return reg.f;
}

uint8_t CPU::b() const {
    return reg.b;
}

uint8_t& CPU::b() {
    return reg.b;
}

uint8_t CPU::c() const {
    return reg.c;
}

uint8_t& CPU::c() {
    return reg.c;
}

uint8_t CPU::d() const {
    return reg.d;
}

uint8_t& CPU::d() {
    return reg.d;
}

uint8_t CPU::e() const {
    return reg.e;
}

uint8_t& CPU::e() {
    return reg.e;
}

uint8_t CPU::h() const {
    return reg.h;
}

uint8_t& CPU::h() {
    return reg.h;
}

uint8_t CPU::l() const {
    return reg.l;
}

uint8_t& CPU::l() {
    return reg.l;
}


uint16_t CPU::af() const {
    return GET_REG_PAIR(AF);
}

void CPU::set_af(uint16_t n) {
    GET_REG_PAIR(AF) = (0xfff0 & n);
}

uint16_t CPU::bc() const {
    return GET_REG_PAIR(BC);
}

uint16_t& CPU::bc() {
    return GET_REG_PAIR(BC);
}

uint16_t CPU::de() const {
    return GET_REG_PAIR(DE);
}

uint16_t& CPU::de() {
    return GET_REG_PAIR(DE);
}

uint16_t CPU::hl() const {
    return GET_REG_PAIR(HL);
}

uint16_t& CPU::hl() {
    return GET_REG_PAIR(HL);
}

/* ========================================================================== */
/* #endregion                            Registers                            */
/* ========================================================================== */

// void CPU::runOpcode()

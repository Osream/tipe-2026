#ifndef __CPU_CLASS_H__
#define __CPU_CLASS_H__

#include <stdint.h>

typedef uint_fast8_t u8;
typedef uint_fast16_t u16;
typedef uint_fast32_t u32;

typedef class CPU_p{
public:
    virtual void print_cpu() = 0;

    virtual u32 get_EAX() = 0;
    virtual u32 get_EBX() = 0;
    virtual u32 get_ECX() = 0;
    virtual u32 get_EDX() = 0;
    virtual u32 get_ESI() = 0;
    virtual u32 get_EDI() = 0;
    virtual u32 get_ESP() = 0;
    virtual u32 get_EBP() = 0;

    virtual u16 get_AX() = 0;
    virtual u16 get_BX() = 0;
    virtual u16 get_CX() = 0;
    virtual u16 get_DX() = 0;

    virtual u8 get_AH() = 0;
    virtual u8 get_AL() = 0;
    virtual u8 get_BH() = 0;
    virtual u8 get_BL() = 0;
    virtual u8 get_CH() = 0;
    virtual u8 get_CL() = 0;
    virtual u8 get_DH() = 0;
    virtual u8 get_DL() = 0;

    virtual void set_EAX(u32) = 0;
    virtual void set_EBX(u32) = 0;
    virtual void set_ECX(u32) = 0;
    virtual void set_EDX(u32) = 0;
    virtual void set_ESI(u32) = 0;
    virtual void set_EDI(u32) = 0;
    virtual void set_ESP(u32) = 0;
    virtual void set_EBP(u32) = 0;

    virtual void set_AX(u16) = 0;
    virtual void set_BX(u16) = 0;
    virtual void set_CX(u16) = 0;
    virtual void set_DX(u16) = 0;

    virtual void set_AH(u8) = 0;
    virtual void set_AL(u8) = 0;
    virtual void set_BH(u8) = 0;
    virtual void set_BL(u8) = 0;
    virtual void set_CH(u8) = 0;
    virtual void set_CL(u8) = 0;
    virtual void set_DH(u8) = 0;
    virtual void set_DL(u8) = 0;

    virtual ~CPU_p() = default;
}* CPU;

CPU init_cpu(u32 r1, u32 r2, u32 r3, u32 r4, u32 r5, u32 r6, u32 r7, u32 r8);

void free_cpu(CPU);

#endif
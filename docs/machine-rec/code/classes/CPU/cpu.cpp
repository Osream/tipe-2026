#include <cstdio>
#include "cpu.h"

class CPU_c : public CPU_p{
public:
    CPU_c(u32 r1, u32 r2, u32 r3, u32 r4, u32 r5, u32 r6, u32 r7, u32 r8);
    void print_cpu() override;
    u32 get_EAX() override;
    u32 get_EBX() override;
    u32 get_ECX() override;
    u32 get_EDX() override;
    u32 get_ESI() override;
    u32 get_EDI() override;
    u32 get_ESP() override;
    u32 get_EBP() override;

    u16 get_AX() override;
    u16 get_BX() override;
    u16 get_CX() override;
    u16 get_DX() override;

    u8 get_AH() override;
    u8 get_AL() override;
    u8 get_BH() override;
    u8 get_BL() override;
    u8 get_CH() override;
    u8 get_CL() override;
    u8 get_DH() override;
    u8 get_DL() override;

    void set_EAX(u32) override;
    void set_EBX(u32) override;
    void set_ECX(u32) override;
    void set_EDX(u32) override;
    void set_ESI(u32) override;
    void set_EDI(u32) override;
    void set_ESP(u32) override;
    void set_EBP(u32) override;

    void set_AX(u16) override;
    void set_BX(u16) override;
    void set_CX(u16) override;
    void set_DX(u16) override;

    void set_AH(u8) override;
    void set_AL(u8) override;
    void set_BH(u8) override;
    void set_BL(u8) override;
    void set_CH(u8) override;
    void set_CL(u8) override;
    void set_DH(u8) override;
    void set_DL(u8) override;

private:
    u32 EAX;
    u32 EBX;
    u32 ECX;
    u32 EDX;
    u32 ESI;
    u32 EDI;
    u32 ESP; //stack pointer
    u32 EBP; //base pointer

    u16 AX;
    u16 BX;
    u16 CX;
    u16 DX;

    u8 AH;
    u8 AL;
    u8 BH;
    u8 BL;
    u8 CH;
    u8 CL;
    u8 DH;
    u8 DL;

};

CPU_c::CPU_c(u32 r1, u32 r2, u32 r3, u32 r4, u32 r5, u32 r6, u32 r7, u32 r8){
    EAX = r1;
    EBX = r2;
    ECX = r3;
    EDX = r4;
    ESI = r5;
    EDI = r6;
    ESP = r7;
    EBP = r8;

    AX = EAX % 0b10000000000000000;
    BX = EBX % 0b10000000000000000;
    CX = ECX % 0b10000000000000000;
    DX = EDX % 0b10000000000000000;

    AH = EAX / 0b10000000000000000;
    AL = EAX / 0b1000000000000000000000000;
    BH = EBX / 0b10000000000000000;
    BL = EBX / 0b1000000000000000000000000;
    CH = ECX / 0b10000000000000000;
    CL = ECX / 0b1000000000000000000000000;
    DH = ECX / 0b10000000000000000;
    DL = EDX / 0b1000000000000000000000000;
}

void CPU_c::print_cpu(){
    printf("EAX = %lu\n",EAX);
    printf("AX = %lu AH = %u AL = %u\n", AX, AH, AL);
    printf("EBX = %lu\n",EBX);
    printf("BX = %lu BH = %u BL = %u\n", BX, BH, BL);
    printf("ECX = %lu\n",ECX);
    printf("CX = %lu CH = %u CL = %u\n", CX, CH, CL);
    printf("EDX = %lu\n",EDX);
    printf("DX = %lu DH = %u DL = %u\n", DX, DH, DL);
    printf("\n");
    printf("ESI = %lu EDI = %lu\n", ESI, EDI);
    printf("ESP = %lu EBP = %lu\n", ESP, EBP);
}

u32 CPU_c::get_EAX(){
    return EAX;
}
u32 CPU_c::get_EBX(){
    return EBX;
}
u32 CPU_c::get_ECX(){
    return ECX;
}
u32 CPU_c::get_EDX(){
    return EDX;
}
u32 CPU_c::get_ESI(){
    return ESI;
}
u32 CPU_c::get_EDI(){
    return EDI;
}
u32 CPU_c::get_ESP(){
    return ESP;
}
u32 CPU_c::get_EBP(){
    return EBP;
}

u16 CPU_c::get_AX(){
    return AX;
}
u16 CPU_c::get_BX(){
    return BX;
}
u16 CPU_c::get_CX(){
    return CX;
}
u16 CPU_c::get_DX(){
    return DX;
}

u8 CPU_c::get_AH(){
    return AH;
}
u8 CPU_c::get_AL(){
    return AL;
}
u8 CPU_c::get_BH(){
    return BH;
}
u8 CPU_c::get_BL(){
    return BL;
}
u8 CPU_c::get_CH(){
    return CH;
}
u8 CPU_c::get_CL(){
    return CL;
}
u8 CPU_c::get_DH(){
    return DH;
}
u8 CPU_c::get_DL(){
    return DL;
}

void CPU_c::set_EAX(u32 i){
    EAX = i;
    AX = EAX % 0b10000000000000000;
    AH = EAX / 0b10000000000000000;
    AL = EAX / 0b1000000000000000000000000;
}
void CPU_c::set_EBX(u32 i){
    EBX = i;
    BX = EBX % 0b10000000000000000;
    BH = EBX / 0b10000000000000000;
    BL = EBX / 0b1000000000000000000000000;
}
void CPU_c::set_ECX(u32 i){
    ECX = i;
    CX = ECX % 0b10000000000000000;
    CH = ECX / 0b10000000000000000;
    CL = ECX / 0b1000000000000000000000000;
}
void CPU_c::set_EDX(u32 i){
    EDX = i;
    DX = EDX % 0b10000000000000000;
    DH = EDX / 0b10000000000000000;
    DL = EDX / 0b1000000000000000000000000;
}
void CPU_c::set_ESI(u32 i){
    ESI = i;
}
void CPU_c::set_EDI(u32 i){
    EDI = i;
}
void CPU_c::set_ESP(u32 i){
    ESP = i;
}
void CPU_c::set_EBP(u32 i){
    EBP = i;
}

void CPU_c::set_AX(u16 i){
    AX = i;
    EAX = AX + AH*0b10000000000000000 + AL*0b1000000000000000000000000;
}
void CPU_c::set_BX(u16 i){
    BX = i;
    EBX = BX + BH*0b10000000000000000 + BL*0b1000000000000000000000000;
}
void CPU_c::set_CX(u16 i){
    CX = i;
    ECX = CX + CH*0b10000000000000000 + CL*0b1000000000000000000000000;
}
void CPU_c::set_DX(u16 i){
    DX = i;
    EDX = DX + DH*0b10000000000000000 + DL*0b1000000000000000000000000;
}

void CPU_c::set_AH(u8 i){
    AH = i;
    EAX = AX + AH*0b10000000000000000 + AL*0b1000000000000000000000000;
}
void CPU_c::set_AL(u8 i){
    AL = i;
    EAX = AX + AH*0b10000000000000000 + AL*0b1000000000000000000000000;
}
void CPU_c::set_BH(u8 i){
    BH = i;
    EBX = BX + BH*0b10000000000000000 + BL*0b1000000000000000000000000;
}
void CPU_c::set_BL(u8 i){
    BL = i;
    EBX = BX + BH*0b10000000000000000 + BL*0b1000000000000000000000000;
}
void CPU_c::set_CH(u8 i){
    CH = i;
    ECX = CX + CH*0b10000000000000000 + CL*0b1000000000000000000000000;
}
void CPU_c::set_CL(u8 i){
    CL = i;
    ECX = CX + CH*0b10000000000000000 + CL*0b1000000000000000000000000;
}
void CPU_c::set_DH(u8 i){
    DH = i;
    EDX = DX + DH*0b10000000000000000 + DL*0b1000000000000000000000000;
}
void CPU_c::set_DL(u8 i){
    DL = i;
    EDX = DX + DH*0b10000000000000000 + DL*0b1000000000000000000000000;
}

CPU init_cpu(u32 r1, u32 r2, u32 r3, u32 r4, u32 r5, u32 r6, u32 r7, u32 r8){
    CPU res = new CPU_c(r1, r2, r3, r4, r5, r6, r7, r8);
    return res;
}

void free_cpu(CPU c){
    delete c;
}
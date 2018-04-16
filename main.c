#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)
//#define _DEBUG_SERIAL_ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O
#ifdef _DEBUG_SERIAL_
   #define TX_232        PIN_C6
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1)
   #use fast_io(c)
#endif
void main (void){
   setup_oscillator(OSC_16MHZ);
   set_tris_a(0xc0);
   set_tris_b(0xf0);
   set_tris_c(0x3f);
   set_tris_d(0xff);
   set_tris_e(0x08);
   long  numeroMinuendo; 
   long  numerosubtraendo; 
   int  botonOperacion= 0;
   long resultado = 0;

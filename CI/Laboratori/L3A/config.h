// configuration parameters 
#pragma config FOSC = HSHP    // Oscillator (LP,XT,HSHP,HSMP,RC,RCIO6,ECHP,ECHPIO6
                              //             ,INTIO67,INTIO7,ECMPIO6,ECLP,ECLPIO6)
#pragma config PLLCFG = OFF     // 4X PLL Enable
#pragma config PRICLKEN = OFF   // Primary clock Enable
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable ->T_Xxiv<-
#pragma config IESO = OFF       // Internal/External Oscillator Switchover
//Setup #pragma config2L
#pragma config PWRTEN = OFF     // Power-up Timer Enable
#pragma config BOREN = OFF      // Brown-out Reset Enable (OFF,ON,NOSLP,SBODIS)
#pragma config BORV = 190       // Brown Out Reset Voltage (285,250,220,190)[V/100] 
//Setup config2H
#pragma config WDTEN = OFF      // Watchdog Timer Enable (OFF,NOSLP,SWON,ON)
#pragma config WDTPS = 1        // Watchdog Timer Postscale Select (1,2,4,...,32768)
//Setup config3H
#pragma config MCLRE = EXTMCLR  // MCLR Pin Enable (EXTMCLR,INTMCLR)

#pragma config CCP2MX = PORTC1  // ECCP2 B output mux (PORTB3, PORTC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable
#pragma config CCP3MX = PORTB5  // CCP3 MUX (PORTB5, PORTC6)
#pragma config HFOFST = OFF     // HFINTOSC Fast Start-up
#pragma config T3CMX = PORTB5   // Timer3 Clock input mux (PORTB5,PORTC0)

//Setup config4L
#pragma config STVREN = OFF     // Stack Full/Underflow Reset Enable
#pragma config LVP = OFF        // Single-Supply ICSP Enable
#pragma config XINST = OFF      // Extended Instruction Set Enable
//Setup config5L
#pragma config CP0 = OFF        // Code Protection Block 0
#pragma config CP1 = OFF
#pragma config CP2 = OFF
#pragma config CP3 = OFF
//Setup config5H
#pragma config CPB = OFF        // Boot Block Code Protection
#pragma config CPD = OFF        // Data EEPROM Code Protection
//Setup config6L
#pragma config WRT0 = OFF       // Write Protection Block 0
#pragma config WRT1 = OFF
#pragma config WRT2 = OFF
#pragma config WRT3 = OFF
//Setup config6H
#pragma config WRTB = OFF       // Boot Block Write Protection
#pragma config WRTC = OFF       // #pragma configuration Register Write Protection
#pragma config WRTD = OFF       // Data EEPROM Write Protection
//Setup config7L
#pragma config EBTR0 = OFF      // Table Read Protection Block 1
#pragma config EBTR1 = OFF
#pragma config EBTR2 = OFF
#pragma config EBTR3 = OFF
//Setup config7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection
//end config.h

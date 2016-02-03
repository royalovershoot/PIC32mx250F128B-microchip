/*
This mini project deals with flashing all 4 built in LEDs on the PIC32mx250F128B microchip
*/

#pragma	config			JTAGEN				=	OFF				
#pragma	config			FNOSC				=	FRCPLL	
#pragma	config			FPLLIDIV            =	DIV_2		
#pragma	config			FPLLMUL             =	MUL_16	
#pragma	config			FPLLODIV            =	DIV_32	
#pragma	config			FPBDIV				=	DIV_1		
#pragma	config			FCKSM				=	CSECME	
#pragma	config			POSCMOD             =	OFF			
#pragma	config			IESO				=	OFF				
#pragma	config			OSCIOFNC            =	OFF				
#pragma	config			FWDTEN				=	OFF				



int global_ctr = 0;                 // a global counter.
int global_delay_val = 50;        //  pulse's delay.



void delay(int d); 


// Main function
int main(int argc, char** argv) {

    
	
	LATB = 0;				// Set value of PORT B output to 0. 
	TRISB = 0;				// Set all pins on PORT B to output
    PORTBbits.RB2=0;        //set port RB2 to 0
    PORTBbits.RB3=0;
    PORTBbits.RB0=0;
    PORTBbits.RB1=0;
    
    
    
	
    
	// Infinite Loop. 
    while(1) 
    {
        
        // Turn LED on  
        delay(global_delay_val);        
    	LATB = 0x0001;		  
        PORTBbits.RB2=1;

        delay(500);
        LATB=0x0001;
        PORTBbits.RB3=1;
        
        
        delay(800);
        LATB=0x0001;
        PORTBbits.RB0=1;
        
        delay(1000);
        LATB=0x0001;
        PORTBbits.RB1=1;
        
        
        // Turn LED off (takes roughly 1 sec)
        delay(global_delay_val);         // 1000: roughly Delay for roughly 1 second with 187.5 kHz system clock
		LATB = 0x0000;		// Set Pin 0 on PORT A to logic level "low" (0v).
        PORTBbits.RB2=0;

        
        
        global_ctr++;
        
        
    }

	return (EXIT_SUCCESS);
}



void delay(int d)
{
    int i;  // Declare variable to be used in the loop

    while(d)    // While d > 0
    {
        i = 100;    // set i to 100 for inner loop
        while(i)    // while i > 0
        {
            i--;    // decrement i (e.g. i will equal 99, 98, 97,...)
        }

        d--;    // decrement d
    }
}

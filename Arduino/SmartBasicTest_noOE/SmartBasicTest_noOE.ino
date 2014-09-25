/****************************************************************
Example code demonstrating the use of the FTDI SmartBasic board.
The SmartBasic board is a serial data multiplexer which allows
a user to program an Arduino Pro, Pro Mini, Fio, or other board
without an on-board USB-to-serial bridge while keeping another
serial connected device connected to the Arduino's hardware
serial port.

This example uses a normal FTDI Basic board as the auxiliary
device; that board's serial port is opened in another terminal.

This code is beerware; if you use it, please buy me (or any other
SparkFun employee) a cold beverage next time you run into one of
us at the local.

25 Sep 2014- Mike Hord, SparkFun Electronics

Code developed in Arduino 1.0.5, on a 5V Arduino Pro board.
****************************************************************/

// Set up a few constants
    #define SEL 2  // When the SEL pin is held low, the data will be
                   //  routed to the PC via the USB-serial bridge.
                   //  That port is also the port used for programming
                   //  by the Arduino IDE. When in bootloading mode, a
                   //  pull-down resistor on the SmartBasic causes it
                   //  to remain in programming mode.
    
    #define ARDUINO_IDE   LOW  // Constants to make our routing change
    #define AUX_TERMINAL  HIGH //  more obvious. When the SEL pin is 
                               //  LOW, data is routed to the
                               //  programming port.
    
    void setup()
    {
      Serial.begin(115200);    // Set up the hardware serial port.
      
      pinMode(SEL, OUTPUT);    // Make the select line an output...
      digitalWrite(SEL, ARDUINO_IDE); // ...and connect the board to
                               //  the Arduino IDE's terminal.  
    }
    
    void loop()
    {
      // The loop just says "Hello" to the two terminals, over and
      //  over, forever. Note the use of the "flush()" function. If
      //  omitted, the Arduino will re-route the serial data before
      //  the transmission has been completed; flush() causes the
      //  Arduino to block until the serial data output buffer is
      //  empty. Failure to use flush() will result in data being
      //  sent to the wrong device, or to multiplexer changes during
      //  transmission which may cause framing errors or data
      //  corruption. *Always put in a flush() before you change
      //  destination devices or disable the output.*
      Serial.flush();
      digitalWrite(SEL, ARDUINO_IDE);
      Serial.println("Hello, Arduino IDE!");
      
      // Swap to the non-Arduino terminal and say hello.
      Serial.flush();
      digitalWrite(SEL, AUX_TERMINAL);
      Serial.println("Hello, auxilliary terminal!");
    
      Serial.flush();
    
      delay(500); // This is a rate-limiter only. The temptation to use
                  //  delay() instead of flush() is strong, but fight it.
                  //  If you use delay, you will *certainly* make a change
                  //  to the code which makes the original delay time too
                  //  short for the new serial data stream, resulting in
                  //  data corruption. flush() will *always* be the right
                  //  length.
    }


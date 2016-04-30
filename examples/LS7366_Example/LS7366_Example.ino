#include <LS7366.h>
#include <SPI.h>

LS7366 myLS7366(8);  //8 is the chip select pin.

void setup() {
  Serial.begin(115200);
  myLS7366.write_mode_register_0(FILTER_1 | DISABLE_INDX | FREE_RUN | QUADRX4);
  myLS7366.write_mode_register_1(NO_FLAGS | EN_CNTR | BYTE_4 );
  myLS7366.clear_counter();
  myLS7366.clear_status_register();
  myLS7366.write_data_register(4);
}

void loop() {
  unsigned long count = myLS7366.read_counter();
  Serial.print("Count: ");
  Serial.print(count, DEC);
  Serial.print(" Status: ");
  print_binary(myLS7366.read_status_register());
  Serial.print("\n");
  delay(1000);
}

//Function to print out one byte in a readable, left-padded binary format

void print_binary(byte val)
{
byte i=0;
for (i=0;i<8;i++)
    {
        if (val & (0x01 << (7-i)))
        {
             Serial.print("1");
        }
        else
        {
             Serial.print("0");
        }
        if (i==3) Serial.print("_");
    }
}

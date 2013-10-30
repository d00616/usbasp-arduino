/*
  Blitzsteuerung für ATMEGA8 in Form eines USBASP
  http://www.fischl.de/usbasp/
  
  Hinzufügen zu arduino/hardware/arduino/boards.txt
    usbasp.name=USBASP ATmega8 12MHz
    usbasp.upload.protocol=usbasp
    usbasp.upload.maximum_size=8192
    usbasp.upload.speed=57600
    usbasp.build.mcu=atmega8
    usbasp.build.f_cpu=12000000L
    usbasp.build.core=arduino
    usbasp.build.variant=standard

  Zum Flashen JP2 auf Zielcontroller schließen und zwei USBASP mit Flachbandkabel verbinden.
    
  Fuses setzen
    avrdude -c usbasp -p atmega8 -U lfuse:w:0xef:m -U hfuse:w:0xc1:m
    
  Vor dem Programmiern chip löschen wenn Fehler beim Flashen auftritt
    avrdude -c usbasp -p atmega8 -e

  Nutzbare PINs:
  
  Arduino  Chip                Board
  ==================================================================
     0      2  PD0  RxD        X2.6      Nicht bei allen Varianten
     1      3  PD1  TxD        X2.8      Nicht bei allen Varianten
     
    A0     23  PC0  ADC0       LED Rot
    A1     24  PC1  ADC1       LED Grün
    A2     25  PC2  ADC2       JP3       Nicht bei allen Varianten
    
    10     16  PB2  SS/OC1B    X2.5    Verbunden mit JP2, PWM
    11     17  PB3  MOSI/OC2   X2.1    PWM
    12     18  PB4  MISO       X2.9
    13     19  PB5  SCK        X2.7
    
     8     14  PB0  ICP1       USB.2
     2      4  PD2  INT0       USB.3     Verbunden mit Arduino Pin 9
     9     15  PB1  OC1A       USB.3     Verbunden mit Arduino Pin 2, PWM
  
 */

int led1 = A1;
int led2 = A0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);     
  pinMode(led2, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
}

#include <Wire.h>
#include <Adafruit_ADS1015.h>

// Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
Adafruit_ADS1015 ads;     /* Use thi for the 12-bit version */
float x[30];
float avg =0;
const int dirPin = 4;
const int stepPin = 5;
void setup(void)
{
    Serial.begin(115200);



  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
  
  ads.begin();
   pinMode(dirPin, OUTPUT);
   pinMode(stepPin, OUTPUT);
}

void loop(void)
{
       int stepDelay = 250;
      digitalWrite(dirPin, HIGH);
      // Giramos 200 pulsos para hacer una vuelta completa
      for (int z = 0; z < 200; z++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(stepDelay);
   
    
  int16_t results;
  
  //float   multiplier = 3.0F;    /* ADS1015 @ +/- 6.144V gain (12-bit results) */
  float multiplier = 0.1875F; /* ADS1115  @ +/- 6.144V gain (16-bit results) */

  for(int i=0; i<=10 ; i++)
  {
    results = ads.readADC_Differential_0_1(); 
    x[i] = results*multiplier;
  }
  for(int i=0; i<=10 ; i++)
  {
    avg = x[i] + avg;
  }
  avg = avg/11;
  
  //Serial.print("Differential: "); Serial.print(results); Serial.print("(");
  Serial.println(avg); 
  //Serial.println("mV)");
    digitalWrite(stepPin, LOW);  
    delayMicroseconds(stepDelay);
       
}
       delay(100);
  
}



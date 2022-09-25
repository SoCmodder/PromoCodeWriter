#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
//a signed char can't be converted to byte or something like that.
byte type[] = "android.com:pkg";
byte payload1[] = "com.ridecharge.android.taximagic";

void setup(){
  Serial.begin(9600);
  delay(500);
  Serial.println("Taxi Magic NDEF Promo Code Writer for Android");
  nfc.begin(); 
}

void loop(){
 Serial.println("\nPlace a formatted Mifare classic NFC tag on the reader.");
 if(nfc.tagPresent()){
  NdefMessage message = NdefMessage();  
  message.addTextRecord("NFCwtf");
  
  boolean success = nfc.write(message);
  if (success){
   Serial.println("Magic finished. Try the tag with your phone!"); 
  }
  else{
   Serial.println("Write failed"); 
  }
 } 
 delay(3000);
}

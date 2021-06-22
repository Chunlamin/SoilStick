/*
 * Soil_Stick_read_output_and_convert_to0-100VWC
 * 30 April 2021
 * facebook fan page: เกษตรไทย IoT
 * https://www.facebook.com/AgriThaiIoT/
 */
 
 #include <SoilStick_A.h>
SoilStick_A SoilStick_1;

//#define ANALOG_PIN A4       // OUT ของเซนเซอร์เชื่อมต่อกับพิน A0 ของบอร์ด arduino Uno
//#define ENABLE_PIN A5       // EN ของเซนเซอร์เชื่อมต่อกับพิน A1 ของบอร์ด arduino Uno
#define ANALOG_PIN 36       // OUT ของเซนเซอร์เชื่อมต่อกับพิน GPIO36 ของบอร์ด ESP32 DevkitV1
#define ENABLE_PIN 22       // EN ของเซนเซอร์เชื่อมต่อกับพิน GPIO22 ของบอร์ด ESP32 DevkitV1
//#define ANALOG_PIN A0       // OUT ของเซนเซอร์เชื่อมต่อกับพิน A0 ของบอร์ด ESP8266
//#define ENABLE_PIN 16       // EN ของเซนเซอร์เชื่อมต่อกับพิน GPIO16 ของบอร์ด ESP8266

float VREF = 3.3; // for ESP32 DevkitV1 and ESP8266
//float VREF = 5.0; // for arduino Uno
long _ADC = 4096;  // for ESP32 DevkitV1
//long _ADC = 1024;  // for arduino Uno and ESP8266

void setup() {
  Serial.begin(115200);
  
  SoilStick_1.begin(ANALOG_PIN, ENABLE_PIN);  // เซตการเชื่อมต่อ analog pin และ digital pin ที่เชื่อมต่อกับ Soil Stick
  SoilStick_1.setADC(_ADC, VREF);             // เซตค่า ความละเอียดของ ADC และ แรงดันอ้างอิง
  SoilStick_1.setSoilMoistureDry(2.33);       // เซตค่า analog output(Volt) จาก Soil Stick เมื่อ Soil Stick อยู่ในสภาวะแห้งสุด
  SoilStick_1.setSoilMoistureWet(1.6);        // เซตค่า analog output(Volt) จาก Soil Stick เมื่อ Soil Stick อยู่ในสภาวะชุ่มชื้นสูงสุด
}

void loop() {  
  
  float volt = SoilStick_1.readOutputVolt();  // อ่านค่า analog output(Volt) จาก Soil Stick
  float soil_vwc = SoilStick_1.VWCS(volt);    // แปลงค่าแรงดันที่อ่านได้เป็นค่า Volumetric water content (VWC) soil moisture sensors

  // แสดงค่าที่อ่านได้จาก Soil Stick
  Serial.print("output: ");
  Serial.print(volt, 3);
  Serial.print("Volt\tVWC: ");
  Serial.println(soil_vwc, 1);
  delay(2000);
}

/*
 * โค๊ดตัวอย่างการทดสอบการอ่านค่าเอ๊าต์พุทของเซนเซอร์วัดความชื้นในดิน Soil Stick
 * และแปลงค่าเป็นส่วนกลับ ปรับให้อยู่ในสเกล0-10
 * ทดสอบกับบอร์ด Arduino Uno
 * 
 * 15 April 2020
 * facebook fan page: เกษตรไทย IoT
 */

#define ANALOG_PIN A0       // OUT ของเซนเซอร์เชื่อมต่อกับพิน A0 ของบอร์ด arduino Uno
#define ENABLE_PIN A1       // EN ของเซนเซอร์เชื่อมต่อกับพิน A1 ของบอร์ด arduino Uno
#define DRY_MILLIVOLT 2490  // ค่าเอ้าต์พุท เมื่อทดสอบที่อากาศแห้ง ในหน่วยมิลลิโวลต์
#define WET_MILLIVOLT 1850  // ค่าเอ้าต์พุท เมื่อทดสอบน้ำเซนเซอร์จุ่มน้ำทั้งตัว ในหน่วยมิลลิโวลต์

void setup() {
  Serial.begin(115200);           // กำหนดค่าเริ่มต้นความเร็วซีเรียลที่ 115200
  pinMode(ENABLE_PIN, OUTPUT);    // กำหนดให้ENABLE_PINอยู่ในโหมดเอ้าต์พุท
  digitalWrite(ENABLE_PIN, HIGH); // ให้ENABLE_PIN เป็นhighเพื่อเปิดการทำงานของ Soil Stick
  delay(1000);                    // หน่วงเวลา 1วินาที เพื่อให้เอ้าต์พุทของ Soil Stick เริ่มนิ่ง
}

void loop() {
  float sensorValueMilliVoltage = (float)analogRead(ANALOG_PIN)*5000.0/1024.0;  // อ่านค่าอนาล๊อคจากANALOG_PIN และแปลงค่าที่อ่านได้เป็นแรงดันไฟฟ้า ในหน่วยมิลลิโวลต์
  
  // map(value, fromLow, fromHigh, toLow, toHigh) ค่าตัวแปรต่างๆของ ฟังชั่น map()
  float moistureLevel = map(sensorValueMilliVoltage, DRY_MILLIVOLT, WET_MILLIVOLT, 0, 100)/10.0;  // แมพค่าจากแรงดันเอ้าต์พุท เป็นสเกล0.0-10.0
  
  Serial.print("Soil Stick Moisture Level = "); // แสดงข้อความ "Soil Stick Moisture Level = " ทางซีเรียลมอนิเตอร์
  Serial.println(moistureLevel, 1);  // แสดงค่าระดับความชื้น ที่ทดสนิยม1ตำแหน่ง และขึ้นบรรทัดใหม่
  delay(1000);  // หน่วงเวลา 1วินาที
}

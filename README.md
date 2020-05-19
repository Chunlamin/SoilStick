# SoilStick
soil moisture sensor FDR

Soil Stick เซ็นเซอร์สำหรับการทดสอบและประเมินความชื้นของดิน (Sensor for soil moisture testing and evaluation)
![Image 1](https://github.com/Chunlamin/SoilStick/blob/master/Images/97583103_1436400656749112_2738311323606581248_n.jpg)

Soil Stick คือเซนเซอร์วัดความชื้นในดิน สำหรับผู้ต้องการข้อมูลระดับความชื้นในดิน อุปกรณ์ออกแบบมาให้มีความทนทานต่อการใช้งานในพื้นที่เพาะปลูกจริงทนทานต่อการกัดกร่อน เหมาะสำหรับการเก็บข้อมูลการเกษตรแม่นยำในระยะยาว รวมไปถึงนักเรียน นักศึกษา และผู้สนใจทดลองทำการตรวจวัดด้านอื่นๆได้อีกด้วย

วัดความชื้นในดินด้วยวิธีการวัดความต้านทางสนามไฟฟ้าที่เปลี่ยนแปลงไปตามความชื้นในดิน โดยวิธีการนี้หลักการตรวจวัดจะมีค่าเปลี่ยนแปลงตามปริมาณน้ำในดินอย่างมีนัยสำคัญ วัสดุนำไฟฟ้าของอุปกรณ์จะอยู่ภายในชั้นของแผ่นFR4จะไม่สัมผัสกับเนื้อดินโดยตรง ซึ่งเป็นจุดเด่นของอุปกรณ์นี้ ประการแรกเนื้อดินไม่สามารถสร้างความเสียหายต่อส่วนการวัดจากการขูดหรือเสียดสีได้ ประการที่สองสารละลายดิน ปฏิกิริยาทางเคมีในดิน หรือชีวชีวภัณฑ์ ทางการเกษตร มีผลต่อการวัดค่าต่ำมาก Soil Stick จึงเหมาะที่จะเป็นอุปกรณ์สำหรับการตรวจวัดความชื้นในดิน

# การประยุกต์ใช้
- ระบบเฝ้าติดตามการเปลี่ยนแปลงความชื้นในดิน
- ระบบการจัดการการให้น้ำพืช
- สมาร์ทฟาร์ม

![Image 2](https://github.com/Chunlamin/SoilStick/blob/master/Images/Screenshot_189.png)

# Specifications
- Supply voltage 3.3-6 Volt
- Operating temperature range 0-70 °C
- Cable range 1.5 Meter, size 24AWG-4C
- Enable active high
- Waterproof

# Connection

![Image 3](https://github.com/Chunlamin/SoilStick/blob/master/Images/Screenshot_188.png)

เซนเซอร์จะมีสายไฟขนาด 24AWG-4C ยาว 1.5 เมตร และยำสายไฟมาให้ การเชื่อมต่อมีดังนี้

- GND: สายไฟสีดำ
- +V: สายไฟสีแดง
- EN: สายไฟสีเหลือง
- OUT: สายไฟสีขาว

![Image 4](https://github.com/Chunlamin/SoilStick/blob/master/Images/IMG_20200416_163508.jpg)

# Enable and output

![Image 5](https://github.com/Chunlamin/SoilStick/blob/master/Images/pic_88_1.bmp)

- Enable signal (yellow)
- Output signal (blue)
- @5V supply

เอ้าต์พุทที่สามารถอ่านเพือนำไปใช้งานได้ จะอยู่หลังจากenableเป็นhighแล้ว เป็นเวลา 200มิลลิวินาที (แนะนำให้ใช้เป็น 500 มิลลิวินาที หลังจากenableเป็นhighแล้ว)

ค่าที่อ่านได้จากเซนเซอร์นี้ จะแปรผกผันกับความชื้น (ความชื้นน้อย เอ้าพุทอ่านได้มาก ความชื้นมากเอ้าต์พุทอ่านได้น้อย) ผู้ใช้จึงควรปรับให้แปรผันตามความชื้น และปรับเทียบกับระดับความชื้นที่ต้องการก่อนการใช้งาน เพื่อความสอดสล้องของความชื้นที่อ่านได้

***เพื่อยืดอายุการใช้งานของเซนเซอร์ ควรให้enableเป็นlow เพื่อหยุดการทำงานของเซนเซอร์ หลังจากอ่านค่าเสร็จแล้วทุกครั้ง

# Electrical characteristics

| Parameter | Condition | Value | Units |
| --- | --- | --- | --- |
| supply voltage | - | 3.3-6 | V |
| supply current | @5V supply | 12.7 | mA |
| output range | - | 0-3 | V |
| enable active | - | 1.1-6 | V |

# Dimensional drawing

![Image 6](https://github.com/Chunlamin/SoilStick/blob/master/Images/Screenshot_186.png)

# Example code 1: อ่านค่าจากเซนเซอร์
อ่านค่าจากเซนเซอร์ และแสดงผลทุกๆ5วินาที

![Image 7](https://github.com/Chunlamin/SoilStick/blob/master/Images/IMG_20200415_105151.JPG)

เชื่อมต่อเซนเซอร์เข้ากับบอร์ดArduinoดังนี้
- สายสีดำ ต่อกับ GND
- สายสีแดง ต่อกับ +5V
- สายสีเหลือง ต่อกับ A1
- สายสีขาว ต่อกับ A0

Example code 1:

![Image 8](https://github.com/Chunlamin/SoilStick/blob/master/Images/Screenshot_190.png)

แสดงผลทาง Serial monitor ทดลองอ่านค่าการเปลี่ยนแปลง จากอากาศแห้งไปเป็นความชื้นสูงสุดที่อ่านได้

# Example code 2: อ่านสัญญาณเอ้าต์พุท
ใช้วิธีการเชื่อมต่อแบบเดียวกับ Example code 1

Example code 2:

![Image 9](https://github.com/Chunlamin/SoilStick/blob/master/Images/Screenshot_191.png)
- Output (red)
- Enable (blue)

เซนเซอร์จะอ่านค่าความชื้นเมื่อenableเป็นhigh และเมื่อenableเป็นlow เซนเซอร์จะหยุดการทำงาน output จะค่อยๆลดลง

*การทดสอบนี้ เซนเซอร์อยู่ในพื้นที่ไม่มีความชื้น

# Price
![Image 10](https://github.com/Chunlamin/SoilStick/blob/master/Images/93885244_2867292716639462_5648328941421723648_n.jpg)

Soil Stick ราคา 330 บาท

สั่งซื้อได้ที่ facebook fan page **เกษตรไทย IoT** (https://www.facebook.com/AgriThaiIoT/)

![Image 11](https://github.com/Chunlamin/SoilStick/blob/master/Images/90270899_126421142269799_7999289821870686208_n.png)

# Medium

# About us

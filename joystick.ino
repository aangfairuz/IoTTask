#include <M5Stack.h> //memanggil library m5stack
/*
note:Reading the adc value requires writing the pin 25 of th
e adc to 0.
dacWrite(25, 0);
*/
void setup() {
// put your setup code here, to run once:
M5.begin(); //menghubungkan m5stack board dengan m5stack library
pinMode(2, INPUT_PULLUP); //mengakses pin dari digital sebagai input
dacWrite(25, 0); //merubah data digital menjadi adta analog
M5.Lcd.setCursor(100, 0, 4); //memindahkan atau memposisikan ulang kursor dengan posisi baris dan kolom 
M5.Lcd.print("JOYSTICK"); //menapilkan tuliskan "JOYSTICK"
}
uint16_t x_data; //inisialisasi x_data dalam bentuk 16 bit
uint16_t y_data; //inisialisasi y_data dalam bentuk 16 bit
uint8_t button_data; //inisialisasi button_data dalam bentuk 16 bit
void loop() {
// put your main code here, to run repeatedly:
x_data = analogRead(35); //membaca masukan pin dalam bentuk data analog
y_data = analogRead(36); //membaca masukan pin dalam bentuk data analog
button_data = digitalRead(2); // membaca masukan pin dalam bentuk data digital
Serial.printf("x:%0d y:%0d button:%d\n", x_data, y_data, button_data); //mengirim data teks ke serial m5stack
M5.Lcd.setCursor(30, 120, 4); //memindahkan atau memposisikan ulang kursor dengan posisi baris dan kolom
M5.Lcd.printf("x:%04d y:%04d button:%d\n", x_data, y_data, button_data); //menampilkan hasi data x,y, dan button data
delay(200); //memberikan jeda 200 mili detik
}

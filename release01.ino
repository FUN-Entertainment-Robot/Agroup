#include <M5Stack.h>
#include <ESP32Servo.h>

Servo sg90;
Servo sg90hv;//必要なモータの数だけ指定

void setup() {
M5.begin();
sg90hv.attach(16); // SG90サーボモータの制御ピン番号を指定
sg90hv.attach(17); // SG90-HVサーボモータの制御ピン番号を指定

int sg90_s =60; //サーボモータのスピードや角度を指定するための変数
int sg90hv_s =60;

//[//M5.Lcd.setRotation](https://m5.lcd.setrotation/)(3); // 画面を90度回転させる（必要に応じて調整してください）
M5.Lcd.fillScreen(BLACK); // 画面を黒色で塗りつぶす
M5.Lcd.setTextColor(WHITE); // テキストの色を白色に設定
M5.Lcd.setTextSize(2); // テキストのサイズを2倍に設定

}

void loop() {
M5.update();
M5.Lcd.setCursor(60, M5.Lcd.height() - 16); // 画面左下にカーソルを移動0
M5.Lcd.print("A");

M5.Lcd.setCursor(M5.Lcd.width() / 2 - 8, M5.Lcd.height() - 16); // 画面中央下にカーソルを移動
M5.Lcd.print("B");

M5.Lcd.setCursor(M5.Lcd.width() - 70, M5.Lcd.height() - 16); // 画面右下にカーソルを移動-16
M5.Lcd.print("C");

if (M5.BtnA.wasPressed()) { // Aボタン。一回だけ動く
sg90hv.write(80); //hvでは、　1~89が正回転、90が停止、91〜180が反回転。それぞれ端に近づくほど速くなる。
delay(800); // 遅延時間
sg90hv.write(90);

delay(1000);

sg90hv.write(101);
delay(1077);
sg90hv.write(90);
delay(1000);
}

if(M5.BtnB.wasPressed()){//Bボタン。複数回連続で動く。

for(int i =0; i<3;i++){
sg90hv.write(80); //hvでは、　1~89が正回転、90が停止、91〜180が反回転。それぞれ端に近づくほど速くなる。
delay(800); // 遅延時間
sg90hv.write(90);
delay(1000);

sg90hv.write(101);
delay(1000);
sg90hv.write(90);
delay(1000);

}
}

if (M5.BtnC.wasPressed()) { // Cボタン。基本意味はない。
sg90hv.write(90);
delay(1000);

}
}
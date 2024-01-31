#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <M5Stack.h>
#include "AudioFileSourceSD.h"
#include "AudioFileSourceID3.h"
#include "AudioGeneratorMP3.h"
#include "AudioOutputI2S.h"

//タッチセンサのピン番号の指定
#define TOUCH_SENSOR 5

// 最小パルス幅(~4096の範囲)
#define SERVOMIN 110

// 最大パルス幅(~4096の範囲)
#define SERVOMAX 480

//　音声ファイル系の定義
AudioGeneratorMP3 *mp3;
AudioFileSourceSD *file;
AudioOutputI2S *out;
AudioFileSourceID3 *id3;

//　サーボドライバの通信経路の指定
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);  // PCA9685のI2Cアドレスを指定

//　move関数で扱う角度を示す変数
int angle;

// テキストカラー
int baseColor = 0xFFFF;
int runningColor = 0xFC40;

//　サーボモータのピン番号の指定
int servoElbowRight_PIN = 0;
int servoLateralShoulderRight_PIN = 1;
int servoLongitudinalShoulderRight_PIN = 2;
int servoElbowLeft_PIN = 3;
int servoLateralShoulderLeft_PIN = 4;
int servoLongitudinalShoulderLeft_PIN = 5;
int servoNeck_PIN = 6;

//　サーボモータの初期位置
int initialPositionElbowRight = 75;
int initialPositionLateralShoulderRight = 165;
int initialPositionLongitudinalShoulderRight = 90;
int initialPositionElbowLeft = 105;
int initialPositionLateralShoulderLeft = 15;
int initialPositionLongitudinalShoulderLeft = 90;
int initialPositionNeck = 80;

//　サーボモータの位置
int positionElbowRight;
int positionLateralShoulderRight;
int positionLongitudinalShoulderRight;
int positionElbowLeft;
int positionLateralShoulderLeft;
int positionLongitudinalShoulderLeft;
int positionNeck;
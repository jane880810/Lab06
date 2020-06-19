#include <Keypad.h>

const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
// 定義 Keypad 的按鍵
char keys[ROWS][COLS] = {
  {'7', '4', '1', '0'}, {'8','5','2', 'A'},
{'9', '6', '3', 'B'}, {'C', 'D', 'E', 'F'}
};
// 定義 Keypad 連到 Arduino 的接腳
byte rowPins[ROWS] = {7,8,9,10};
// 連到 Keypad 的 4 個 Rows
byte colPins[COLS] = {11,12,13,14};
// 連到 Keypad 的 4 個 Columns
// 建立 Keypad 物件
Keypad keypad = Keypad( makeKeymap(keys), rowPins,colPins, ROWS, COLS );
int tune;
void setup() {

}

void loop() {
  char key = keypad.getKey(); // 讀取 Keypad的輸入
  if (key != NO_KEY) {  // 有按下按鍵
    if (key == '1')
      tune = 262;
    else if (key == '2')
      tune = 294;
    else if (key == '3')
      tune = 330;
    else if (key == '4')
      tune = 349;
    else if (key == '5')
      tune = 392;
    else if (key == '6')
      tune = 440;
    else if (key == '7')
      tune = 494;
    else
      tune = 0;
    tone(5, tune);
    delay(500);
    noTone(5);
  }
}

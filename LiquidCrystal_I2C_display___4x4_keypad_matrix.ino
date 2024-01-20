// keypad should be wired from 8 to 1 (keypad pins) to 9 to 2 Arduino pins
//This is a code to wire your arduino to your LCD screen and keypad

#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//set your lcd address
#define LCD_ADDRESS 0x27

//set the dimensions
#define LCD_COLUMNS 16
#define LCD_ROWS 2

#define myKeypad 

//declare the LiquidCrystal_I2C object with I2C address, the number of columns and rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte numRows = 4; //number of rows on the keypad
const byte numCols  = 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as it appears on the keypad

char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A',},
{'4', '5', '6', 'B',},
{'7', '8', '9', 'C',},
{'*', '0', '#', 'D',}
};

byte rowPins[numRows] = {9,8,7,6}; //if you modify your pins you should modify this
byte colPins[numCols] = {5,4,3,2}; //columns 0 to 3

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap (keymap), rowPins, colPins, numRows, numCols);

void setup(){
//  Serial.begin(9600);
  //initialize the lcd and turn on the backlight
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.print("Press a key");
//  delay(2000);
  lcd.setCursor(1,2);
}
void loop(){
//  char customKey = customKeypad.getKey();
//  if (customKey)
//  {
//    lcd.print(customKey);
//  }
//if (customKey = 'D')
//  {
//    lcd.print("Pressed D");

lcd.setCursor(0,0); //Defining positon to write from first row,first column .
  lcd.print("PRESS ANY KEY"); //You can write 16 Characters per line .
   
  char key = customKeypad.getKey();// Read the key
  lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
  lcd.print("Passcode: ");
  // Print if key pressed
  
  lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
  lcd.print("Passcode: ");
  if (key){
    lcd.print("*");
  }
  lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
  lcd.print("Passcode: ");
  if (key){
    lcd.print("*");
  }
  lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
  lcd.print("Passcode: ");
  if (key){
    lcd.print("*");
  }
}

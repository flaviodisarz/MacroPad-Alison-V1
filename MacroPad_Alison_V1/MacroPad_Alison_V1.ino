//////////////////////////////////////////////////
//   Codigo Geral MacroPad Alison Pulcino...    //
//                                              //
//          Controle de Processos.              //
//                                              //
//   Inclusão das Bibliotecas    --- Ok.        //
//   Definição dos Pinos         --- Ok.        //
//   Definição das Teclas        --- OK.        //
//   Definição das Funções       --- Ok.        //
//   Definição das Layers        --- Ok.        //
//   Definição dos Leds          --- Ok.        //
//   Definição das Cores         --- Ok.        //
//   Definição dos Rotary        --- Ok.        //
//   Validação das Funções       --- Ok.        //
//                                              //
//////////////////////////////////////////////////

//Bibliotecas Inseridas e Instaladas no Programa.

//Biblioteca de Definição Matricial
#include <Keypad.h>

//Biblioteca de Definição das Funções de Controle USB
#include <HID-Project.h>
#include <HID-Settings.h>

//Biblioteca do Encoder
//#include <KY040.h>

//Biblioteca  Leds
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

//Bibliotecas Próprias
#include "Def.h"
#include "Layout.h"
#include "Funcoes.h"

//Congigurações do Sistema
void setup() {
  pinMode(EncoderD_Pin_1, INPUT);
  pinMode(EncoderD_Pin_2, INPUT);
  pinMode(ModoBotao, INPUT_PULLUP);
  pinMode(PlayBotao, INPUT_PULLUP);
  pinMode(EncoderE_Pin_1, INPUT);
  pinMode(EncoderE_Pin_2, INPUT);
  Serial.begin(9600);
  Keyboard.begin();
  pixels.begin();
}

//Loop do Sistema
void loop() {

  StatusEncoder_D = digitalRead(EncoderD_Pin_1);
  if ((PosicaoFinalEncoder_D == LOW) && (StatusEncoder_D == HIGH)) {
    if (digitalRead(EncoderD_Pin_2) == LOW) {
      PosicaoInicialEncoder_D = 1;
      Consumer.write(MEDIA_VOLUME_UP);
      Serial.println("Volume UP");
    } else {
      PosicaoInicialEncoder_D = 2;
      Consumer.write(MEDIA_VOLUME_DOWN);
      Serial.println("Volume DOWN");
    }
  }
  PosicaoFinalEncoder_D = StatusEncoder_D;

  StatusEncoder_E = digitalRead(EncoderE_Pin_1);
  if ((PosicaoFinalEncoder_E == LOW) && (StatusEncoder_E == HIGH)) {
    if (digitalRead(EncoderE_Pin_2) == LOW) {
      PosicaoInicialEncoder_E = 1;
      Consumer.write(MEDIA_NEXT);
      Serial.println("Avançar Musica");
    } else {
      PosicaoInicialEncoder_E = 2;
      Consumer.write(MEDIA_PREVIOUS);
      Serial.println("Voltar Musica");
    }
    Serial.println(PosicaoInicialEncoder_E);
  }
  PosicaoFinalEncoder_E = StatusEncoder_E;


  checkPlayBotao();
  switch (ContadorPlay) {
    case 0:
      break;
    case 1:
      Consumer.write(MEDIA_PLAY_PAUSE);
      delay(300);
      ContadorPlay = 0;
      break;
  }
  char key = keypad.getKey();
  checkModoBotao();
  switch (ContadorModo) {
    case 0:
      setColorsMode0();
      if (key) {
        Serial.println(key);
        switch (key) {
          case '1':
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.print('v');
            break;
          case '2':
            Keyboard.println("A Paz do Senhor");
            Keyboard.releaseAll();
            break;
          case '3':
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.print('c');
            Keyboard.releaseAll();
            break;
          case '4':
            Keyboard.println("Pulcino1*");
            break;
        }
        delay(50);
        Keyboard.releaseAll();
      }
      break;

    case 1:
      setColorsMode1();
      if (key) {
        Serial.println(key);
        switch (key) {
          case '1':
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press('p');
            Keyboard.releaseAll();
            break;
          case '2':
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press('l');
            Keyboard.releaseAll();
            break;
          case '3':
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press('d');
            Keyboard.releaseAll();
            break;
          case '4':
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press('p');
            Keyboard.releaseAll();
            break;
        }
        delay(50);
        Keyboard.releaseAll();
      }
      break;

    case 2:
      setColorsMode2();
      if (key) {
        Serial.println(key);
        switch (key) {
          case '1':
            Keyboard.println("di");
            break;
          case '2':
            Keyboard.println("qsave");
            break;
          case '3':
            Keyboard.println("aa");

            break;
          case '4':
            Keyboard.println("co");
            break;
        }
        delay(50);
        Keyboard.releaseAll();
      }
      break;
    case 3:
      setColorsMode3();
      if (key) {
        Serial.println(key);
        switch (key) {
          case '1':
            Keyboard.println("di");
            break;
          case '2':
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press('b');
            Keyboard.releaseAll();
            break;
          case '3':
            Keyboard.println("m");
            break;
          case '4':
            Keyboard.println("c");
            break;
        }
        delay(50);
        Keyboard.releaseAll();
      }
      break;

    case 4:
      setColorsMode4();
      if (key) {
        Serial.println(key);
        switch (key) {
          case '1':
            Keyboard.println("DESGRAAAAAAAAAAAAAAAAAAAAAAAAAACA.");
            break;
          case '2':
            Keyboard.println("AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH.");
            break;
          case '3':
            Keyboard.println("SUA MAE.");
            break;
          case '4':
            Keyboard.println("ELE E LOUCO NE.");
            break;
        }
        delay(50);
        Keyboard.releaseAll();
      }
      break;
  }
}

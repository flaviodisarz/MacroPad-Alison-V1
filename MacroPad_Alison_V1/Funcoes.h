//////////////////////////////////////////////
//     Codigo de Definições das Funções     //
//                                          //
//     Funções de Led's                     //
//     Função de Alteração de Modo          //
//     Função de Mídias                     //
//                                          //
//////////////////////////////////////////////

//Funções de Led's
//Led's na Cor Rosa
void setColorsMode0() {
  if (Cor == 0) {
    pixels.setPixelColor(1, pixels.Color(231, 84, 128));
    pixels.setPixelColor(2, pixels.Color(231, 84, 128));
    pixels.setPixelColor(0, pixels.Color(231, 84, 128));
    pixels.setPixelColor(3, pixels.Color(231, 84, 128));
    pixels.show();
    Cor = 1;
  }
}
//Led's na Cor Verde
void setColorsMode1() {
  if (Cor == 0) {
    pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    pixels.setPixelColor(3, pixels.Color(0, 255, 0));
    pixels.show();
    Cor = 1;
  }
}
//Led's na Cor Azul
void setColorsMode2() {
  if (Cor == 0) {
    pixels.setPixelColor(1, pixels.Color(0, 0, 255));
    pixels.setPixelColor(2, pixels.Color(0, 0, 255));
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.setPixelColor(3, pixels.Color(0, 0, 255));
    pixels.show();
    Cor = 1;
  }
}
//Led's na Cor Amarela
void setColorsMode3() {
  if (Cor == 0) {
    pixels.setPixelColor(1, pixels.Color(255, 215, 0));
    pixels.setPixelColor(2, pixels.Color(255, 215, 0));
    pixels.setPixelColor(0, pixels.Color(255, 215, 0));
    pixels.setPixelColor(3, pixels.Color(255, 215, 0));
    pixels.show();
    Cor = 1;
  }
}
//Led's na Cor Vermelha
void setColorsMode4() {
  if (Cor == 0) {
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.setPixelColor(3, pixels.Color(255, 0, 0));
    pixels.show();
    Cor = 1;
  }
}

//Função de Alteração de Modo
void checkModoBotao() {
  StatusModo = digitalRead(ModoBotao);
  if (StatusModo != UltimoStatusModo) {
    if (StatusModo == LOW) {
      ContadorModo++;
      Cor = 0;
    }
    delay(50);
  }
  UltimoStatusModo = StatusModo;
  if (ContadorModo > 4) {
    ContadorModo = 0;
  }
}

//Função de Mídias
void checkPlayBotao() {
  StatusPlay = digitalRead(PlayBotao);
  if (StatusPlay != UltimoStatusPlay) {
    if (StatusPlay == LOW) {
      ContadorPlay++;
    }
    delay(50);
  }
  UltimoStatusPlay = StatusPlay;
  if (ContadorPlay > 1) {
    ContadorPlay = 0;
  }
}


/////////////////////////////
//   Definição de Matriz   //
//      Matriz 2x2         //
//     Rotary's 1 e 2      //
//       [RE] [RD]         //
//       [ 1] [ 2]         //
//       [ 3] [ 4]         //
//                         //
/////////////////////////////

//Definições de Quantidade de Colunas e Linhas
const byte ROWS = 2;
const byte COLS = 2;

//Definições das Funções da Matriz
char keys[ROWS][COLS] = {
  { '1', '3' },
  { '2', '4' },
};

//Definições das Colunas e Linhas
byte rowPins[ROWS] = { R1, R2 };
byte colPins[COLS] = { C1, C2 };

//Definições das Led's
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NumLeds, PIN, NEO_GRB + NEO_KHZ800);
////////////////////////////////////////////
//     Codigo de Definições dos Pinos     //
//                                        //
//     Pinos Matriz                       //
//     Pinos Rotary Encoder               //
//     Constantes de Funções              //
//                                        //
////////////////////////////////////////////

//Definições de Pinos Led's
#define PIN 9

//Definições de Pinos Botões
int R1 = 7;
int R2 = 8;
int C1 = 5;
int C2 = 6;

//Definições de Pinos Encoder's
const int ModoBotao = 4;
const int PlayBotao = 21;
int EncoderD_Pin_1 = 20;//20
int EncoderD_Pin_2 = 19;//19
int EncoderE_Pin_1 = 3;//2
int EncoderE_Pin_2 = 2;//3

//Definições de Constantes das Funções
#define NumLeds 4
int Cor = 0;
int ContadorModo = 0;
int StatusModo = 0;
int UltimoStatusModo = 0;

int ContadorPlay = 0;
int StatusPlay = 0;
int UltimoStatusPlay = 0;

int PosicaoInicialEncoder_D = 0;
int PosicaoFinalEncoder_D = LOW;
int StatusEncoder_D = LOW;

int PosicaoInicialEncoder_E = 0;
int PosicaoFinalEncoder_E = LOW;
int StatusEncoder_E = LOW;

void inicio();                                       

void (*isr[])() _attribute_ ((section (".vetor")))={ // atribui vetor ponteiro de função a uma seção da
    (void (*) ())0x20020000,                         // memória chamada "vetor" no endereço 0x20020000
    inicio                                           // tal endereço (final da RAM) é para onde irá retornar
};                                                   // do interrupt

void inicio (){
    *((int*)(0x40023800 + 0x30))=0x08;              // habilitar porta D
    *((int*)(0x40020C00 + 0x00))=0x01000000;        // GPIO D modo output
    *((int*)(0x40020C00 + 0x04))=0x00000000;        // GPIO D modo modo output push-pull
    *((int*)(0x40020C00 + 0x08))=0x00000000;        // GPIO D modo output low speed
    *((int*)(0x40020C00 + 0x0c))=0x00000000;        // GPIO D no pull-up, pull-down
    int ligado=0x1000;                              // atribui valor para variavel
    int desligado=0x0000;                           // atribui valor para variavel
    int i;                                          // cria variavel auxiliar
    int *ptr=(int*)(0x40020C00 + 0x14);             // declara ponteiro que aponta para GPIOD_ODR
loop:
    i=800000;                                       // inicia variavel auxiliar com 800000
    *ptr=ligado;                                    // liga o LED (mandou 0x1000 para o GPIOD_ODR, que liga)
    while(i--);                                     // faz nada enquanto i!= 0, e decrementa a cada interação
    *ptr=desligado;                                 // desliga o LED (mandou 0x000 para o GPIOD_ODR, que desliga)
    i=800000;                                       // reinicia o "contador" colocando a variavel aux em 800000
    while(i--);                                     // faz nada enquanto i!= 0, e decrementa a cada interação
    goto loop;                                      // volta para o início do loop
}
# MinervaProject

Registro Mestre de Projeto 

Bases e arquivos de apoio utilizados para o desenvolvimento do projeto:

STM32duino - IDE Arduino Ver.1 e Ver.2

- Fontes TTL 
https://github.com/FrankBoesing/fonts.git
- Display TFT SPI/I2C
https://github.com/Bodmer/TFT_eSPI
- FontConverter - 1
https://rop.nl/truetype2gfx/
- FontConverter - 2
https://oleddisplay.squix.ch/#/home
- RGB888 para RGB565
https://trolsoft.ru/ru/articles/rgb565-color-picker
- App (EM TESTE)
https://thunkable.com/#/

Nixie_Clock - Extensor de Sensores de Sobrevivência

Iniciando em 16/10/2021

Projeto Minerva da paixão pelos clássicos tubos Nixie desenvolvidos na década de 50 aos modernos display LCD, da inspiração veio junto o desafio de unir o antigo ao novo agregando diversos sensores para a apresentação de informações para uso e sobrevivência diário como:

- Pressão (mmHg)
- Temperatura (ºC e F)
- Umidade (%)
- Altitude
- sieverts (µSv e mSv)
- Hora/Data
- Calendário Completo
- Estação do Ano (Primavera)
- Semana (Semana 39)
- Modo de ajustes dos parâmetros 

Sendo organizados pelos Menus:
Geiger                              - Apresenta Contagem por Segundo, Leitura Sieverts nSv/s
Dosimeter                           - Apresenta valor Dosimetro, Tempo de atualização, faixa de risco de Sv/h
Geiger GF                           - Apresenta gráfico dos valores apresentados nas 24 Horas do Geiger
Weather                             - Apresenta Temperatura, Umidade, Pressão Atmosférica, mínima e máxima e previsão via Zambretti 
Weather GF Temperature              - Apresenta gráfico dos valores apresentados nas 24 Horas do Temperatura
Weather GF Humidity                 - Apresenta gráfico dos valores apresentados nas 24 Horas do Umidade
Weather GF Atmosferic Pressure      - Apresenta gráfico dos valores apresentados nas 24 Horas do Pressão Atmosferica
Calendar                            - Apresenta Calendário
Timer                               - Apresenta Alarme, Contador e Tempo de Volta
Ajust Time                          - Apresenta ajuste do Relógio
Ajust Data                          - Apresenta ajuste da Data
Ajust Bright                        - Apresenta ajuste de Brilho da Tela

Ajustes Gráficos sendo:
Nixie Settings                      - Apresenta ajuste de animação Nixie
Battery Settings                    - Apresenta ajuste de bateria
Custom Color                        - Apresenta ajuste de cores de menus
Graphic Settings 1                  - Apresenta ajuste de linhas de gráfico
Graphic Settings 2                  - Apresenta estilos gráfico
Time Settings                       - Apresenta ajuste de tempo, 12H/24H H/M/S, H/M
Background Settings                 - Apresenta estilo de Plano de Fundo
Database                            - Apresenta valores de todas as variaveis presentes (USO DESENVOLVIMENTO).


Lista Terminais Utilizados STM32F401CCU6  26/02/2022

Componentes e suas caracteristicas

SN74141 : True Table // Podendo utilizar k155id1 ou SN74141
- D C B A #
- L, L, L, L 0
- L, L, L, H 1
- L, L, H, L 2
- L, L, H, H 3
- L, H, L, L 4
- L, H, L, H 5
- L, H, H, L 6
- L, H, H, H 7
- H, L, L, L 8
- H, L, L, H 9
- H, L, H, L N
- H, L, H, H N
- H, H, L, L N
- H, H, L, H N
- H, H, H, L N
- H, H, H, H N

ILI9486_DRIVER - Alimentação Ideal 3v3
TFT 8-BIT PARALLEL

STM32L476RG

- R       Botao Hard Reset (Apenas para Desenvolvimento)

- PA0     TFT_RD
- PA1     TFT_WD
- PA2     
- PA3     
- PA4     TFT_DC
- PA5     
- PA6    
- PA7     
- PA8     TFT_D7
- PA9     TFT_D1
- PA10    TFT_D2
- PA11    
- PA12    
- PA15    

- PB0     TFT_CS
- PB1    
- PB2     
- PB3     TFT_D3
- PB4     TFT_D5
- PB5     TFT_D4
- PB6     
- PB7     
- PB8     
- PB9     
- PB10    TFT_D6
- PB12   
- PB13    
- PB14  
- PB15   

- PC0
- PC1     TFT_RST
- PC2
- PC3
- PC4
- PC5
- PC6
- PC7     TFT_D0
- PC8
- PC9
- PC10
- PC11
- PC12
- PC13   
- PC14    
- PC15    

- PD2

- PH0
- PH1

ESP32S

- R       Botao Hard Reset

- GPIO0
- GPIO1
- GPIO2
- GPIO3
- GPIO4
- GPIO6
- GPIO7
- GPIO8
- GPIO9
- GPIO10
- GPIO11
- GPIO12
- GPIO13
- GPIO14
- GPIO15
- GPIO16
- GPIO17
- GPIO18
- GPIO19
- GPIO21
- GPIO22
- GPIO23
- GPIO25
- GPIO26
- GPIO27
- GPIO32
- GPIO33
- GPIO34
- GPIO35
- GPIO36
- GPIO39

Detectado falha grave na execução conjunta dos modulos de Nixie e ILI9486, não sendo possível a parada da execução sem a perda de dados comprometendo assim o funcionamento e o projeto, sendo então continuado a utilização do microcontrolador ARM STM32F401CC e adicionado com interação ao Microcontrolador ESP32, escolhido pela dimensão capacidade de armazenamento e poder de processamento tendo assim, novas opções e funcionalidade como rede Bluetooth e Wi-Fi.

# MinervaProject

Registro Mestre de Projeto 

Bases e arquivos de apoio utilizados para o desenvolvimento do projeto:

STM32duino - IDE Arduino Ver.1 e Ver.2

- Fontes TTL 
https://github.com/FrankBoesing/fonts.git
- Display TFT SPI/I2C
https://github.com/FrankBoesing/TFT_eSPI_ext.git
- FontConverter - 1
https://rop.nl/truetype2gfx/
- FontConverter - 2
https://oleddisplay.squix.ch/#/home
- RGB888 para RGB565
https://trolsoft.ru/ru/articles/rgb565-color-picker

Nixie_Clock - Extensor de Sensores de Sobrevivência

Iniciando em 16/10/2021

Projeto MC1 Tempus da paixão pelos clássicos tubos Nixie desenvolvidos na década de 50 aos modernos display LCD, da inspiração veio junto o desafio de unir o antigo ao novo agregando diversos sensores para a apresentação de informações para uso e sobrevivencia diário como:

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

*Projeto em desenvolvimento, concluído 15% 29/10/2021

*Projeto em desenvolvimento, concluído 40% 29/12/2021
Removido em software medição de Altitude (*faixa de erro acima de 10%).

Modelagem e conceitos de dimensões finalizadas, componentes e materiais em 65% comprados e montados.

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

ST7789 - Alimentação Ideal 3v3 possível 5V mas com aquecimento

STM32F401CC

- R       Botao Hard Reset (Apenas para Desenvolvimento)

- PA0     Alimentacao LDR
- PA1     Pino DC ST7789
- PA2     Pino RST ST7789
- PA3     Pino BLK ST7789
- PA4     LDR Sensor
- PA5     Pino SCL ST7789 
- PA6     Geiger Sensor
- PA7     Pino SDA ST7789
- PA8     Pino Nixie A
- PA9     Pino Nixie B
- PA10    Pino Nixie C
- PA11    Pino Nixie D
- PA12    anode Nixie B
- PA15    anode Nixie A

- PB0     Nivel Bateria
- PB1     anode Nixie D
- PB2     anode Nixie C
- PB3     Pino SCL BME280 // EM TESTE
- PB4      
- PB5     Pino SDA BME280 // EM TESTE
- PB6     **USART TX1
- PB7     **USART RX1
- PB8     Buzzer
- PB9     
- PB10    
- PB12    Botao Hibernar
- PB13    Botao Menu
- PB14    Botao Up
- PB15    Botao Down

- PC13    Leitura Bat EN
- PC14    
- PC15    


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


Detectado falha grave na execução conjunta dos modulos de Nixie e ST7789, não sendo possível a parada da execução sem a perda de dados comprometendo assim o funcionamento e o projeto, sendo então continuado a utilização do microcontrolador ARM STM32F401CC e adicionado com interação ao Microcontrolador ESP32, escolhido pela dimensão capacidade de armazenamento e poder de processamento tendo assim, novas opções e funcionalidade como rede Bluetooth e Wi-Fi.

*Projeto em desenvolvimento, concluído 30% 02/03/2022

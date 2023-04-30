// Inclusão das bibliotecas
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Instanciação do objeto da classe AsyncWebServer
AsyncWebServer server(80);

// Constantes das credenciais do WiFi
const char* ssid = "Ricardo-EvolutionPro-2G";
const char* password = "ricardo123";

void setup() {

  // Conecta-se ao Ponto de acesso com as credenciais fornecidas
  WiFi.begin(ssid, password);

  // disponibiliza o url "/"
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    const char index_html[] PROGMEM = R"====(

<!DOCTYPE html>
<html lang="pt-br">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Lato:300">
    <head>
       <meta charset="utf-8"/>
       <title>Welcome</title>
       
    </head>

    <script>
        const scrollBars = document.querySelectorAll('.scroll-bar');

        function updateScrollBars() {
        const scrollTop = document.documentElement.scrollTop;
        const scrollHeight = document.documentElement.scrollHeight;
        const clientHeight = document.documentElement.clientHeight;
        const scrollRatio = scrollTop / (scrollHeight - clientHeight);

        scrollBars.forEach((scrollBar, index) => {
            if (index / 4 <= scrollRatio) {
            scrollBar.classList.add('active');
            } else {
            scrollBar.classList.remove('active');
            }
        });
        }

        window.addEventListener('scroll', updateScrollBars);

    </script>
    <style>
        @import url('https://fonts.googleapis.com/css?family=Lato&display=swap');

        body {
            margin: 0;
            padding: 0;
            justify-content: center;
        }
        .header-container {
            
            display: flex;
            justify-content: flex-end;
            align-items: center;
            padding: 10px;
            background-color: #161616;
            color: white;
        }

        img {
            width: 50px;
            height: 50px;
            margin-left: 2%;
            margin-top: 5px;
            position: absolute;
        }

        .header-buttons {
            display: flex;
            justify-content: flex-end;
            align-items: center;
        }

        .botao-header {
            font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
            font-size: 18px;
            color: #c0c0c0;
            background-color: transparent;
            border: none;
            padding: 10px;
            cursor: pointer;
            margin-left: 10px;
            width: 90px;
        }

        .botao-header2 {
            font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
            font-weight: 600;
            font-size: 18px;
            background-color: #fff;
            color: #000000;
            border: none;
            padding: 10px;
            border-radius: 5px;
            cursor: pointer;
            margin-left: 20px;
            width: 100px;
            margin-right: 2%;
        }

        .botao-header:hover {
            border: none;
            border-radius: 5px;
            background-color: #ffffff;
            color: #000000;
        }
        .page1 {
            align-items: center;
            width: 100%;
            height: 500px;
            background-color: #161616;
        }
        .page2 {
            align-items: center;
            width: 100%;
            height: 500px;
            background-color: #F67423;
        }
        .page3 {
            align-items: center;
            width: 100%;
            height: 500px;
            background-color: #BE1D69;
        }
        .page4 {
            align-items: center;
            width: 100%;
            height: 500px;
            background-color: #33ACD1;
        }
        .page5 {
            align-items: center;
            width: 100%;
            height: 500px;
            background-color: #343A40;
        }

        .allinone {
            padding-top: 50px;
            display: flex;
            width: 85%;
            margin: 0 auto;
        }
        .gradient-box {
            position: relative;
            background: linear-gradient(to bottom right, rgba(0, 219, 222, 0.9) 0%, rgba(75, 25, 102, 1)55%, rgba(30,25,30, 0.9)); /* define o gradiente na diagonal */
            padding: 0px; /* adiciona algum espaço interno para o conteúdo */
            color: #fff; /* define a cor do texto para branco */
            border-radius: 30px;
            height: 340px;
            width: 60%;
        }

        .gradientimage {
            margin-top: 10px;
            margin-left: 15px;
            width: 55px;
            height: 55px;
        }

        .caixa {
            padding-top: 75px;
            padding-left: 35px;
            margin: 0 auto;
            width: 450px;
            height: 200px;
        }
        .caixa button {
            margin-right: 15px;
            margin-bottom: 15px;
        }

        .coluna {
            border-radius: 15px;
            border: none;
            width: 70px;
            height: 70px;
        }

        .text-box1 {
            line-height: 0px;
            right: 250px;
            position: absolute;
        }
        
        .text-box1 p {
            margin-top: 35px;
            font-size: 54px;
            color: #ffffff;
            font-family: 'Lato', sans-serif;
            font-weight: bold;
        }

        .h1page1 {
            line-height: 25px;
            width: 50px;
            text-align: right;
            color: #c0c0c0;
            font-family: 'Lato', sans-serif;
            font-weight: 300;
            font-size: 20px;
            padding: 0;
            width: 241px;
        }

        .text-box2 {
            line-height: 0px;
            left: 50px;
            position: absolute;
        }
        
        .text-box2 p {
            margin-top: 125px;
            font-size: 54px;
            color: #ffffff;
            font-family: 'Lato', sans-serif;
            font-weight: bold;
        }

        .h1page2 {
            line-height: 25px;
            width: 50px;
            text-align: left;
            color: #c0c0c0;
            font-family: 'Lato', sans-serif;
            font-weight: 300;
            font-size: 20px;
            padding: 0;
            width: 241px;
        }

        .text-box3 {
            text-align: center;
            line-height: 0px;
            left: 30%;
            position: absolute;
        }
        
        .text-box3 p {
            margin-top: 75px;
            font-size: 54px;
            color: #ffffff;
            font-family: 'Lato', sans-serif;
            font-weight: bold;
        }

        .h1page3 {
            margin-left: 85px;
            line-height: 25px;
            text-align: center;
            color: #c0c0c0;
            font-family: 'Lato', sans-serif;
            font-weight: 300;
            font-size: 20px;
            padding: 0;
            width: 241px;
        }

        .text-box4 {
            line-height: 0px;
            left: 100px;
            position: absolute;
        }
        
        .text-box4 p {
            margin-top: 125px;
            font-size: 54px;
            color: #ffffff;
            font-family: 'Lato', sans-serif;
            font-weight: bold;
        }

        .h1page4 {
            line-height: 25px;
            width: 50px;
            text-align: left;
            color: #c0c0c0;
            font-family: 'Lato', sans-serif;
            font-weight: 300;
            font-size: 20px;
            padding: 0;
            width: 275px;
        }

        .btn {
            display: flex;
            justify-content: center;
            align-items: center;
            position: fixed;
            bottom: 10px;
            right: 10px;
            width: 50px;
            height: 50px;
            border-radius: 25px;
            background-color: #808080;
            text-decoration: none;
        }
        .btn:hover {
            transition: 250ms;
            color: #06D2DA;
        }
        
        .knowmore {
            color: #c0c0c0;
            font-family: 'Lato', sans-serif;
            font-weight: 300;
            font-size: 20px;
            border: none;
            background-color: #F67423;
        }

        .knowmore:hover {
            cursor: pointer;
        }
        
    </style>
    <body>
        <div class="page1">
            <div header="Content-Type" "background-color: #191919">
                <img src="blackmufoxpng.png" alt="Logo da Empresa">
                <header class="header-container">
                    <button class="botao-header">About</button>
                    <button class="botao-header">Screens</button>
                    <button class="botao-header">Connect</button>
                    <button class="botao-header2">Settings</button>
                </header>
            </div>
            <div class="page1"> 
                <div class="allinone">
                    <div class="gradient-box">
                        <img src="blackmufoxpng.png" class = "gradientimage" alt="Logo da Empresa">
                        <div class="caixa">
                            <div class="linha">
                                <button class="coluna" style="background-color: #f67a23;">
                                <button class="coluna" style="background-color: #f1a71f;">
                                <button class="coluna" style="background-color: #eb6052;">
                                <button class="coluna" style="background-color: #5fbc8d;">
                                <button class="coluna" style="background-color: #e91b5b;">
                            </div>
                            <div class="linha">
                                <button class="coluna" style="background-color: #eb6052;">
                                <button class="coluna" style="background-color: #58d160;">
                                <button class="coluna" style="background-color: #33acd1;">
                                <button class="coluna" style="background-color: #e46837;">
                                <button class="coluna" style="background-color: #15d9e2;">
                            </div>
                            <div class="linha">
                                <button class="coluna" style="background-color: #189b8d;">
                                <button class="coluna" style="background-color: #be1d69;">
                                <button class="coluna" style="background-color: #343a40;">
                                <button class="coluna" style="background-color: #9a54d8;">
                                <button class="coluna" style="background-color: #6a6a6a;">
                            </div>
                          </div>
                          
                    </div>
                    <div class="text-box1">
                        <p>All in One</p>
                        <h1 class="h1page1">Configure your <br> 
                            device using the <br> 
                            web access with <br> 
                            no need of a <br> 
                            account or <br> 
                            Mainframe.</h1>
                    </div> 
                </div>                  
            </div>
            <div class="page2"> 
                <div class="text-box2">
                    <p>Geiger Measurer</p>
                    <h1 class="h1page2">Measure the alfa and 
                        <br> beta radiations the <br> 
                        electron and 4He of the <br> 
                        Thorium, Radio, Uranium, <br> 
                        Plutonium decay. <br><br>
                        <button class="knowmore"><i>Want know more?</i></button></h1>
                </div> 
            </div>
            <div class="page3"> 
                <div class="text-box3">
                    <p>Compass System</p>
                    <h1 class="h1page3">Full system with compass <br> 
                        and gyroscope.</h1>
                </div> 
            </div>
            <div class="page4"> 
                <div class="text-box4">
                    <p>Weather System</p>
                    <h1 class="h1page4">By usiing the Temperature, <br>
                        Humidity and Atmospheric <br>
                        pressure data, find the possible <br>
                        weather forecast.</h1>
                </div> 
            </div>
            <div class="page5"> 
                <div class="text-box4">
                    <p>Nixie Tube Clock</p>
                    <h1 class="h1page4">Show the time in the <br>
                        old style of orange Neon <br>
                        working perfect in <br>
                        dark and light places.</h1>
                </div> 
                <section></section>
                <a href="#" class="btn"></a>
            </div>
        </div>
        
    </body>
</html>

    )===="; // grande matriz de caracteres
    request->send_P(200, "text/html", index_html); // Envia a resposta
  });

  // Servidor começa à ouvir os clientes
  server.begin();
}

void loop() {}

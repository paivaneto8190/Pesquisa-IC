# Rastreador solar com arduino (RASCUNHO)

O objetivo desse projeto é fazer um modelo em pequena escala de um dispositivo composto por 4 sensores LDR capazes de rastrear a luz solar e se direcionarem para a região de maior luminosidade.

## Métodos pensados
Inicialmente foi pensado em captar os dados dos sensores e usá-los verificando quais os maiores valores de luminosidade de acordo com uma tolerância fazendo assim mexer os eixos com os servos motores.

Caso necessário, devido as limitações do arduino, pode ser implantado um filtro analógico ou um filtro por meio de médias aritméticas que permitam filtrar os sinais do sensor que chegam ruidosos ao arduino

PS: olhar códigos da internet e fazer mudanças de acordo com os valores registrados pelos sensores já que só há rotação em dois eixos
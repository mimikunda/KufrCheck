# Pinout for active build
## DHT11
| DHT11 pin | Connect to |
|---|---|
| VCC | Arduino 5V |
| DATA / OUT | Arduino D2 |
| GND | Arduino GND |

For a **bare 4-pin sensor**, with the grille facing you, the pins are typically VCC, DATA, NC, GND from left to right. Add a 10 kΩ pull-up resistor between VCC and DATA if it isn’t already built into a module. Check the labels on your module, since its pin order can vary. <citation src="1,2"></citation>



## 1602A

| LCD pin | Label | Connect to |
|---:|---|---|
| 1 | VSS / GND | GND |
| 2 | VDD / VCC | 5V |
| 3 | VO | Wiper of a 10 kΩ contrast potentiometer; pot ends to 5V and GND |
| 4 | RS | D12 |
| 5 | RW | GND |
| 6 | E | D11 |
| 7–10 | D0–D3 | Leave unconnected |
| 11 | D4 | D6 |
| 12 | D5 | D5 |
| 13 | D6 | D4 |
| 14 | D7 | D3 |
| 15 | A / LED+ | 5V, through a resistor if your module lacks one |
| 16 | K / LED− | GND |


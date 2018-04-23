# Smart Pharmacy
## ENGR-111 Project 3
Smart Pharmacy software component running on an Arduino Uno
Pin layout:
- MOSI: ICSP-4 (middle-out)
- MISO: ICSP-1 (top-in)
- SCK: ISCP-3  (middle-in)
- NSS: Pin 10
- RST: Pin 9
- VCC: 3.3V (DO NOT USE 5V, VMA405 WILL BE DAMAGED IF YOU DO SO)
- GND: GND
- IRQ: not used
We are using a VMA405 RFID reader with standard MiFare cards
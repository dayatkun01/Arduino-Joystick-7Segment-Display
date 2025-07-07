# Arduino-Joystick-7Segment-Display
This is my very first public repository that i share to public, i publishing this just for having fun and saving my code in future and for comparing my code in this time and in future, sorry for bad english

Instruction:
you must follow this instruction so its 100% work as expected!


![image](https://github.com/user-attachments/assets/2513403c-2c8c-4c85-918c-4f33c393273f)

As you can see in image Above, there is a Pin name for each male pin from the LED, you must follow these so you be able to use this code with perfect!

D1(LED) = D2(Arduino)

A(LED) = D3(Arduino)

F(LED) = D4(Arduino)

D2(LED) = D5(Arduino)

D3(LED) = D6(Arduino)

B(LED) = D7(Arduino)

D4(LED) = D8(Arduino)

G(LED) = D9(Arduino)

C(LED) = D10(Arduino)

DP(LED) = D11(Arduino)

D(LED) = D12(Arduino)

E(LED) = D13(Arduino)

and for the Joystick

![image](https://github.com/user-attachments/assets/d0b4c8d2-9ee9-4899-9b5c-7545d5cdae80)

GND(Joystick) = GND(Arduino)

5V(Joystick) = 5V(Arduino)

VRX(Joystick) = A2(Arduino)

VRY(Joystick) = A1(Arduino)

SW(Joystick) = A0(Arduino)

Note: Maybe you wondering why, because why i told u for use Analog in arduino for joystick SW than Digital? because, you arduino pin would be fulled fill by LED

And you are all set! you ready for use

Now i will give you the control

Note: Selected number = Number that have dot in Top Left Down

Joystick Up = Next Number (reset 0 if More than 9) for selected number

Joystick Down = Previouse Number (goto 9 if less than 0) for selected number

Joystick Right = Change dot position (Number Selector) to next number (Goto first digit if more than forth digit)

Joystick Left = Change dot position (Number Selector) to previous number (Goto Last digit if less than first digit)

Thank you for reading this!

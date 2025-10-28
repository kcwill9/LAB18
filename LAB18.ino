
import time
import random
from gpiozero import LED, Button

# Define GPIO pins
leds = [
    LED(23),  # led0
    LED(4),   # led1
    LED(25),  # led2
    LED(10),  # led3
    LED(17),  # led4
    LED(8),   # led5
    LED(22)   # led6
]
pushButton = Button(7)

def main():
    try:
        while True:
            print("Press the button to roll the dice.")
            number = generateNumber()
            displayNumber(number)
    except KeyboardInterrupt:
        print("\nExiting program.")
        ledsOff()

def generateNumber():
    print("Waiting for button press...")
    pushButton.wait_for_press()
    time.sleep(0.030)  # Debounce delay
    throw = random.randint(1, 6)
    print(f"Dice rolled: {throw}")
    return throw

def displayNumber(number):
    if number == 1:
        leds[3].on()
    elif number == 2:
        leds[5].on()
        leds[1].on()
    elif number == 3:
        leds[5].on()
        leds[1].on()
        leds[3].on()
    elif number == 4:
        leds[5].on()
        leds[1].on()
        leds[0].on()
        leds[6].on()
    elif number == 5:
        leds[0].on()
        leds[1].on()
        leds[3].on()
        leds[5].on()
        leds[6].on()
    elif number == 6:
        leds[5].on()
        leds[1].on()
        leds[0].on()
        leds[6].on()
        leds[2].on()
        leds[4].on()

    time.sleep(1)
    ledsOff()

def ledsOff():
    for led in leds:
        led.off()

if __name__ == "__main__":
    main()

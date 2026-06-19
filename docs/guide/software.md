# Install the Software

{{BOM}}

## Setup Arduino IDE {pagestep}

Install the [Arduino IDE](https://www.arduino.cc/en/software/) for your operating system. Also be sure to install the following libraries:

- [Adafruit SHT31](https://github.com/adafruit/Adafruit_SHT31)
- [U8g2](https://github.com/olikraus/u8g2)

Next, add the Adafruit board support to your Arduino IDE. Open **File → Preferences** and add the following URL to the *Additional Boards Manager URLs* field:

```
https://adafruit.github.io/arduino-board-index/package_adafruit_index.json
```

Then open **Tools → Board → Boards Manager**, search for `Adafruit Feather M4` and install the **Adafruit SAMD Boards** package.

## Install the code {pagestep}

Connect your [Feather M4 Express]{Qty: 1} to your laptop using a [USB A (or C) to micro USB cable]{Qty: 1, Cat: Tool}.
Download the code from `code/prod/` and open the `prod.ino` file in the Arduino IDE.

Select your board: go to **Tools → Board → Adafruit SAMD Boards → Adafruit Feather M4 Express**.
Select the port: **Tools → Port → (the port your Feather is connected to)**.

Finally, click the **Upload** button (right arrow icon) or press **Ctrl+U** to compile and flash the code onto your Feather M4.

[Feather M4 Express]:  ../Parts.yaml#FeatherM4
[USB A (or C) to micro USB cable]:  ../Parts.yaml#USBMicroCable
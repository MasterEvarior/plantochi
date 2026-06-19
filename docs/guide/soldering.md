# Solder

{{BOM}}

## Prepare your workspace {pagestep}

Set up your [Soldering Iron]{Qty: 1, Cat: Tool}, [Solder Wire]{Qty: 1, Cat: Tool}, and [Protoboard]{Qty: 1}. Make sure you have good ventilation (or simply do not care enough for the consequences).

## Solder headers to the Feather M4 {pagestep}

Insert your [Pin Headers]{Qty: 2} into the Feather M4's through-holes. Flip the board over and solder each pin, making sure the headers sit straight and do not touch each other.

## Solder the sensor wires {pagestep}

Cut and strip lengths of [Hook-up Wire]{Qty: 1, Cat: Tool} to connect the [Piezo Buzzer]{Qty: 1}, [LDR Light Dependent Resistor]{Qty: 1}, [Grove Capacitive Moisture Sensor]{Qty: 1}, [OLED Display]{Qty: 1}, and [Temperature Humidity Sensor]{Qty: 1} to the protoboard.

>! **Attention** 
>! 
>! Make the wire rather **too long** than **not long enough**.
>! The case as more than enough space to hide them all.

## Connect everything on the protoboard {pagestep}

Solder the wires and pin headers from the Feather M4 to the [Protoboard], routing the connections to each sensor. Double-check your pinout before soldering each joint.

## Test your soldering {pagestep}

Visually inspect all solder joints for cold joints or bridges. You should also be able to see the readings for each sensonr, aswell as something on the display, if you already installed the software from [the step before](software.md){step}.

[Soldering Iron]: ../Parts.yaml#SolderingIron
[Solder Wire]:  ../Parts.yaml#SolderWire
[Pin Headers]:  ../Parts.yaml#HeaderPins
[Protoboard]:  ../Parts.yaml#ProtoBoard
[Hook-up Wire]:  ../Parts.yaml#Wire
[Piezo Buzzer]:  ../Parts.yaml#PiezoBuzzer
[LDR Light Dependent Resistor]:  ../Parts.yaml#LDR
[Grove Capacitive Moisture Sensor]:  ../Parts.yaml#GroveCapMoistSensor
[OLED Display]:  ../Parts.yaml#OledDisplay
[Temperature Humidity Sensor]:  ../Parts.yaml#TempHumiSensor

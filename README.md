# About

This Library is intended for use with SHT30 Mini module on the Particle Core/Photon platform.

The intention of this library is to make use of the SHT30 mini module with Particle development web IDE as simple as possible for users.

The SHT30 Mini Module from ControlEverything may be purchased [here] [sht30store].

###Developer information
NCD has been designing and manufacturing computer control products since 1995.  We specialize in hardware design and manufacturing of sensory input and output control devices.  We pride ourselves as being the industry leader of computer control relay products as well as sensory reading products.  Our products are proven reliable and we are very excited to support Particle.  For more information on NCD please visit www.controleverything.com

###Requirements
- [SHT30 Mini Module][sht30store].
- Particle Core/Photon module
- Knowledge base for developing and programming with Particle Core/Photon modules.

### Version
1.0.0

### How to use this library

The libary must be imported into your application.  This can be done through the Particle WEB IDE by selecting Libraries, then select the SHT30.  Click Include in App button.  Select the App you want to include the library in.  Finally click Add to this app.  For more information see [Particle's documentation] [sparkIncludeLibrary].

### Example use

Once the Library is included in your applicaiton you should see an include statement at the top like this:
```cpp
//This #include statement was automatically added by the Particle IDE.
#include "SHT30/SHT30.h"
```

Now you need to instanciate an object of the library for use in your application like this:
```cpp
SHT30 sensor;
```

Here is an example use case for the class:
```cpp
// This #include statement was automatically added by the Particle IDE.
#include "SHT30/SHT30.h"

SHT30 sensor;
double humidity;
double temperature;

void setup() {
sensor.setAddress(0);
Particle.variable("Humidity", humidity);
Particle.variable("Temperature", temperature);
}

void loop() {
if(sensor.update()){
humidity = sensor.humidity;
temperature = sensor.temperature;
}
delay(1000);
}
```

###Public accessible methods
```cpp
void setAddress(int a0);
```
>Must be called first before using the object.  This method should also be called any time communication with
>the controller is lost or broken to recover communication  This method accepts one int argument.  This
>tells the Library what address to direct commands to.  a0 representations of the the Address
>jumper on the SHT30 mini module.  If the jumper is
>installed then send a 1, if the jumper is not installed send a 0 like this ```sensor.setAddress(0).```


```cpp
bool update();
```
>This method accepts no arguments.  A call to this method will return trigger a reading of the current Humidiity and Temperature on the SHT30 sensor, if the reading is successful true is returned, if the reading fails for any reason false will be returned.
>

###Public accessible Variables

```cpp
double temperature
```
>This variable is updated during the update function call with the current temperature reading from teh SHT30.  You should call the function update, then if true is returned check this value for the current temperature.  This temperature value will be in degrees C.

```cpp
double humidity
```
>This variable is updated during the update function call with the current humidity reading from teh SHT30.  You should call the function update, then if true is returned check this value for the current humidity.  This humidity value will represent the current relative humidiity as a percentage value.

License
----

GNU
[sparkIncludeLibrary]:https://docs.particle.io/guide/getting-started/build/photon/
[sht30store]:https://www.controleverything.com/content/Humidity?sku=SHT30_I2CS
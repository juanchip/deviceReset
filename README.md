# deviceReset
Implementacion de un código que simula "Desenchufar" un Dispositivo USB en GNU/Linux.

### ¿ Como funciona ?

Cuando tenemos un problema con un dispositivo USB en sistemas GNU/Linux, ya sea que se quedó "Frizado" o bien, no responde a nuestros comandos (Ej, un Mouse, un Arduino, Un Teclado) , podemos utilizar este pequeño script para sacarnos del apuro, por pura comodidad de no desconectar el puerto USB.
El script directamente ataca el control del IO del sistema, borrando todo registro del mismo, induciendo un re-registro del mismo, borrándose todas las configuraciones anteriores y los programas anteriores.

### Requisitos
- GCC

### Instalación
Compilar
```
gcc resetusb.c -o resetusb
```
Permitirle ejecutarse al archivo de salida
```
chmod +x resetusb
```
Utilizar **lsusb -t** para indentificar el dispositivo deseado
```
lsusb -t
/:  Bus 01.Port 1: Dev 1, Class=root_hub, Driver=dwc_otg/1p, 480M
    |__ Port 1: Dev 2, If 0, Class=Hub, Driver=hub/5p, 480M
        |__ Port 1: Dev 3, If 0, Class=Vendor Specific Class, Driver=smsc95x
        |__ Port 2: Dev 4, If 0, Class=Video, Driver=uvcvideo, 480M
        |__ Port 2: Dev 4, If 3, Class=Audio, Driver=snd-usb-audio, 480M
        |__ Port 2: Dev 4, If 1, Class=Video, Driver=uvcvideo, 480M
        |__ Port 2: Dev 4, If 2, Class=Audio, Driver=snd-usb-audio, 480M
        |__ Port 3: Dev 6, If 0, Class=Vendor Specific Class, Driver=ath9k_htc, 

```
Ejecutar el programa con privilegios de administrador (sudo), sustituí el <busID> y el <DeviceID > del dipositivo que necesites

```
sudo ./usbreset /dev/bus/usb/001/006 
```
En este ejemplo ponemos en reset el Dev(DeviceID) 6 en en Port(BusID) 1


### Licencia

GNU General Public License 3.0

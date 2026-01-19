## this demo
friday 2
--this done with ble demo--
VSCODE esp32 demo:
* poorly designed and very confusing console for this  
from platformIO->Open choose "project examples"
choose "expressif 32" as platform
choose "esp32-s3-devkitc-1" for board
in entry which appears, choose "arduino" or "Espidf". Espidf is advanced and weird.  
Next to "Espressif ESP32-S3-DevKitC-1-N8 (8 MB QD, No PSRAM)" click "arduino"  
Then on top click on "installed",then click "expressif 32" then examples tab then do pulldown to desired example.
Then "import" the example. It goes somewhere in /docs ??

# Setting up vscode in ubuntu
```
# stuff to install for vscode on ubuntu
# first do update/upgrade or it fails later
sudo apt update
sudo apt upgrade -y
# install git
apt-get install git
# after installing platformIO plugin, install python
sudo apt install python3-venv

# Set your global name
git config --global user.name "ubuntu17"
# Set your global email
git config --global user.email "ubuntu17@example.com"
```
## need to do this after installing platformIO ubuntu
- from error in Ubuntu message about no access to serial port, then pasted to ai, got this answer
```
# this gets url into the file using -O argument
curl -O https://raw.githubusercontent.com/platformio/platformio-core/develop/platformio/assets/system/99-platformio-udev.rules 
cat 99-platformio-udev.rules 
# apply the file
sudo cp 99-platformio-udev.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules
sudo udevadm trigger
sudo usermod -a -G dialout $USER
# run history and trim off leading command count
history | cut -c 8- > hist_99rules 
```


from orig:  
How to build PlatformIO based project
=====================================

1. [Install PlatformIO Core](https://docs.platformio.org/page/core.html)
2. Download [development platform with examples](https://github.com/platformio/platform-espressif32/archive/develop.zip)
3. Extract ZIP archive
4. Run these commands:

```shell
# Change directory to example
$ cd platform-espressif32/examples/arduino-ble5-advertising

# Build project
$ pio run

# Upload firmware
$ pio run --target upload

# Build specific environment
$ pio run -e esp32-c3-devkitm-1

# Upload firmware for the specific environment
$ pio run -e esp32-c3-devkitm-1 --target upload

# Clean build files
$ pio run --target clean
```
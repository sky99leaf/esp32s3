
at time of writing, this folder has 2 copies of wifi scan demo for esp32s3
Both use "platformIO", not "esp-idf".  

git config --global user.name "username"
git config --global user.email useremail@example.com

VSCODE esp32 demo:
* poorly designed and very confusing console for this  
from platformIO->Open choose "project examples"
choose "expressif 32" as platform
choose "esp32-s3-devkitc-1" for board
in entry which appears, choose "arduino" or "Espidf". Espidf is advanced and weird.  
Next to "Espressif ESP32-S3-DevKitC-1-N8 (8 MB QD, No PSRAM)" click "arduino"  
Then on top click on "installed",then click "expressif 32" then examples tab then do pulldown to desired example.
Then "import" the example. It goes somewhere in /docs ??



Notes:  
* using platformIO with vscode in windows: never got it to work.   
  probably because notbody uses it.  Using WSL (windows system for linux) did
  not work either for platformIO, and lots of error messages.  
* in vscode/platformIO, need to point platformIO to one of the above projects, using filesystem location.  
* in vscode/github, it points to the root folder of the 2 projects.  
* in vscode, File->Open folder of only one of the 2 projects.  




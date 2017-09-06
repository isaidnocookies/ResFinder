# ResFinder
Displays details about active displays attached to your computer. 

To compile:
gcc -o ResFinder -framework CoreFoundation -framework ApplicationServices ResFinder.c

Displays VendorNumberID and Model Number for attached displays. Also, for each display, it displays the associated mode, resolution width, resolution hight, and refresh rate for resolutions compatible with displays.

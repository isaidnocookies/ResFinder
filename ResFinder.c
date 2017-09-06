// gcc -o ResFinder -framework CoreFoundation -framework ApplicationServices ResFinder.c

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>
#include <ApplicationServices/ApplicationServices.h>
#include <CoreGraphics/CoreGraphics.h>

int main() {
	uint32_t displayCount = 16;
	CGDirectDisplayID displays[16];
	CGError error;
	CFArrayRef modes;
	CGDisplayModeRef mode;

	error = CGGetOnlineDisplayList(16, &displays[0], &displayCount);
	if (error == 0) {
		//success
		for (uint32_t i = 0; i < displayCount; i++) {
			if (CGMainDisplayID() == displays[i]) {
				printf("Main display: %x\n", displays[i]);
			} else {
				printf("            : %x\n", displays[i]);
			}
			printf("\t\tVendor: %x , Model: %x\n", CGDisplayVendorNumber(displays[i]), CGDisplayModelNumber(displays[i]));
			modes = CGDisplayCopyAllDisplayModes(displays[i], NULL);
			printf("\t\tMode count: %ld\n", CFArrayGetCount(modes));

			for (CFIndex i = 0; i < CFArrayGetCount(modes); i++) {
				mode = (CGDisplayModeRef)CFArrayGetValueAtIndex(modes, i);
				printf("\t\t%x %zu x %zu %f\n", CGDisplayModeGetIODisplayModeID(mode),
												CGDisplayModeGetWidth(mode),
												CGDisplayModeGetHeight(mode),
												CGDisplayModeGetRefreshRate(mode));
			}

			CFRelease(modes);
		}
	}

	return 0;
}

/* Copyright (C) 2017 HippoSecurity */
#include <stdio.h>
#include "hippo.h"

int main() {

    char* apiKey = "39643166cafe264ab576329aeefa9d1f";

    // 1. initialize library
    int handle = hippo_init(apiKey);
    if (handle < 1) {
        printf("Invalid API Key!\n");
        return 1;
    }

    // 2. get gCode
    char gCode[4 + 1];
    size_t gCodeLen = hippo_get_gcode(handle, gCode, 4);
    if (gCodeLen < 1) {
        printf("Failed to generate gCode!\n");
        return 1;
    }
    printf("Your gCode is: %s\n", gCode);

    // 3. wait for OTP input
    char otp[64];
    printf("Please enter OTP: ");
    scanf("%s", otp);

    // 4. verify OTP
    char* licenseKey = "LICENSE_KEY";
    char* hostId = "112233DDEEFF";
    int licenseCount = 0;
    int valid = hippo_verify_otp(handle, licenseKey, hostId, otp);

    // 5. get license count
    if (valid) {
        licenseCount = hippo_get_license_count(handle);
    }

    // 6. close library
    hippo_done(handle);

    if (licenseCount > 0) {
        printf("License count: %d\n", licenseCount);
        // use licenseCount and continue startup
    } else {
        printf("Invalid license!\n");
        // abort startup
    }
    return 0;
}

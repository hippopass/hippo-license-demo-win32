![HippoLicense](media/logo_round.png)

# HippoLicense Toolkit

HippoLicense demo project for Windows Server

## Prerequisite

Please contact HippoSecurity support to obtain your copy of the shared library:  `hippo-lib.dll`, and copy the binary file into the same folder as your executable file.

## Build and run the demo

Open the demo project in your Visual Studio 2017, build the whole project and `DemoApp.exe` should be generated in `HippoLicense\Debug\` folder.

Copy `hippo-lib.dll` into the same folder and run the executable:

```
C:\hippo-license-demo-win32\HippoLicense\Debug>DemoApp.exe
Your gCode is: 2473
Please enter OTP: 630354
License count: 12
```

It will print out 4-digits gCode and prompt for OTP input. Use the Android demo client to generate OTP and enter here.

## Integration

#### Create new Win32 console application (optional)

* Launch Visual Studio 2017, select `File` > `New` > `Project...` to create a `Win32 Console Application`.
* Copy `hippo.h` header file into your project folder.
* Create a new folder `lib` in your project folder, and copy `hippo-lib.lib` into the `lib` folder.
* Modify project `Properties` > `Linker` > `Input` > `Additional Dependencies`, add `hippo-lib.lib`.
* Modify project `Properties` > `Linker` > `General` > `Additional Library Directories`, add `.\lib`.

#### Modify your application

Copy codes from `demo.c` to your project, remember to modify it to read `License Key` and `Host ID` from your server.

```
char* licenseKey = "LICENSE_KEY";
char* hostId = "112233DDEEFF";
```

## License

MIT © HippoSecurity

#ifndef HIPPO_H
#define HIPPO_H

# ifdef __cplusplus
extern "C"
{
# endif

#ifdef BUILDING_HIPPO_DLL
#define HIPPO_DLL __declspec(dllexport)
#else
#define HIPPO_DLL __declspec(dllimport)
#endif

int HIPPO_DLL hippo_init(char* apiKey);
size_t HIPPO_DLL hippo_get_gcode(int handle, char* buf, size_t len);
int HIPPO_DLL hippo_verify_otp(int handle, char* licenseKey, char* hostId, char* otp);
int HIPPO_DLL hippo_get_license_count(int handle);
void HIPPO_DLL hippo_done(int handle);

# ifdef __cplusplus
}
# endif

#endif /* HIPPO_H */


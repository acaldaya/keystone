#ifndef _PLATFORM_H_
#define _PLATFORM_H_

/* These functions are defined by platform/soc specific objects,
   defined in platform/$PLATFORM/$PLATFORM.c */

/* This fires once FOR EACH sm supported enclave during init of
   enclave metadata. It may not fail currently. */
void platform_init_enclave(struct platform_enclave_data* enclave);

/* This fires once GLOBALLY before any other platform init */
void platform_init_global();

/* This fires once each time an enclave is created by the sm */
void platform_create_enclave(struct platform_enclave_data* enclave);

/* This fires once each time an enclave is destroyed by the sm */
void platform_destroy_enclave(struct platform_enclave_data* enclave);

/* This fires when context switching INTO an enclave from the OS */
void platform_switch_to_enclave(struct platform_enclave_data* enclave);

/* This fires when context switching OUT of an enclave into the OS */
void platform_switch_from_enclave(struct platform_enclave_data* enclave);

/* Future version: This fires when context switching from enclave A to
   enclave B */
// void platform_switch_between_enclaves(platform_enclave_data* enclaveA,
//                                       platform_enclave_data* enclaveB);

/* This is a required feature, it must return 64bits of random data on
   demand and never fail. If it would fail it may power off
   instead. */
uint64_t platform_random();
#endif /* _PLATFORM_H_ */

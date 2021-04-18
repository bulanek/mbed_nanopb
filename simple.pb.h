/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.6-dev */

#ifndef PB_SIMPLE_PB_H_INCLUDED
#define PB_SIMPLE_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _SimpleMessage { 
    uint32_t test_uint32; 
    uint64_t test_uint64; 
    float test_float; 
    char test_string[21]; 
} SimpleMessage;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define SimpleMessage_init_default               {0, 0, 0, ""}
#define SimpleMessage_init_zero                  {0, 0, 0, ""}

/* Field tags (for use in manual encoding/decoding) */
#define SimpleMessage_test_uint32_tag            2
#define SimpleMessage_test_uint64_tag            3
#define SimpleMessage_test_float_tag             4
#define SimpleMessage_test_string_tag            5

/* Struct field encoding specification for nanopb */
#define SimpleMessage_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, UINT32,   test_uint32,       2) \
X(a, STATIC,   REQUIRED, UINT64,   test_uint64,       3) \
X(a, STATIC,   REQUIRED, FLOAT,    test_float,        4) \
X(a, STATIC,   REQUIRED, STRING,   test_string,       5)
#define SimpleMessage_CALLBACK NULL
#define SimpleMessage_DEFAULT NULL

extern const pb_msgdesc_t SimpleMessage_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define SimpleMessage_fields &SimpleMessage_msg

/* Maximum encoded size of messages (where known) */
#define SimpleMessage_size                       44

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif

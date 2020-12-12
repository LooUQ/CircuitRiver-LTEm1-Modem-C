/******************************************************************************
 *  \file ltem1.h
 *  \author Jensen Miller, Greg Terrell
 *  \license MIT License
 *
 *  Copyright (c) 2020 LooUQ Incorporated.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software. THE SOFTWARE IS PROVIDED
 * "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 * LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *****************************************************************************/

#ifndef __LTEM1C_UTIL_H__
#define __LTEM1C_UTIL_H__

#include "ltem1c.h"

#define PROPS_DICT_CNT 12


#define IP_DISPLAY(NUM_IP, STRING_IP) \
char STRING_IP##[16]; \
sprintf(STRING_IP, "%d.%d.%d.%d", NUM_IP##.octet[0] , NUM_IP##.octet[1], NUM_IP##.octet[2], NUM_IP##.octet[3]);


/** 
 *  \brief Union datatype to facilitate display and manipulation of an IPv4 address.
*/
union ip_addr_tag
{
    uint8_t octet[4];
	uint32_t packed;
};

typedef union ip_addr_tag ip_addr_t;


/** 
 *  \brief Struct exposing the properties collection (names and values as c-strings) for a received message.
*/
typedef struct propsDict_tag
{
    uint8_t count;                      ///< During parsing, how many properties (name/value pairs) were found.
    char *names[PROPS_DICT_CNT];   ///< Array of property names.
    char *values[PROPS_DICT_CNT];  ///< Array of property values (as c-strings). Application is responsible for any type conversion.
} propsDict_t;



#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus


char *strToken(char *source, int delimiter, char *token, uint8_t tokenMax);
propsDict_t util_parseStringToPropsDict(char *propsSrc);
char *util_getActionPropValue(const char *propName, propsDict_t props);


/* seems like the only survivor is strToken which is referenced in gnss and network modules, likely move to ltem1c.c and drop util.c */
//ip_addr_t util_parseIpAddr(const char *ipStr);
//void floatToString(float fVal, char *buf, uint8_t bufSz, uint8_t precision);
//const char *strlenSafe(const char *charStr, uint16_t maxSz);


#ifdef __cplusplus
}
#endif // !__cplusplus


#endif  /* !__LTEM1C_UTIL_H__ */
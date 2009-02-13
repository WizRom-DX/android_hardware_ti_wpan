/******************************************************************************\
##                                                                            *
## Unpublished Proprietary and Confidential Information of Texas Instruments  *
## Israel Ltd. Do Not Disclose.                                               *
## Copyright 2008 Texas Instruments Israel Ltd.                               *
## All rights reserved. All unpublished rights reserved.                      *
##                                                                            *
## No part of this work may be used or reproduced in any form or by any       *
## means, or stored in a database or retrieval system, without prior written  *
## permission of Texas Instruments Israel Ltd. or its parent company Texas    *
## Instruments Incorporated.                                                  *
## Use of this work is subject to a license from Texas Instruments Israel     *
## Ltd. or its parent company Texas Instruments Incorporated.                 *
##                                                                            *
## This work contains Texas Instruments Israel Ltd. confidential and          *
## proprietary information which is protected by copyright, trade secret,     *
## trademark and other intellectual property rights.                          *
##                                                                            *
## The United States, Israel  and other countries maintain controls on the    *
## export and/or import of cryptographic items and technology. Unless prior   *
## authorization is obtained from the U.S. Department of Commerce and the     *
## Israeli Government, you shall not export, reexport, or release, directly   *
## or indirectly, any technology, software, or software source code received  *
## from Texas Instruments Incorporated (TI) or Texas Instruments Israel,      *
## or export, directly or indirectly, any direct product of such technology,  *
## software, or software source code to any destination or country to which   *
## the export, reexport or release of the technology, software, software      *
## source code, or direct product is prohibited by the EAR. The subject items *
## are classified as encryption items under Part 740.17 of the Commerce       *
## Control List (�CCL�). The assurances provided for herein are furnished in  *
## compliance with the specific encryption controls set forth in Part 740.17  *
## of the EAR -Encryption Commodities and Software (ENC).                     *
##                                                                            *
## NOTE: THE TRANSFER OF THE TECHNICAL INFORMATION IS BEING MADE UNDER AN     *
## EXPORT LICENSE ISSUED BY THE ISRAELI GOVERNMENT AND THE APPLICABLE EXPORT  *
## LICENSE DOES NOT ALLOW THE TECHNICAL INFORMATION TO BE USED FOR THE        *
## MODIFICATION OF THE BT ENCRYPTION OR THE DEVELOPMENT OF ANY NEW ENCRYPTION.*
## UNDER THE ISRAELI GOVERNMENT'S EXPORT LICENSE, THE INFORMATION CAN BE USED *
## FOR THE INTERNAL DESIGN AND MANUFACTURE OF TI PRODUCTS THAT WILL CONTAIN   *
## THE BT IC.                                                                 *
##                                                                            *
\******************************************************************************/
/*******************************************************************************\
*
*   FILE NAME:      bthal_utils.c
*
*   DESCRIPTION:    This file implements the API of the BTHAL UTILS.
*
*   AUTHOR:         Ronen Levy
*
\*******************************************************************************/


/********************************************************************************
 *
 * Include files
 *
 *******************************************************************************/

#include "bthal_utils.h"
#include "mcp_hal_string.h"
#include "mcp_hal_memory.h"
#include "mcp_hal_misc.h"

/****************************************************************************
 *
 * Constants
 *
 ****************************************************************************/

/****************************************************************************
 *
 * Public Functions
 *
 ***************************************************************************/


/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_Rand()
 *
 *     Called by the stack to generate a random number between
 *     0x0000 and 0xFFFF.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *      void.
 *
 * Returns:
 *     A 16-bit random number.
 */
BTHAL_U16 BTHAL_UTILS_Rand(void)
{
    McpU16  randValue = MCP_HAL_MISC_Rand();

    MCP_HAL_MISC_Srand(randValue);

    return randValue;
}


/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_MemCopy()
 *
 *      Called by the stack to copy memory from one buffer to another.
 *     
 *      This function's implementation could use the ANSI memcpy function.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *      dest [out] - Destination buffer for data.
 *
 *      source [in] - Source buffer for data. "dest" and "source" must not overlap.
 *
 *      numBytes [in] - Number of bytes to copy from "source" to "dest".
 *
 * Returns:
 *      void.
 * 
 */
void BTHAL_UTILS_MemCopy(BTHAL_U8 *dest, const BTHAL_U8 *source, BTHAL_U32 numBytes)
{
    MCP_HAL_MEMORY_MemCopy(dest, source, numBytes);
}


/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_MemCmp()
 *
 *     Called by the stack to compare the bytes in two different buffers.
 *     If the buffers lengths or contents differ, this function returns FALSE.
 *
 *     This function's implementation could use the ANSI memcmp
 *     routine as shown:
 *
 *     return (len1 != len2) ? FALSE : (0 == memcmp(buffer1, buffer2, len2));
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *     buffer1 [in] - First buffer to compare.
 *
 *     len1 [in] - Length of first buffer to compare.
 *
 *     buffer2 [in] - Second buffer to compare.
 *
 *     len2 [in] - Length of second buffer to compare.
 *
 * Returns:
 *     TRUE - The lengths and contents of both buffers match exactly.
 *
 *     FALSE - Either the lengths or the contents of the buffers do not match.
 */
BTHAL_BOOL BTHAL_UTILS_MemCmp(const BTHAL_U8 *buffer1, BTHAL_U16 len1, const BTHAL_U8 *buffer2, BTHAL_U16 len2)
{
    return MCP_HAL_MEMORY_MemCmp(buffer1, len1, buffer2, len2);
}


/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_MemSet()
 *
 *     Fills the destination buffer with the specified byte.
 *
 *     This function's implementation could use the ANSI memset
 *     function.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *     dest [out] - Buffer to fill.
 *
 *     byte [in] - Byte to fill with.
 *
 *     len [in] - Length of the destination buffer.
 *
 * Returns:
 *      void.
 */
void BTHAL_UTILS_MemSet(BTHAL_U8 *dest, BTHAL_U8 byte, BTHAL_U32 len)
{
    MCP_HAL_MEMORY_MemSet(dest, byte, len);
}


/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_StrCmp()
 *
 *    Compares two strings for equality.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *     Str1 [in] - String to compare.
 *
 *     Str2 [in] - String to compare.
 *
 * Returns:
 *     Zero - If strings match.
 *     Non-Zero - If strings do not match.
 */
BTHAL_U8 BTHAL_UTILS_StrCmp(const char *Str1, const char *Str2)
{
    return MCP_HAL_STRING_StrCmp(Str1, Str2);
}


/*---------------------------------------------------------------------------
 * BTHAL_UTILS_StriCmp()
 *
 *     Compares two strings for equality regardless of case.
 *
 * Parameters:
 *     Str1 - String to compare.
 *     Str2 - String to compare.
 *
 * Returns:
 *     Zero - If strings match.
 *     Non-Zero - If strings do not match.
 */
BTHAL_U8 BTHAL_UTILS_StriCmp(const char *Str1, const char *Str2)
{   
    return MCP_HAL_STRING_StriCmp(Str1, Str2);
}

/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_StrLen()
 *
 *      Calculate the length of the string.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *      Str [in]- String to count length.
 *
 * Returns:
 *     Returns length of string.
 */
BTHAL_U16 BTHAL_UTILS_StrLen(const char *Str)
{
    return MCP_HAL_STRING_StrLen(Str);
}


/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_StrCpy()
 *
 *      Copy a string (same as ANSI C strcpy)
 *
 *      The OS_StrCpy function copies StrSource, including the terminating null character, 
 *      to the location specified by StrDest. No overflow checking is performed when strings 
 *      are copied or appended. 
 *
 *      The behavior of OS_StrCpy is undefined if the source and destination strings overlap 
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *      StrDest [out]- Destination string.
 *
 *      StrSource [in]- Source string
 *
 * Returns:
 *     Returns StrDest. No return value is reserved to indicate an error.
 */
char* BTHAL_UTILS_StrCpy(char* StrDest, const char *StrSource)
{
    return MCP_HAL_STRING_StrCpy(StrDest, StrSource);
}


/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_StrnCpy()
 *
 *      Copy characters of one string to another (same as ANSI C strncpy)
 *
 *      The OS_StrnCpy function copies the initial Count characters of StrSource to StrDest and 
 *      returns StrDest. If Count is less than or equal to the length of StrSource, a null character 
 *      is not appended automatically to the copied string. If Count is greater than the length of 
 *      StrSource, the destination string is padded with null characters up to length Count. 
 *
 *      The behavior of OS_StrnCpy is undefined if the source and destination strings overlap.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *      StrDest [out] - Destination string.
 *
 *      StrSource [in] - Source string
 *
 *      Count - Number of characters to be copied
 *
 * Returns:
 *     Returns strDest. No return value is reserved to indicate an error.
 */
char* BTHAL_UTILS_StrnCpy(char* StrDest, const char *StrSource, BTHAL_U32 Count)
{
    return MCP_HAL_STRING_StrnCpy(StrDest, StrSource, Count);
}


/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_AtoU32()
 *
 *    Convert strings to double  (same as ANSI C atoi)
 *
 *    The BTHAL_UTILS_AtoU32 function converts a character string to an integer value.
 *    The function do not recognize decimal points or exponents.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *     string [in] - String to be converted which has the following form:
 *
 *    [whitespace][sign][digits]
 *
 *    Where whitespace consists of space and/or tab characters, which are ignored; 
 *    sign is either plus (+) or minus (�); and digits are one or more decimal digits. 
 *
 * Returns:
 *    A U32 value produced by interpreting the input characters as a number.
 *    The return value is 0 if the input cannot be converted to a value of that type. 
 *    The return value is undefined in case of overflow.
 */
BTHAL_U32 BTHAL_UTILS_AtoU32(const char *string)
{
    return MCP_HAL_MISC_AtoU32(string);
}

/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_StrCat()
 *
 *      Append a string (same as ANSI C strcat)
 *
 *      The OS_StrrChr function finds the last occurrence of c (converted to char) in string. 
 *      The search includes the terminating null character.
 *      The OS_StrCat function appends strSource to strDest and terminates the resulting string 
 *      with a null character. The initial character of strSource overwrites the terminating null 
 *      character of strDest. No overflow checking is performed when strings are copied or 
 *      appended. The behavior of OS_StrCat is undefined if the source and destination strings 
 *      overlap
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *      strDest [in] - Null-terminated destination string.
 *
 *      strSource [in] - Null-terminated source string
 *
 * Returns:
 *      Returns the destination string (strDest). No return value is reserved to indicate an error.
 */
char *BTHAL_UTILS_StrCat(char *strDest, const char *strSource)
{
    return MCP_HAL_STRING_StrCat(strDest, strSource);
}


/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_StrrChr()
 *
 *      Scan a string for the last occurrence of a character (same as ANSI C strrchr).
 *
 *      The BTHAL_UTILS_StrrChr function finds the last occurrence of c (converted to char) in string. 
 *      The search includes the terminating null character.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *      Str [in] - tNull-terminated string to search
 *
 *      c [in] - Character to be located.
 *
 * Returns:
 *  
 *      Returns a pointer to the last occurrence of c in Str, or NULL if c is not found.
 */
char *BTHAL_UTILS_StrrChr(const char *Str, BTHAL_S32 c)
{
    return MCP_HAL_STRING_StrrChr(Str, c);
}


/****************************************************************************
 *
 * Debugging functions
 *
 ****************************************************************************/
  /*---------------------------------------------------------------------------
 * BTHAL_UTILS_Assert()
 *
 *     Called by the stack to indicate that an assertion failed. BTHAL_UTILS_Assert
 *     should display the failed expression and the file and line number
 *     where the expression occurred.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *     expression [in] - A string containing the failed expression.
 *
 *     file [in] - A string containing the file in which the expression occurred.
 *
 *     line [in] - The line number that tested the expression.
 *
 * Returns:
 *      void.
 */
void BTHAL_UTILS_Assert(const char *expression, const char *file, BTHAL_U16 line)
{
#if XA_DEBUG == XA_ENABLED
    MCP_HAL_MISC_Assert(expression, file, line);
#endif /* XA_DEBUG == XA_ENABLED */
}

/*---------------------------------------------------------------------------
 * BTHAL_UTILS_StriCmpUtf8()
 *
 *     Compares two strings for equality regardless of case.
 *
 * Parameters:
 *     Str1 - String to compare.
 *     Str2 - String to compare.
 *
 * Returns:
 *     Zero - If strings match.
 *     Non-Zero - If strings do not match.
 */
BTHAL_S32 BTHAL_UTILS_StriCmpUtf8(const BthalUtf8 *Str1, const BthalUtf8 *Str2)
{   
    return MCP_HAL_STRING_StriCmpUtf8(Str1, Str2);
}

/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_StrLenUtf8()
 *
 * Brief: 
 *      Calculate the length (number of bytes) in the 0-terminated string.
 *      String can be in UTF-8 format as well.
 *
 * Description: 
 *      Calculate the length (number of bytes) in the 0-terminated string.
 *      String can be in UTF-8 format as well.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *      Str [in]- String to count length (UTF-8 format)
 *
 * Returns:
 *     Returns length of string.(number of bytes)
 */
BTHAL_U16 BTHAL_UTILS_StrLenUtf8(const BthalUtf8 *Str)
{
    return MCP_HAL_STRING_StrLenUtf8(Str);
}

/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_StrCmpUtf8()
 *
 * Brief: 
 *      Compares two strings for equality.
 * 
 * Description: 
 *      Compares two strings for equality.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *     Str1 [in] - String to compare.
 *
 *     Str2 [in] - String to compare.
 *
 * Returns:
 *     Zero - If strings match.
 *     Non-Zero - If strings do not match.
 */
BTHAL_U8 BTHAL_UTILS_StrCmpUtf8(const BthalUtf8 *Str1, const BthalUtf8 *Str2)
{
    return MCP_HAL_STRING_StrCmpUtf8(Str1, Str2);
}

/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_StrnCpyUtf8()
 *
 * Brief: 
 *      Copy characters of one string to another (same as ANSI C strncpy)
 *      Strings can be in UTF-8 format as well.
 *
 * Description: 
 *      Copy characters of one string to another (same as ANSI C strncpy)
 *      Strings can be in UTF-8 format as well.
 *
 *      The BTHAL_UTILS_StrnCpyUtf8 function copies the initial Count characters of StrSource to StrDest and 
 *      returns StrDest. If Count is less than or equal to the length of StrSource, a null character 
 *      is not appended automatically to the copied string. If Count is greater than the length of 
 *      StrSource, the destination string is padded with null characters up to length Count. 
 *
 *      The behavior of OS_StrnCpy is undefined if the source and destination strings overlap.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *      StrDest [out] - Destination string.
 *
 *      StrSource [in] - Source string
 *
 *      Count - Number of bytes to be copied
 *
 * Returns:
 *     Returns strDest. No return value is reserved to indicate an error.
 */
BthalUtf8* BTHAL_UTILS_StrnCpyUtf8(BthalUtf8* StrDest, const BthalUtf8 *StrSource, BTHAL_U32 Count)
{
    return MCP_HAL_STRING_StrnCpyUtf8(StrDest, StrSource, Count);
}


/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_StrCatUtf8()
 *
 * Brief: 
 *      Append a string (same as ANSI C strcat)
 *
 * Description: 
 *      Append a string (same as ANSI C strcat)
 *
 *      The OS_StrrChr function finds the last occurrence of c (converted to char) in string. 
 *      The search includes the terminating null character.
 *      The OS_StrCat function appends strSource to strDest and terminates the resulting string 
 *      with a null character. The initial character of strSource overwrites the terminating null 
 *      character of strDest. No overflow checking is performed when strings are copied or 
 *      appended. The behavior of OS_StrCat is undefined if the source and destination strings 
 *      overlap
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *      strDest [in] - Null-terminated destination string.
 *
 *      strSource [in] - Null-terminated source string
 *
 * Returns:
 *      Returns the destination string (strDest). No return value is reserved to indicate an error.
 */
BthalUtf8 *BTHAL_UTILS_StrCatUtf8(BthalUtf8 *strDest, const BthalUtf8 *strSource)
{
    return MCP_HAL_STRING_StrCatUtf8(strDest, strSource);
}

/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_StrrChrUtf8()
 *
 * Brief: 
 *      Scan a string for the last occurrence of a character (same as ANSI C strrchr).
 *
 * Description:
 *      Scan a string for the last occurrence of a character (same as ANSI C strrchr).
 *      The string is in UTF-8 format, and so this fucntion will only work for
 *      finding an ASCII character in the range of 0x01 to 0x7F
 *
 *      The BTHAL_UTILS_StrrChr function finds the last occurrence of c (converted to char) in string. 
 *      The search includes the terminating null character.
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *      Str [in] - tNull-terminated string to search
 *
 *      c [in] - Character to be located.
 *
 * Returns:
 *  
 *      Returns a pointer to the last occurrence of c in Str, or NULL if c is not found.
 */
BthalUtf8 *BTHAL_UTILS_StrrChrUtf8(const BthalUtf8 *Str, BTHAL_U32 c)
{
    return MCP_HAL_STRING_StrrChrUtf8(Str, c);
}

/*-------------------------------------------------------------------------------
 * BTHAL_UTILS_StrCpyUtf8()
 *
 *      Copy a string (same as ANSI C strcpy)
 *
 *      The OS_StrCpyUtf8 function copies StrSource, including the terminating null character, 
 *      to the location specified by StrDest. No overflow checking is performed when strings 
 *      are copied or appended. 
 *
 *      The behavior of OS_StrCpy is undefined if the source and destination strings overlap 
 *
 * Type:
 *      Synchronous
 *
 * Parameters:
 *      StrDest [out]- Destination string.
 *
 *      StrSource [in]- Source string
 *
 * Returns:
 *     Returns StrDest. No return value is reserved to indicate an error.
 */
BthalUtf8* BTHAL_UTILS_StrCpyUtf8(BthalUtf8* StrDest, const BthalUtf8 *StrSource)
{
    return MCP_HAL_STRING_StrCpyUtf8(StrDest, StrSource);
}


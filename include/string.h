/**
 * file string.h
 * @brief 
 * author He Xin, hexin900110@163.com
 * version 1.0
 * date 2019-02-04
 */


#ifndef _STRING_H_
#define _STRING_H_

#include <types.h>

/**
 * @brief memcpy 
 *
 * @param dst
 * @param src
 * @param len
 */
static inline void memcpy(void *dst, const void *src, uint32_t *len)
{
	char *ds = (char *)dst;
	char *sc = (char *)src;

	while(len--) {
		*ds++ = *sc++;
	}
}

/**
 * @brief memset 
 *
 * @param dst
 * @param val
 * @param len
 */
static inline void memset(void *dst, int val, uint32_t len)
{
	char *ds = (char *)dst;

	while (len--) {
		*ds++ = val;	
	}
}

/**
 * @brief bzero 
 *
 * @param dst
 * @param len
 */
static inline void bzero(void *dst, uint32_t len)
{
	char *ds = (char *)dst;

	while(len--) {
		*ds++ = 0;
	}
}

/**
 * @brief strcmp 
 *
 * @param str1
 * @param str2
 *
 * @return 
 */
static inline int32_t strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && (*str1 == *str2)) {
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}

/**
 * @brief strcpy 
 *
 * @param dest
 * @param src
 *
 * @return 
 */
static inline char * strcpy(char *dest, const char *src)
{
	char *ret = dest;

	while (*src) {
		*dest++ = *src++;
	}

	*dest = '\0';

	return ret;
}

/**
 * @brief strcat 
 *
 * @param desc
 * @param src
 *
 * @return 
 */
static inline char * strcat(char *desc, const char *src)
{
	char *ret = desc;
	while (*desc) {
		desc++;
	}

	while ((*desc++ = *src++)) {

	}

	return ret;
}

/**
 * @brief strlen 
 *
 * @param src
 *
 * @return 
 */
static inline int32_t strlen(const char *src)
{
	const char *ptr = src;
	while (*ptr) {
		ptr++;
	}

	return (ptr - src);
}


#endif               /*  _STRING_H_  */

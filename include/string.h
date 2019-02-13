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
	int8_t *ds = (int8_t *)dst;
	int8_t *sc = (int8_t *)src;

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
static inline void memset(void *dst, uint8_t val, uint32_t len)
{
	int8_t *ds = (int8_t *)dst;

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
	int8_t *ds = (int8_t *)dst;

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
static inline int32_t strcmp(const int8_t *str1, const int8_t *str2)
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
static inline int8_t *strcpy(int8_t *dest, const int8_t *src)
{
	int8_t *ret = dest;

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
static inline int8_t *strcat(int8_t *desc, const int8_t *src)
{
	int8_t *ret = desc;
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
static inline int32_t strlen(const int8_t *src)
{
	const int8_t *ptr = src;
	while (*ptr) {
		ptr++;
	}

	return (ptr - src);
}


#endif               /*  _STRING_H_  */

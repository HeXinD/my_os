/**
 * file vargs.h
 * @brief 
 * author He Xin, hexin900110@163.com
 * version 1.0
 * date 2019-02-13
 */
#ifndef _VARGS_H_
#define _VARGS_H_

typedef __builtin_va_list va_list;

#define va_start(ap, last)         (__builtin_va_start(ap, last))
#define va_arg(ap, type)           (__builtin_va_arg(ap, type))
#define va_end(ap) 

#endif

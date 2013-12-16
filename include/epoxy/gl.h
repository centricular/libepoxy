/*
 * Copyright © 2013 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/** @file gl.h
 *
 * Provides an implementation of a GL dispatch layer using either
 * global function pointers or a hidden vtable.
 */

#ifndef __EPOXY_GL_H
#define __EPOXY_GL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#if defined(__gl_h_) || defined(__glext_h_)
#error epoxy/gl.h must be included before (or in place of) GL/gl.h
#else
#define __gl_h_
#define __glext_h_
#endif

#ifndef _WIN32
/* APIENTRY and GLAPIENTRY are not used on Linux or Mac. */
#define APIENTRY
#define GLAPIENTRY
#define GLAPI
#else
#ifndef APIENTRY
#define APIENTRY __stdcall
#endif

#ifndef GLAPIENTRY
#define GLAPIENTRY APIENTRY
#endif

#ifndef GLAPI
#define GLAPI extern
#endif
#endif /* _WIN32 */

#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif

#ifndef GLAPIENTRYP
#define GLAPIENTRYP GLAPIENTRY *
#endif

#include "epoxy/gl_generated.h"

bool epoxy_has_gl_extension(const char *extension);
bool epoxy_is_desktop_gl(void);
int epoxy_gl_version(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __EPOXY_GL_H */

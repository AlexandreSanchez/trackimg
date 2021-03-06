/*
 * Copyright (c) 2014, INSA of Rennes
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *   * Neither the name of INSA Rennes nor the names of its
 *     contributors may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 * WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * @author Alexandre Sanchez <alexandre.sanchez@insa-rennes.fr>
 *
 */

#ifndef _TRACKIMG_TRACE_H_
#define _TRACKIMG_TRACE_H_

#include "trackimg.h"

#define arrayCopy(DST,SRC,LEN) \
            { size_t TMPSZ = sizeof(*(SRC)) * (LEN); \
              if ( ((DST) = malloc(TMPSZ)) != NULL ) \
                memcpy((DST), (SRC), TMPSZ); }

static const char *TRACKIMG_ERRORS_TXT[TRACKIMG_ERR_SIZE] = {
    "",
    "Bad arguments. Please check usage print.",
    "Arg value for -n is not valide.",
    "Arg value for -m is not valide.",
    "Arg value for -v is not valide.",
    "Mandatory argument missing. Please check usage print.",
    "Cannot open input file."
};

extern verbose_level_et verbose_level;

void set_trace_level(verbose_level_et level);

/**
 *
 */
void print_trackimg_error(trackimgmap_error_et error);

/**
 *
 */
bool check_verbosity(verbose_level_et level);

/**
 *
 */
void print_trackimg_trace(verbose_level_et level, const char *trace, ...);

#endif  /* _TRACKIMG_TRACE_H_ */

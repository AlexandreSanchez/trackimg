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

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "trace.h"

verbose_level_et verbose_level = TRACKIMG_VL_QUIET;

void set_trace_level(verbose_level_et level) {
    verbose_level = level;
}

/********************************************************************************************
 *
 * Trackimg utils functions
 *
 ********************************************************************************************/

void print_trackimg_error(trackimgmap_error_et error) {
    if (error != TRACKIMG_OK && error < TRACKIMG_ERR_SIZE) {
        fprintf(stderr,"Trackimg : ERROR : %s\n", TRACKIMG_ERRORS_TXT[error]);
    }
}

void check_trackimg_error(trackimgmap_error_et error) {
    if (error != TRACKIMG_OK) {
        print_trackimg_error(error);
        exit(error);
    }
}

bool check_verbosity(verbose_level_et level) {
    return level<=verbose_level;
}

void print_trackimg_trace(verbose_level_et level, const char *trace, ...) {
    va_list args;
    assert(trace != NULL);

    va_start (args, trace);

    if (level <= verbose_level) {
        vprintf(trace, args);
        printf("\n");
        fflush(stdout);
    }

    va_end (args);
}

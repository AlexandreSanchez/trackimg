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

#include <iostream>
#include <omp.h>

#include "trackimg.h"
#include "options.h"
#include "trace.h"

options::options() {
    m_nbProcessors = 1;
    m_verboseLevel = TRACKIMG_VL_QUIET;
    m_inputDirectory = "/home/asanchez/sequences/videodata/datasets/animal/";
    m_objPos[0] = 153;
    m_objPos[1] = 4;
    m_objSize[0] = 41;
    m_objSize[1] = 30;
}

void options::print(){
    if (m_verboseLevel != TRACKIMG_VL_QUIET) {
        cout << "Options are :" << endl;
        cout << "   + Video dataset        : " << m_inputDirectory << endl;
        cout << "   + Number of processors : " << m_nbProcessors << " (Max processors: " << omp_get_num_procs() << ")" << endl;
        cout << "   + Verbosity level      : " << m_verboseLevel << endl;
    }
}

void options::setNbProcessors(int arg_value){
    m_nbProcessors = arg_value;
    omp_set_num_threads(m_nbProcessors);
}

void options::setVerboseLevel(char* arg_value){
    if (arg_value == NULL) {
        m_verboseLevel = TRACKIMG_VL_VERBOSE_1;
    } else {
        int trace_level = atoi(arg_value);
        if (trace_level < 1 || trace_level > TRACKIMG_VL_VERBOSE_2-TRACKIMG_VL_QUIET) {
            print_trackimg_error(TRACKIMG_ERR_BAD_ARGS_VERBOSE);
            exit(TRACKIMG_ERR_BAD_ARGS_VERBOSE);
        }
        m_verboseLevel = TRACKIMG_VL_QUIET+trace_level;
    }
}

void options::setInputDirectory(string arg_value){
    m_inputDirectory = arg_value;
}

int options::getNbProcessors() {
    return m_nbProcessors;
}

int options::getVerboseLevel() {
    return m_verboseLevel;
}

string options::getInputDirectory() {
    return m_inputDirectory;
}

int options::getObjtPos(int i) {
    return m_objPos[i];
}

int options::getObjtSize(int i) {
    return m_objSize[i];
}

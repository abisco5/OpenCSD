/*
 * \file       raw_frame_printer.h
 * \brief      Reference CoreSight Trace Decoder : 
 * 
 * \copyright  Copyright (c) 2015, ARM Limited. All Rights Reserved.
 */

/* 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, 
 * this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice, 
 * this list of conditions and the following disclaimer in the documentation 
 * and/or other materials provided with the distribution. 
 * 
 * 3. Neither the name of the copyright holder nor the names of its contributors 
 * may be used to endorse or promote products derived from this software without 
 * specific prior written permission. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 'AS IS' AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND 
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */ 

#ifndef ARM_RAW_FRAME_PRINTER_H_INCLUDED
#define ARM_RAW_FRAME_PRINTER_H_INCLUDED

#include "rctdl.h"
#include "item_printer.h"

#include <string>
#include <sstream>

class RawFramePrinter : public ITrcRawFrameIn, public ItemPrinter
{
public:
    RawFramePrinter() {};
    RawFramePrinter(rctdlMsgLogger *pMsgLogger);
    virtual ~RawFramePrinter() {};

    virtual rctdl_err_t TraceRawFrameIn(  const rctdl_datapath_op_t op, 
                                                const rctdl_trc_index_t index, 
                                                const rctdl_rawframe_elem_t frame_element, 
                                                const int dataBlockSize, 
                                                const uint8_t *pDataBlock,
                                                const uint8_t traceID);

private:
    void createDataString(const int dataSize, const uint8_t *pData, int bytesPerLine, std::string &dataStr);

};

inline RawFramePrinter::RawFramePrinter(rctdlMsgLogger *pMsgLogger)
{
    setMessageLogger(pMsgLogger);
}


#endif // ARM_RAW_FRAME_PRINTER_H_INCLUDED

/* End of File raw_frame_printer.h */
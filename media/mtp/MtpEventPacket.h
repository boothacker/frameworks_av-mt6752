/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _MTP_EVENT_PACKET_H
#define _MTP_EVENT_PACKET_H

#include "MtpPacket.h"
#include "mtp.h"

namespace android {

class MtpEventPacket : public MtpPacket {

public:
                        MtpEventPacket();
    virtual             ~MtpEventPacket();

#ifdef MTP_DEVICE
    // write our data to the given file descriptor
    int                 write(int fd);
#endif

#ifdef MTP_HOST
    // read our buffer from the given endpoint
    int                 read(struct usb_endpoint *ep);
#endif

    inline MtpEventCode     getEventCode() const { return getContainerCode(); }
    inline void             setEventCode(MtpEventCode code)
                                                     { return setContainerCode(code); }
};

}; // namespace android

#endif // _MTP_EVENT_PACKET_H

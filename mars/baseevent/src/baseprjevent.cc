// Tencent is pleased to support the open source community by making Mars available.
// Copyright (C) 2016 THL A29 Limited, a Tencent company. All rights reserved.

// Licensed under the MIT License (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://opensource.org/licenses/MIT

// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
// either express or implied. See the License for the specific language governing permissions and
// limitations under the License.

/*
 * baseprjevent.cpp
 *
 *  Created on: 2014-7-7
 *      Author: yerungui
 */

#include "mars/baseevent/baseprjevent.h"

boost::signals2::signal<void()>& GetSignalOnCreate() {
    static boost::signals2::signal<void()> SignalOnCreate;
    return SignalOnCreate;
}

boost::signals2::signal<void(int _encoder_version)>& GetSignalOnInitBeforeOnCreate() {
    static boost::signals2::signal<void(int _encoder_version)> SignalOnInitBeforeOnCreate;
    return SignalOnInitBeforeOnCreate;
}

boost::signals2::signal<void(int _encoder_version, std::string _encoder_name)>& GetSignalOnInitBeforeOnCreateV2() {
    static boost::signals2::signal<void(int _encoder_version, std::string _encoder_name)> SignalOnInitBeforeOnCreateV2;
    return SignalOnInitBeforeOnCreateV2;
}

boost::signals2::signal<void()>& GetSignalOnDestroy() {
    static boost::signals2::signal<void()> SignalOnDestroy;
    return SignalOnDestroy;
}

boost::signals2::signal<void(int _sig)>& GetSignalOnSingalCrash() {
    static boost::signals2::signal<void(int _sig)> SignalOnSingalCrash;
    return SignalOnSingalCrash;
}

boost::signals2::signal<void()>& GetSignalOnExceptionCrash() {
    static boost::signals2::signal<void()> SignalOnExceptionCrash;
    return SignalOnExceptionCrash;
}

boost::signals2::signal<void(bool _isForeground)>& GetSignalOnForeground() {
    static boost::signals2::signal<void(bool _isForeground)> SignalOnForeground;
    return SignalOnForeground;
}

boost::signals2::signal<void()>& GetSignalOnNetworkChange() {
    static boost::signals2::signal<void()> SignalOnNetworkChange;
    return SignalOnNetworkChange;
}

boost::signals2::signal<void(const char* _tag, int64_t _send, int64_t _recv)>& GetSignalOnNetworkDataChange() {
    static boost::signals2::signal<void(const char* _tag, int64_t _send, int64_t _recv)> SignalOnNetworkDataChange;
    return SignalOnNetworkDataChange;
}

boost::signals2::signal<void(int64_t _id)>& GetSignalOnAlarm() {
    static boost::signals2::signal<void(int64_t _id)> SignalOnAlarm;
    return SignalOnAlarm;
}

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
 *   simple_ipport_sort.h
 *   network
 *
 *   Created by liucan on 14-6-16.
 *   Copyright (c) 2014 Tencent. All rights reserved.
 */

#ifndef STN_SRC_SIMPLE_IPPORT_SORT_H_
#define STN_SRC_SIMPLE_IPPORT_SORT_H_

#include <deque>
#include <map>
#include <string>
#include <vector>

#include "mars/boot/context.h"
#include "mars/comm/thread/lock.h"
#include "mars/comm/tickcount.h"
#include "mars/comm/tinyxml2.h"
#include "mars/stn/stn.h"

namespace mars {
namespace stn {

struct BanItem;

class SimpleIPPortSort {
 public:
    SimpleIPPortSort(boot::Context* _context);
    ~SimpleIPPortSort();

    void InitHistory2BannedList(bool _savexml);
    void RemoveBannedList(const std::string& _ip);
    void Update(const std::string& _ip, uint16_t _port, bool _is_success);

    void SortandFilter(std::vector<IPPortItem>& _items, int _needcount, bool _use_IPv6) const;

    void AddServerBan(const std::string& _ip);

 private:
    void __LoadXml();
    void __SaveXml();
    void __RemoveTimeoutXml();

    std::vector<BanItem>::iterator __FindBannedIter(const std::string& _ip, uint16_t _port) const;
    bool __IsBanned(std::vector<BanItem>::iterator _iter) const;
    bool __IsBanned(const std::string& _ip, uint16_t _port) const;
    void __UpdateBanList(bool _isSuccess, const std::string& _ip, uint16_t _port);
    bool __CanUpdate(const std::string& _ip, uint16_t _port, bool _is_success) const;

    void __FilterbyBanned(std::vector<IPPortItem>& _items) const;
    void __SortbyBanned(std::vector<IPPortItem>& _items, bool _use_IPv6) const;
    bool __IsServerBan(const std::string& _ip) const;
    bool __IsV6Ip(const IPPortItem& item) const;
    void __PickIpItemRandom(std::vector<IPPortItem>& _items,
                            std::deque<IPPortItem>& _items_history,
                            std::deque<IPPortItem>& _items_new) const;
    bool __IsIPv6(const std::string& _ip);

 private:
    SimpleIPPortSort(const SimpleIPPortSort&);
    SimpleIPPortSort& operator=(const SimpleIPPortSort&);

 private:
    boot::Context* context_;
    std::string hostpath_;
    tinyxml2::XMLDocument recordsxml_;

    mutable comm::Mutex mutex_;
    mutable std::vector<BanItem> _ban_fail_list_;
    mutable std::map<std::string, uint64_t> _server_bans_;

    uint8_t IPv6_ban_flag_;
    uint8_t IPv4_ban_flag_;
    bool ban_v6_;
};

}  // namespace stn
}  // namespace mars
#endif  // STN_SRC_SIMPLE_IPPORT_SORT_H_

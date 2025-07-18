// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _FASTDDS_TCP_CHANNEL_RESOURCE_BASIC_
#define _FASTDDS_TCP_CHANNEL_RESOURCE_BASIC_

#include <mutex>
#include <asio.hpp>
#include <rtps/transport/TCPChannelResource.h>

namespace eprosima {
namespace fastdds {
namespace rtps {

class TCPChannelResourceBasic : public TCPChannelResource
{
    asio::io_context& context_;

    std::mutex send_mutex_;
    std::shared_ptr<asio::ip::tcp::socket> socket_;

public:

    // Constructor called when trying to connect to a remote server
    TCPChannelResourceBasic(
            TCPTransportInterface* parent,
            asio::io_context& context,
            const Locator& locator,
            uint32_t maxMsgSize);

    // Constructor called when local server accepted connection
    TCPChannelResourceBasic(
            TCPTransportInterface* parent,
            asio::io_context& context,
            std::shared_ptr<asio::ip::tcp::socket> socket,
            uint32_t maxMsgSize);

    virtual ~TCPChannelResourceBasic();

    void connect(
            const std::shared_ptr<TCPChannelResource>& myself) override;

    void disconnect() override;

    uint32_t read(
            octet* buffer,
            std::size_t size,
            asio::error_code& ec) override;

    size_t send(
            const octet* header,
            size_t header_size,
            const std::vector<NetworkBuffer>& buffers,
            uint32_t total_bytes,
            asio::error_code& ec) override;

    // Throwing asio calls
    asio::ip::tcp::endpoint remote_endpoint() const override;
    asio::ip::tcp::endpoint local_endpoint() const override;

    // Non-throwing asio calls
    asio::ip::tcp::endpoint remote_endpoint(
            asio::error_code& ec) const override;
    asio::ip::tcp::endpoint local_endpoint(
            asio::error_code& ec) const override;

    void set_options(
            const TCPTransportDescriptor* options) override;

    void cancel() override;
    void close() override;
    void shutdown(
            asio::socket_base::shutdown_type what) override;

    inline std::shared_ptr<asio::ip::tcp::socket> socket()
    {
        return socket_;
    }

private:

    TCPChannelResourceBasic(
            const TCPChannelResourceBasic&) = delete;
    TCPChannelResourceBasic& operator =(
            const TCPChannelResourceBasic&) = delete;
};


} // namespace rtps
} // namespace fastdds
} // namespace eprosima

#endif // _FASTDDS_TCP_CHANNEL_RESOURCE_BASIC_

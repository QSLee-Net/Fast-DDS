// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/**
 * @file ReaderLocator.hpp
 */

#ifndef FASTDDS_RTPS_WRITER__READERLOCATOR_HPP
#define FASTDDS_RTPS_WRITER__READERLOCATOR_HPP

#include <vector>

#include <fastdds/rtps/common/Guid.hpp>
#include <fastdds/rtps/common/Locator.hpp>
#include <fastdds/rtps/common/LocatorSelectorEntry.hpp>
#include <fastdds/rtps/common/SequenceNumber.hpp>
#include <fastdds/rtps/messages/RTPSMessageSenderInterface.hpp>

#include <rtps/reader/LocalReaderPointer.hpp>

namespace eprosima {
namespace fastdds {
namespace rtps {

class RTPSParticipantImpl;
class RTPSWriter;
class BaseReader;
class IDataSharingNotifier;

/**
 * Class ReaderLocator, contains information about a remote reader, without saving its state.
 * It also implements RTPSMessageSenderInterface, so it can be used when separate sending is enabled.
 * @ingroup WRITER_MODULE
 */
class ReaderLocator : public RTPSMessageSenderInterface
{
public:

    virtual ~ReaderLocator() = default;

    /**
     * Construct a ReaderLocator.
     *
     * @param owner                   Pointer to the RTPSWriter creating this object.
     * @param max_unicast_locators    Maximum number of unicast locators to hold.
     * @param max_multicast_locators  Maximum number of multicast locators to hold.
     */
    ReaderLocator(
            RTPSWriter* /*owner*/,
            size_t /*max_unicast_locators*/,
            size_t /*max_multicast_locators*/)
    {
    }

    LocatorSelectorEntry* general_locator_selector_entry()
    {
        return nullptr;
    }

    LocatorSelectorEntry* async_locator_selector_entry()
    {
        return nullptr;
    }

    const GUID_t& remote_guid() const
    {
        return remote_guid_;
    }

    /**
     * Try to start using this object for a new matched reader.
     *
     * @param remote_guid         GUID of the remote reader.
     * @param unicast_locators    Unicast locators of the remote reader.
     * @param multicast_locators  Multicast locators of the remote reader.
     * @param expects_inline_qos  Whether remote reader expects to receive inline QoS.
     *
     * @return false when this object was already started, true otherwise.
     */
    bool start(
            const GUID_t& /*remote_guid*/,
            const ResourceLimitedVector<Locator_t>& /*unicast_locators*/,
            const ResourceLimitedVector<Locator_t>& /*multicast_locators*/,
            bool /*expects_inline_qos*/)
    {
        return true;
    }

    bool start(
            const GUID_t& /*remote_guid*/,
            const ResourceLimitedVector<Locator_t>& /*unicast_locators*/,
            const ResourceLimitedVector<Locator_t>& /*multicast_locators*/,
            bool /*expects_inline_qos*/,
            bool /*is_datasharing*/)
    {
        return true;
    }

    /**
     * Try to update information of this object.
     *
     * @param unicast_locators    Unicast locators of the remote reader.
     * @param multicast_locators  Multicast locators of the remote reader.
     * @param expects_inline_qos  Whether remote reader expects to receive inline QoS.
     *
     * @return true when information has changed, false otherwise.
     */
    bool update(
            const ResourceLimitedVector<Locator_t>& /*unicast_locators*/,
            const ResourceLimitedVector<Locator_t>& /*multicast_locators*/,
            bool /*expects_inline_qos*/)
    {
        return true;
    }

    /**
     * Try to stop using this object for an unmatched reader.
     *
     * @param remote_guid  GUID of the remote reader.
     *
     * @return true if this object was started for remote_guid, false otherwise.
     */
    bool stop(
            const GUID_t& /*remote_guid*/)
    {
        return true;
    }

    bool stop()
    {
        return true;
    }

    /**
     * Check if the destinations managed by this sender interface have changed.
     *
     * @return true if destinations have changed, false otherwise.
     */
    bool destinations_have_changed() const override
    {
        return false;
    }

    /**
     * Get a GUID prefix representing all destinations.
     *
     * @return When all the destinations share the same prefix (i.e. belong to the same participant)
     * that prefix is returned. When there are no destinations, or they belong to different
     * participants, c_GuidPrefix_Unknown is returned.
     */
    GuidPrefix_t destination_guid_prefix() const override
    {
        return remote_guid_.guidPrefix;
    }

    /**
     * Get the GUID prefix of all the destination participants.
     *
     * @return a const reference to a vector with the GUID prefix of all destination participants.
     */
    const std::vector<GuidPrefix_t>& remote_participants() const override
    {
        return guid_prefix_as_vector_;
    }

    /**
     * Get the GUID of all destinations.
     *
     * @return a const reference to a vector with the GUID of all destinations.
     */
    const std::vector<GUID_t>& remote_guids() const override
    {
        return guid_as_vector_;
    }

    /**
     * Send a message through this interface.
     *
     * @param buffers Vector of NetworkBuffers to send with data already serialized.
     * @param total_bytes Total number of bytes to send. Should be equal to the sum of the @c size field of all buffers.
     * @param max_blocking_time_point Future timepoint where blocking send should end.
     */
    bool send(
            const std::vector<eprosima::fastdds::rtps::NetworkBuffer>& /*buffers*/,
            const uint32_t& /*total_bytes*/,
            std::chrono::steady_clock::time_point /*max_blocking_time_point*/) const override
    {
        return true;
    }

    bool is_local_reader() const
    {
        return false;
    }

    LocalReaderPointer::Instance local_reader()
    {
        return LocalReaderPointer::Instance(std::shared_ptr<LocalReaderPointer>());
    }

    bool is_datasharing_reader() const
    {
        return false;
    }

    /**
     * @return The datasharing notifier for this reader or nullptr if the reader is not datasharing.
     */
    IDataSharingNotifier* datasharing_notifier()
    {
        return nullptr;
    }

    /**
     * @return The datasharing notifier for this reader or nullptr if the reader is not datasharing.
     */
    const IDataSharingNotifier* datasharing_notifier() const
    {
        return nullptr;
    }

    void datasharing_notify()
    {
    }

    size_t locators_size() const
    {
        return 0;
    }

    void lock() override
    {
    }

    void unlock() override
    {
    }

private:

    GUID_t remote_guid_;
    std::vector<GuidPrefix_t> guid_prefix_as_vector_;
    std::vector<GUID_t> guid_as_vector_;
};

} /* namespace rtps */
} /* namespace fastdds */
} /* namespace eprosima */

#endif // FASTDDS_RTPS_WRITER__READERLOCATOR_HPP

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

/*!
 * @file basic_inner_typesPubSubTypes.cpp
 * This header file contains the implementation of the serialization functions.
 *
 * This file was generated by the tool fastddsgen.
 */

#include "basic_inner_typesPubSubTypes.hpp"

#include <fastdds/dds/log/Log.hpp>
#include <fastdds/rtps/common/CdrSerialization.hpp>

#include "basic_inner_typesCdrAux.hpp"
#include "basic_inner_typesTypeObjectSupport.hpp"

using SerializedPayload_t = eprosima::fastdds::rtps::SerializedPayload_t;
using InstanceHandle_t = eprosima::fastdds::rtps::InstanceHandle_t;
using DataRepresentationId_t = eprosima::fastdds::dds::DataRepresentationId_t;

InnerStructureHelperPubSubType::InnerStructureHelperPubSubType()
{
    set_name("InnerStructureHelper");
    uint32_t type_size = InnerStructureHelper_max_cdr_typesize;
    type_size += static_cast<uint32_t>(eprosima::fastcdr::Cdr::alignment(type_size, 4)); /* possible submessage alignment */
    max_serialized_type_size = type_size + 4; /*encapsulation*/
    is_compute_key_provided = false;
    uint32_t key_length = InnerStructureHelper_max_key_cdr_typesize > 16 ? InnerStructureHelper_max_key_cdr_typesize : 16;
    key_buffer_ = reinterpret_cast<unsigned char*>(malloc(key_length));
    memset(key_buffer_, 0, key_length);
}

InnerStructureHelperPubSubType::~InnerStructureHelperPubSubType()
{
    if (key_buffer_ != nullptr)
    {
        free(key_buffer_);
    }
}

bool InnerStructureHelperPubSubType::serialize(
        const void* const data,
        SerializedPayload_t& payload,
        DataRepresentationId_t data_representation)
{
    const InnerStructureHelper* p_type = static_cast<const InnerStructureHelper*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload.data), payload.max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
            eprosima::fastcdr::CdrVersion::XCDRv1 : eprosima::fastcdr::CdrVersion::XCDRv2);
    payload.encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    ser.set_encoding_flag(
        data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
        eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR  :
        eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2);

    try
    {
        // Serialize encapsulation
        ser.serialize_encapsulation();
        // Serialize the object.
        ser << *p_type;
        ser.set_dds_cdr_options({0,0});
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    // Get the serialized length
    payload.length = static_cast<uint32_t>(ser.get_serialized_data_length());
    return true;
}

bool InnerStructureHelperPubSubType::deserialize(
        SerializedPayload_t& payload,
        void* data)
{
    try
    {
        // Convert DATA to pointer of your type
        InnerStructureHelper* p_type = static_cast<InnerStructureHelper*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload.data), payload.length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN);

        // Deserialize encapsulation.
        deser.read_encapsulation();
        payload.encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

        // Deserialize the object.
        deser >> *p_type;
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    return true;
}

uint32_t InnerStructureHelperPubSubType::calculate_serialized_size(
        const void* const data,
        DataRepresentationId_t data_representation)
{
    try
    {
        eprosima::fastcdr::CdrSizeCalculator calculator(
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
            eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);
        size_t current_alignment {0};
        return static_cast<uint32_t>(calculator.calculate_serialized_size(
                    *static_cast<const InnerStructureHelper*>(data), current_alignment)) +
                4u /*encapsulation*/;
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return 0;
    }
}

void* InnerStructureHelperPubSubType::create_data()
{
    return reinterpret_cast<void*>(new InnerStructureHelper());
}

void InnerStructureHelperPubSubType::delete_data(
        void* data)
{
    delete(reinterpret_cast<InnerStructureHelper*>(data));
}

bool InnerStructureHelperPubSubType::compute_key(
        SerializedPayload_t& payload,
        InstanceHandle_t& handle,
        bool force_md5)
{
    if (!is_compute_key_provided)
    {
        return false;
    }

    InnerStructureHelper data;
    if (deserialize(payload, static_cast<void*>(&data)))
    {
        return compute_key(static_cast<void*>(&data), handle, force_md5);
    }

    return false;
}

bool InnerStructureHelperPubSubType::compute_key(
        const void* const data,
        InstanceHandle_t& handle,
        bool force_md5)
{
    if (!is_compute_key_provided)
    {
        return false;
    }

    const InnerStructureHelper* p_type = static_cast<const InnerStructureHelper*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(key_buffer_),
            InnerStructureHelper_max_key_cdr_typesize);

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS, eprosima::fastcdr::CdrVersion::XCDRv2);
    ser.set_encoding_flag(eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR2);
    eprosima::fastcdr::serialize_key(ser, *p_type);
    if (force_md5 || InnerStructureHelper_max_key_cdr_typesize > 16)
    {
        md5_.init();
        md5_.update(key_buffer_, static_cast<unsigned int>(ser.get_serialized_data_length()));
        md5_.finalize();
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle.value[i] = md5_.digest[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle.value[i] = key_buffer_[i];
        }
    }
    return true;
}

void InnerStructureHelperPubSubType::register_type_object_representation()
{
    register_InnerStructureHelper_type_identifier(type_identifiers_);
}

InnerEmptyStructureHelperPubSubType::InnerEmptyStructureHelperPubSubType()
{
    set_name("InnerEmptyStructureHelper");
    uint32_t type_size = InnerEmptyStructureHelper_max_cdr_typesize;
    type_size += static_cast<uint32_t>(eprosima::fastcdr::Cdr::alignment(type_size, 4)); /* possible submessage alignment */
    max_serialized_type_size = type_size + 4; /*encapsulation*/
    is_compute_key_provided = false;
    uint32_t key_length = InnerEmptyStructureHelper_max_key_cdr_typesize > 16 ? InnerEmptyStructureHelper_max_key_cdr_typesize : 16;
    key_buffer_ = reinterpret_cast<unsigned char*>(malloc(key_length));
    memset(key_buffer_, 0, key_length);
}

InnerEmptyStructureHelperPubSubType::~InnerEmptyStructureHelperPubSubType()
{
    if (key_buffer_ != nullptr)
    {
        free(key_buffer_);
    }
}

bool InnerEmptyStructureHelperPubSubType::serialize(
        const void* const data,
        SerializedPayload_t& payload,
        DataRepresentationId_t data_representation)
{
    const InnerEmptyStructureHelper* p_type = static_cast<const InnerEmptyStructureHelper*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload.data), payload.max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
            eprosima::fastcdr::CdrVersion::XCDRv1 : eprosima::fastcdr::CdrVersion::XCDRv2);
    payload.encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    ser.set_encoding_flag(
        data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
        eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR  :
        eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2);

    try
    {
        // Serialize encapsulation
        ser.serialize_encapsulation();
        // Serialize the object.
        ser << *p_type;
        ser.set_dds_cdr_options({0,0});
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    // Get the serialized length
    payload.length = static_cast<uint32_t>(ser.get_serialized_data_length());
    return true;
}

bool InnerEmptyStructureHelperPubSubType::deserialize(
        SerializedPayload_t& payload,
        void* data)
{
    try
    {
        // Convert DATA to pointer of your type
        InnerEmptyStructureHelper* p_type = static_cast<InnerEmptyStructureHelper*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload.data), payload.length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN);

        // Deserialize encapsulation.
        deser.read_encapsulation();
        payload.encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

        // Deserialize the object.
        deser >> *p_type;
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return false;
    }

    return true;
}

uint32_t InnerEmptyStructureHelperPubSubType::calculate_serialized_size(
        const void* const data,
        DataRepresentationId_t data_representation)
{
    try
    {
        eprosima::fastcdr::CdrSizeCalculator calculator(
            data_representation == DataRepresentationId_t::XCDR_DATA_REPRESENTATION ?
            eprosima::fastcdr::CdrVersion::XCDRv1 :eprosima::fastcdr::CdrVersion::XCDRv2);
        size_t current_alignment {0};
        return static_cast<uint32_t>(calculator.calculate_serialized_size(
                    *static_cast<const InnerEmptyStructureHelper*>(data), current_alignment)) +
                4u /*encapsulation*/;
    }
    catch (eprosima::fastcdr::exception::Exception& /*exception*/)
    {
        return 0;
    }
}

void* InnerEmptyStructureHelperPubSubType::create_data()
{
    return reinterpret_cast<void*>(new InnerEmptyStructureHelper());
}

void InnerEmptyStructureHelperPubSubType::delete_data(
        void* data)
{
    delete(reinterpret_cast<InnerEmptyStructureHelper*>(data));
}

bool InnerEmptyStructureHelperPubSubType::compute_key(
        SerializedPayload_t& payload,
        InstanceHandle_t& handle,
        bool force_md5)
{
    if (!is_compute_key_provided)
    {
        return false;
    }

    InnerEmptyStructureHelper data;
    if (deserialize(payload, static_cast<void*>(&data)))
    {
        return compute_key(static_cast<void*>(&data), handle, force_md5);
    }

    return false;
}

bool InnerEmptyStructureHelperPubSubType::compute_key(
        const void* const data,
        InstanceHandle_t& handle,
        bool force_md5)
{
    if (!is_compute_key_provided)
    {
        return false;
    }

    const InnerEmptyStructureHelper* p_type = static_cast<const InnerEmptyStructureHelper*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(key_buffer_),
            InnerEmptyStructureHelper_max_key_cdr_typesize);

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS, eprosima::fastcdr::CdrVersion::XCDRv2);
    ser.set_encoding_flag(eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR2);
    eprosima::fastcdr::serialize_key(ser, *p_type);
    if (force_md5 || InnerEmptyStructureHelper_max_key_cdr_typesize > 16)
    {
        md5_.init();
        md5_.update(key_buffer_, static_cast<unsigned int>(ser.get_serialized_data_length()));
        md5_.finalize();
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle.value[i] = md5_.digest[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle.value[i] = key_buffer_[i];
        }
    }
    return true;
}

void InnerEmptyStructureHelperPubSubType::register_type_object_representation()
{
    register_InnerEmptyStructureHelper_type_identifier(type_identifiers_);
}


// Include auxiliary functions like for serializing/deserializing.
#include "basic_inner_typesCdrAux.ipp"

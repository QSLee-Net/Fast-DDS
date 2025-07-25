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
 * @file FlowControl.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen (version: 4.1.0).
 */

#ifndef FAST_DDS_GENERATED__FLOWCONTROL_HPP
#define FAST_DDS_GENERATED__FLOWCONTROL_HPP

#include <array>
#include <cstdint>
#include <utility>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define eProsima_user_DllExport
#endif  // _WIN32

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(FLOWCONTROL_SOURCE)
#define FLOWCONTROL_DllAPI __declspec( dllexport )
#else
#define FLOWCONTROL_DllAPI __declspec( dllimport )
#endif // FLOWCONTROL_SOURCE
#else
#define FLOWCONTROL_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define FLOWCONTROL_DllAPI
#endif // _WIN32

/*!
 * @brief This class represents the structure FlowControl defined by the user in the IDL file.
 * @ingroup FlowControl
 */
class FlowControl
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport FlowControl()
    {
    }

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~FlowControl()
    {
    }

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object FlowControl that will be copied.
     */
    eProsima_user_DllExport FlowControl(
            const FlowControl& x)
    {
                    m_index = x.m_index;

                    m_message = x.m_message;

    }

    /*!
     * @brief Move constructor.
     * @param x Reference to the object FlowControl that will be copied.
     */
    eProsima_user_DllExport FlowControl(
            FlowControl&& x) noexcept
    {
        m_index = x.m_index;
        m_message = std::move(x.m_message);
    }

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object FlowControl that will be copied.
     */
    eProsima_user_DllExport FlowControl& operator =(
            const FlowControl& x)
    {

                    m_index = x.m_index;

                    m_message = x.m_message;

        return *this;
    }

    /*!
     * @brief Move assignment.
     * @param x Reference to the object FlowControl that will be copied.
     */
    eProsima_user_DllExport FlowControl& operator =(
            FlowControl&& x) noexcept
    {

        m_index = x.m_index;
        m_message = std::move(x.m_message);
        return *this;
    }

    /*!
     * @brief Comparison operator.
     * @param x FlowControl object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const FlowControl& x) const
    {
        return (m_index == x.m_index &&
           m_message == x.m_message);
    }

    /*!
     * @brief Comparison operator.
     * @param x FlowControl object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const FlowControl& x) const
    {
        return !(*this == x);
    }

    /*!
     * @brief This function sets a value in member index
     * @param _index New value for member index
     */
    eProsima_user_DllExport void index(
            uint32_t _index)
    {
        m_index = _index;
    }

    /*!
     * @brief This function returns the value of member index
     * @return Value of member index
     */
    eProsima_user_DllExport uint32_t index() const
    {
        return m_index;
    }

    /*!
     * @brief This function returns a reference to member index
     * @return Reference to member index
     */
    eProsima_user_DllExport uint32_t& index()
    {
        return m_index;
    }


    /*!
     * @brief This function copies the value in member message
     * @param _message New value to be copied in member message
     */
    eProsima_user_DllExport void message(
            const std::array<char, 600000>& _message)
    {
        m_message = _message;
    }

    /*!
     * @brief This function moves the value in member message
     * @param _message New value to be moved in member message
     */
    eProsima_user_DllExport void message(
            std::array<char, 600000>&& _message)
    {
        m_message = std::move(_message);
    }

    /*!
     * @brief This function returns a constant reference to member message
     * @return Constant reference to member message
     */
    eProsima_user_DllExport const std::array<char, 600000>& message() const
    {
        return m_message;
    }

    /*!
     * @brief This function returns a reference to member message
     * @return Reference to member message
     */
    eProsima_user_DllExport std::array<char, 600000>& message()
    {
        return m_message;
    }



private:

    uint32_t m_index{0};
    std::array<char, 600000> m_message{0};

};

#endif // _FAST_DDS_GENERATED_FLOWCONTROL_HPP_



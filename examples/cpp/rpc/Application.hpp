// Copyright 2025 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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
 * @file Application.hpp
 *
 */

#ifndef FASTDDS_EXAMPLES_CPP_RPC__APPLICATION_HPP
#define FASTDDS_EXAMPLES_CPP_RPC__APPLICATION_HPP

#include <memory>
#include <string>

#include "CLIParser.hpp"

namespace eprosima {
namespace fastdds {
namespace examples {
namespace rpc {

class Application
{
public:

    //! Virtual destructor
    virtual ~Application() = default;

    //! Run application
    virtual void run() = 0;

    //! Trigger the end of execution
    virtual void stop() = 0;

    //! Factory method to create applications based on configuration
    static std::shared_ptr<Application> make_app(
            const CLIParser::config& config,
            const std::string& service_name);
};

} // namespace rpc
} // namespace examples
} // namespace fastdds
} // namespace eprosima

#endif // FASTDDS_EXAMPLES_CPP_RPC__APPLICATION_HPP

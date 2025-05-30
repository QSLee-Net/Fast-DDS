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
 * @file Application.cpp
 *
 */

#include "Application.hpp"

#include "CLIParser.hpp"
#include "ClientApp.hpp"
#include "ServerApp.hpp"

using namespace eprosima::fastdds::dds;

namespace eprosima {
namespace fastdds {
namespace examples {
namespace rpc {

//! Factory method to create a server or client
std::shared_ptr<Application> Application::make_app(
        const CLIParser::config& config,
        const std::string& service_name)
{
    std::shared_ptr<Application> entity;
    switch (config.entity)
    {
        case CLIParser::EntityKind::CLIENT:
        {
            entity = std::make_shared<ClientApp>(config, service_name);
            break;
        }
        case CLIParser::EntityKind::SERVER:
        {
            entity = std::make_shared<ServerApp>(config, service_name);
            break;
        }
        case CLIParser::EntityKind::UNDEFINED:
        default:
            throw std::runtime_error("Entity initialization failed");
            break;
    }
    return entity;
}

} // namespace rpc
} // namespace examples
} // namespace fastdds
} // namespace eprosima

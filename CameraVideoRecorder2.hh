/*
 * Copyright (C) 2020 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef GZ_SIM_CAMERAVIDEORECORDER_SYSTEM_HH_
#define GZ_SIM_CAMERAVIDEORECORDER_SYSTEM_HH_

#include <memory>
#include <gz/sim/config.hh>
#include <gz/sim/System.hh>

using namespace gz;
using namespace sim;
using namespace systems;
namespace streamer
{
  class CameraVideoRecorderPrivate;

  class CameraVideoRecorder2 final:
    public gz::sim::System,
    public gz::sim::ISystemConfigure,
    public gz::sim::ISystemPostUpdate
  {
    /// \brief Constructor
    public: CameraVideoRecorder2();

    /// \brief Destructor
    public: ~CameraVideoRecorder2() final = default;

    /// Documentation inherited
    public: void Configure(const Entity &_entity,
                           const std::shared_ptr<const sdf::Element> &_sdf,
                           EntityComponentManager &_ecm,
                           EventManager &_eventMgr) final;

    /// Documentation inherited
    public: void PostUpdate(const UpdateInfo &_info,
                const EntityComponentManager &_ecm) final;

    /// \brief Private data pointer
    private: std::unique_ptr<CameraVideoRecorderPrivate> dataPtr;
  };
}

#endif

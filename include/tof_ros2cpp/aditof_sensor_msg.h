/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2019, Analog Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef ADITOF_SENSOR_MSG_H
#define ADITOF_SENSOR_MSG_H

#include <aditof/camera.h>
#include <rcl/publisher.h>
#include <rcl/time.h>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/image_encodings.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

class AditofSensorMsg
{
public:
  virtual ~AditofSensorMsg() = default;
  virtual void FrameDataToMsg(
    const std::shared_ptr<aditof::Camera> & camera, aditof::Frame ** frame,
    rclcpp::Time tStamp) = 0;
  virtual sensor_msgs::msg::Image getMessage() = 0;
  virtual void publishMsg(rclcpp::Publisher<sensor_msgs::msg::Image> & pub) = 0;
};

class AditofSensorPointCloudMsg
{
public:
  virtual ~AditofSensorPointCloudMsg() = default;
  virtual void FrameDataToMsg(
    const std::shared_ptr<aditof::Camera> & camera, aditof::Frame ** frame) = 0;

  virtual sensor_msgs::msg::PointCloud2 getMessagePointCloud() = 0;
  virtual void publishMsg(rclcpp::Publisher<sensor_msgs::msg::PointCloud2> & pub) = 0;
};

#endif  // ADITOF_SENSOR_MSG_H

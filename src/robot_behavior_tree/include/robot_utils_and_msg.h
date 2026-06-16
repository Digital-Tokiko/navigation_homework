//
// Created by mizu on 2026/6/8.
//

#ifndef NAVIGATION_HOMEWORK_ROBOT_MSG_H
#define NAVIGATION_HOMEWORK_ROBOT_MSG_H

#include <vector>

#include "geometry_msgs/msg/pose2_d.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "robot_msgs/msg/map_info.hpp"
#include "robot_msgs/msg/map_info_msgs.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "example_interfaces/msg/bool.hpp"

enum TargetType : uint8_t {
    STAR = 0,
    BASE = 1,
    ENEMY_BASE = 2,
    PURPLEENTRY = 3,
    GREENENTRY = 4,
    SENTRY = 5,
    ENEMY = 6,
    PURPLEEXIT = 7,
    GREENEXIT = 8,
};

struct map_info_struct {
    bool is_exist;
    bool is_out_of_center;
    geometry_msgs::msg::Pose2D pose;
};

#endif //NAVIGATION_HOMEWORK_ROBOT_MSG_H
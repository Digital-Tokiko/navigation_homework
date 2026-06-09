//
// Created by mizu on 2026/6/8.
//

#ifndef NAVIGATION_HOMEWORK_UPDATEMAPINFO_H
#define NAVIGATION_HOMEWORK_UPDATEMAPINFO_H

#include <rclcpp/rclcpp.hpp>

#include "nav2_behavior_tree/bt_action_node.hpp"

#include "robot_msg.h"

class UpdateMapinfo : public BT::ActionNodeBase {

    rclcpp::Node::SharedPtr node_ptr_;

    rclcpp::Subscription<robot_msgs::msg::MapInfoMsgs>::SharedPtr map_info_subscriber_;

public:
    NavVelRemap(
        const std::string & xml_tag_name,
        const BT::NodeConfiguration & conf)
    : BT::ActionNodeBase(xml_tag_name, conf) {

        node_ptr_ = conf.blackboard->get<rclcpp::Node::SharedPtr>("node");

        nav2_cmd_vel_subscriber_ = node_ptr_->create_subscription<geometry_msgs::msg::Twist>("map_info", 10, std::bind(&UpdateMapinfo::MapinfoCallback, this, std::placeholders::_1));

        is_updated_ = false;

        current_angle_ = 0;

    }

    void MapinfoCallback(const robot_msgs::msg::MapInfoMsgs msg);

    BT::NodeStatus tick() override
    {
        return BT::NodeStatus::SUCCESS;
    }

    void halt() override {return;}
};


#endif //NAVIGATION_HOMEWORK_UPDATEMAPINFO_H
//
// Created by mizu on 2026/6/8.
//

#ifndef NAVIGATION_HOMEWORK_NAVVELREMAP_H
#define NAVIGATION_HOMEWORK_NAVVELREMAP_H

#include <rclcpp/rclcpp.hpp>

#include "nav2_behavior_tree/bt_action_node.hpp"

#include "robot_msg.h"

class NavVelRemap : public BT::ActionNodeBase {
    double current_angle_;
    bool is_updated_;

    rclcpp::Node::SharedPtr node_ptr_;

    geometry_msgs::msg::Pose2D pose_;

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr nav2_cmd_vel_subscriber_;
    rclcpp::Publisher<geometry_msgs::msg::Pose2D>::SharedPtr pose_publisher_;


public:
    NavVelRemap(
        const std::string & xml_tag_name,
        const BT::NodeConfiguration & conf)
    : BT::ActionNodeBase(xml_tag_name, conf) {

        node_ptr_ = conf.blackboard->get<rclcpp::Node::SharedPtr>("node");

        nav2_cmd_vel_subscriber_ = node_ptr_->create_subscription<geometry_msgs::msg::Twist>("cmd_vel", 10, std::bind(&NavVelRemap::VelCallback, this, std::placeholders::_1));

        pose_publisher_ = node_ptr_->create_publisher<geometry_msgs::msg::Pose2D>("pose", 10);

        is_updated_ = false;

        current_angle_ = 0;

    }

    void VelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);

    BT::NodeStatus tick() override
    {
        rclcpp::spin_some(node_ptr_);
        pose_publisher_->publish(pose_);

        pose_.x = 0;
        pose_.y = 0;

        return BT::NodeStatus::SUCCESS;
    }

    void halt() override {return;}

};


#endif //NAVIGATION_HOMEWORK_NAVVELREMAP_H
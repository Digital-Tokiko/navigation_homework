//
// Created by mizu on 2026/6/9.
//

#ifndef NAVIGATION_HOMEWORK_IFGAMESTART_H
#define NAVIGATION_HOMEWORK_IFGAMESTART_H

#include <string>

#include "rclcpp/rclcpp.hpp"
#include "behaviortree_cpp_v3/condition_node.h"

    class IfGameStart : public BT::ConditionNode
    {
    public:
        /**
         * @brief A constructor for nav2_behavior_tree::IsBatteryLowCondition
         * @param condition_name Name for the XML tag for this node
         * @param conf BT node configuration
         */
        IfInChaseCondition(
            const std::string &condition_name,
            const BT::NodeConfiguration &conf);

        IfInChaseCondition() = delete;

        /**
         * @brief The main override required by a BT action
         * @return BT::NodeStatus Status of tick execution
         */
        BT::NodeStatus tick() override;

        /**
         * @brief Creates list of BT ports
         * @return BT::PortsList Containing node-specific ports
         */
        static BT::PortsList providedPorts()
        {
            return {};
        }

};


#endif //NAVIGATION_HOMEWORK_IFGAMESTART_H
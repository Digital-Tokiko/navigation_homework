//
// Created by mizu on 2026/6/8.
//

#include "UpdateMapinfo.h"

#include <vector>

static BT::PortsList providedPorts() {
    return {
        BT::OutputPort<std::vector<robot_msgs::msg::MapInfo>>("map_infos", "map_infos"),
        BT::OutputPort<int>("enemy_num","enemy_num"),
        BT::OutputPort<double>("sentry_hp","sentry_hp"),
        BT::OutputPort<bool>("is_transfering","is_transfering"),
        BT::OutputPort<bool>("is_bullet_low", "is_bullet_low"),
        BT::OutputPort<bool>("is_game_started", "is_game_started"),
    }
}

void MapinfoCallback(const robot_msgs::msg::MapInfoMsgs msg) {
    setOutput("map_infos", msg.map_info);
    setOutput("enemy_num", msg.enemy_num);
    setOutput("is_transfering", msg.is_transfering);
    setOutput("is_bullet_low", msg.is_bullet_low);
    setOutput("sentry_hp", msg.sentry_hp);
}

#include "behaviortree_cpp_v3/bt_factory.h"
BT_REGISTER_NODES(factory)
{
    BT::NodeBuilder builder =
      [](const std::string & name, const BT::NodeConfiguration & config)
      {
          return std::make_unique<NavVelRemap>(name, config);
      };

    factory.registerBuilder<NavVelRemap>("NavVelRemap", builder);
}
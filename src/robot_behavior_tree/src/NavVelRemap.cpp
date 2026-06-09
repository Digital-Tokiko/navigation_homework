//
// Created by mizu on 2026/6/8.
//

#include "NavVelRemap.h"

#include <cmath>

void NavVelRemap::VelCallback(const geometry_msgs::msg::Twist::SharedPtr msg){
	double V_0 = msg->linear.x;
	double w = msg->angular.z;

	current_angle_ += w;

	pose_.x = V_0 * cos(current_angle_);
	pose_.y = - V_0 * sin(current_angle_);
	pose_.theta = current_angle_ ;

	is_updated_ = true;
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

/*BT_REGISTER_NODES(factory)
{
	factory.registerNodeType<NavVelRemap>("NavVelRemap");
}*/
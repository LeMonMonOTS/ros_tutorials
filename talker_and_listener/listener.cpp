#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


void callback(const std_msgs::String::ConstPtr& msg){
  std::cout << "I heared " << *msg;
}


int main(int argc, char **argv){
  ros::init(argc, argv, "listener");
  
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000, callback);

  ros::spin();

  return 0;
}

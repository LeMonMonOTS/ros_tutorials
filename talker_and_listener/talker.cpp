#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


int main(int argc, char **argv){
  ros::init(argc, argv, "talker");
   
  ros::NodeHandle n;

  ros::Publisher pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate Loop_rate(10);

  int count = 0;
  while (ros::ok()){
    std_msgs::String msg;

    std::stringstream ss;
    ss << "Hello world!" << count;
    msg.data = ss.str();

    std::cout << ss.str() << std::endl;

    pub.publish(msg);

    ros::spinOnce();

    Loop_rate.sleep();

    ++count;
  }
  return 0;
}

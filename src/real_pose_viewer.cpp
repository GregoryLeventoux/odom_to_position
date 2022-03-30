#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include  "geometry_msgs/msg/point.hpp"

class RealPoseViewer : public rclcpp::Node
{
  public:
    RealPoseViewer()
    : Node("real_pose_viewer")
    {

        subscriber = this->create_subscription<nav_msgs::msg::Odometry>(
                    "/r2d2/odom", 10,  std::bind(&RealPoseViewer::callback, this, std::placeholders::_1));

        publisher = this->create_publisher<geometry_msgs::msg::Point> ("/r2d2/real_position",10);


    }


  private:

    void callback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        publisher->publish(msg->pose.pose.position);
    }

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscriber;
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr publisher;

};



int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RealPoseViewer>());
  rclcpp::shutdown();
  return 0;
}

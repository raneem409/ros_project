#include <ros/ros.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "base_to_odom");
    ros::NodeHandle nh;

    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener(tfBuffer);

    ros::Rate rate(10.0);
    while (ros::ok()) {
        geometry_msgs::TransformStamped transformStamped;
        try {
            transformStamped = tfBuffer.lookupTransform("base_link", "odom", ros::Time(0));
            ROS_INFO("Received transform from base_link to odom: x=%f, y=%f, z=%f", 
                transformStamped.transform.translation.x,
                transformStamped.transform.translation.y,
                transformStamped.transform.translation.z);
        } catch (tf2::TransformException& ex) {
            ROS_WARN("Could not get transform from base_link to odom: %s", ex.what());
        }

        rate.sleep();
    }

    return 0;
}


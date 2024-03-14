#!/usr/bin/env python

import rospy
from nav_msgs.msg import Odometry

def odom_callback(odom_msg):
    # Process odometry data here
    pass

if __name__ == "__main__":
    rospy.init_node("odom_subscriber")

    # Subscribe to the odom topic
    rospy.Subscriber("odom", Odometry, odom_callback)

    rospy.spin()


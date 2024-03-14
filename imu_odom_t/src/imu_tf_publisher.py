#!/usr/bin/env python

import rospy
import tf2_ros
from geometry_msgs.msg import TransformStamped

def publish_static_transform():
    # Define the translation between base_link and imu_Link
    translation = (0.0, 0.0, 0.1)  # Adjust according to actual position of the imu_Link sensor

    # Define the rotation (no rotation in this case)
    rotation = (0.0, 0.0, 0.0, 1.0)

    # Create a TransformStamped message
    transform_stamped = TransformStamped()
    transform_stamped.header.stamp = rospy.Time.now()
    transform_stamped.header.frame_id = "base_link"
    transform_stamped.child_frame_id = "imu_Link"
    transform_stamped.transform.translation.x = translation[0]
    transform_stamped.transform.translation.y = translation[1]
    transform_stamped.transform.translation.z = translation[2]
    transform_stamped.transform.rotation.x = rotation[0]
    transform_stamped.transform.rotation.y = rotation[1]
    transform_stamped.transform.rotation.z = rotation[2]
    transform_stamped.transform.rotation.w = rotation[3]

    # Publish the transformation
    broadcaster.sendTransform(transform_stamped)

if __name__ == "__main__":
    rospy.init_node("imu_tf_publisher")

    # Initialize TransformBroadcaster
    broadcaster = tf2_ros.TransformBroadcaster()

    rate = rospy.Rate(10)  # Adjust the publishing rate as needed

    while not rospy.is_shutdown():
        publish_static_transform()
        rate.sleep()


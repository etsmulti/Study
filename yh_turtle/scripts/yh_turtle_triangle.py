#!/home/min/anaconda3/bin/python
# -*- coding: utf8 *-*

import rospy
from geometry_msgs.msg import Twist
import math
# from turtlesim import Pose

def talker():
    rospy.init_node("yh_tutle_triangle")
    pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=100)

    # pub = rospy.Publisher("/turtle1/pose", Pose, queue_size=100)
    msg = Twist()

    l = input("한변의 길이는 : ")
    a = input("움직이는 각도는  : ")

    ll = float(l)
    aa = float(a)

    loop_rate = rospy.Rate(1)

    while not rospy.is_shutdown(): 
        msg.linear.x = ll
        msg.angular.z = 0
        pub.publish(msg)
        loop_rate.sleep()

        msg.linear.x = 0
        msg.angular.z = (math.pi/180.0) * aa
        pub.publish(msg)
        loop_rate.sleep()

if __name__ == "__main__":
    try:
        talker()
    except rospy.ROSInterruptException:
        pass


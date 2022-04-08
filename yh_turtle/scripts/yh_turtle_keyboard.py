#!/home/min/anaconda3/bin/python
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist

pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=1)

def keyboardCallBack(msg):
    pub.publish(msg)

def listner():
    rospy.init_node("yh_turtle_keyboard", anonymous=True)
    rospy.Subscriber("/cmd_vel", Twist, keyboardCallBack)

    rospy.spin()

if __name__ == "__main__":
    listner()
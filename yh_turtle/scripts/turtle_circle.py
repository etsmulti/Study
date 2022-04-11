#!/usr/bin/python
# -*- coding: utf8 *-*

import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import TeleportAbsolute
from std_srvs.srv import Empty
import sys

class TurtleCircle():
    def __init__(self, radius):
        self.pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=10)
        self.client_teleport = rospy.ServiceProxy("/turtle1/teleport_absolute", TeleportAbsolute)
        self.client_clear = rospy.ServiceProxy("/clear", Empty)
        self.radius = radius

    def run(self):
        self.client_teleport(5.54445, 5.54445 - self.radius, 0)
        self.client_clear()
        msg = Twist()
        
        msg.linear.x = self.radius
        msg.angular.z = 1.0

        loop_rate = rospy.Rate(1)

        while not rospy.is_shutdown():
            self.pub.publish(msg)
            loop_rate.sleep()


if __name__ == "__main__":
    rospy.init_node("turtle_circle")
    ar = sys.argv[1]
    radius = float(ar)

    turtle_circle = TurtleCircle(radius)
    turtle_circle.run()

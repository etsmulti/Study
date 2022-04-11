#!/home/min/anaconda3/bin/python
# -*- coding: utf8 -*-

import rospy
import math
import sys
from geometry_msgs.msg import Twist 
from turtlesim.srv import TeleportAbsolute
from std_srvs.srv import Empty

class TurtleTriangle():
    def __init__(self, length):
        self.pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=10)
        self.client_teleport = rospy.ServiceProxy("/turtle1/teleport_absolute", TeleportAbsolute)
        self.client_clear = rospy.ServiceProxy("/clear", Empty)
        self.length = length

    def run(self):
        self.client_teleport(5.544445 -self.length/2, 5.544445-( math.sqrt(3) / 4  * self.length), 0)
        self.client_clear() 
        

        msg = Twist()


        # while self.pub.get_num_connections() < 1:
        #     continue
        loop_rate = rospy.Rate(1)

        loop_rate.sleep()
        cnt = 0

        while not rospy.is_shutdown():
            if (cnt == 3):
                self.client_clear()
                cnt  = 0
            msg.linear.x = self.length
            msg.angular.z = 0
            self.pub.publish(msg)
            loop_rate.sleep()

            msg.linear.x = 0
            msg.angular.z = math.pi * 2 / 3
            self.pub.publish(msg)
            loop_rate.sleep()
            cnt += 1

if __name__ == "__main__":
    rospy.init_node("turtle_triangle")
    if len(sys.argv) != 2:
        print("arg error")
        sys.exit(1)
    lt = sys.argv[1]
    length = float(lt)

    turtle_triangle = TurtleTriangle(length)
    turtle_triangle.run()








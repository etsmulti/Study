#!/home/min/anaconda3/bin/python
# -*- coding: utf8 -*-

import rospy
import math
import sys
from geometry_msgs.msg import Twist 
from turtlesim.srv import TeleportAbsolute
from std_srvs.srv import Empty
from turtle_triangle import TurtleTriangle


class TurtleSquare(TurtleTriangle):

    # def __init__(self, length):
    #     self.pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=10)
    #     self.client_teleport = rospy.ServiceProxy("/turtle1/teleport_absolute", TeleportAbsolute)
    #     self.client_clear = rospy.ServiceProxy("/clear", Empty)
    #     self.length = length

    def run(self):

        self.client_teleport(5.544445 - self.length/2, 5.544445 - self.length/2, 0)
        self.client_clear()

        loop_rate = rospy.Rate(1)
        msg = Twist()

        loop_rate.sleep()
        # while self.pub.get_num_connections() < 1 :
        #     continue
        # print(sys.version)
        cnt = 0

        
        while not rospy.is_shutdown():

            if (cnt == 4):
                self.client_clear()
                cnt = 0

            msg.linear.x = self.length
            msg.angular.z = 0
            self.pub.publish(msg)
            loop_rate.sleep()
            loop_rate.sleep()

            msg.linear.x = 0
            msg.angular.z = math.pi / 2
            self.pub.publish(msg)
            loop_rate.sleep()

            cnt += 1


if __name__ == "__main__":
    rospy.init_node("turtle_square")
    try :
        # lt = input("변의 길이를 입력해 주세요 : ")
        # length = float(lt)
        length = float(input("변의 길이를 입력하세요 : "))
        turtle_square = TurtleSquare(length)
        turtle_square.run()
    except:
        pass


            



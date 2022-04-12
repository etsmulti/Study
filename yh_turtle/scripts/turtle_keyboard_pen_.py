#!/home/min/anaconda3/bin/python
# -*- coding: utf8 *-*

from sqlalchemy import false, true
import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import SetPen, SetPenRequest
# from turtle_pen import TurtlePen

# width = 10
# penfirst = true

class MyTurtle:
    def __init__(self) :
        self.sub = rospy.Subscriber("cmd_vel", Twist, self.msgCallback)
        self.pub = rospy.Publisher("turtle1/cmd_vel", Twist, queue_size=1)
        # service name = turtle1/set_pen
        # service type = turtlesim/SetPen
        self.client_pen = rospy.ServiceProxy("turtle1/set_pen", SetPen)
        self.pen = SetPenRequest()
        self.pen.width = 3

    def msgCallback(self, msg):
        # global width
        # global penfirst
        self.pub.publish(msg)
       
        if (msg.linear.z  > 0):
            # if(penfirst): 
            #     width = my_pen.width +1                
            #     penfirst = false
            # else:
            #     width += 1

            # my_pen.client_pen(my_pen.r,my_pen.g,my_pen.b, width, 0)
            # print("t")
 
            self.pen.r = int(input("r: "))
            self.pen.g = int(input("g: "))
            self.pen.b = int(input("b: "))
            self.client_pen(self.pen)

        elif msg.linear.z < 0:
            # if(penfirst): 
            #     width = my_pen.width -1                
            #     penfirst = false
            # else:
            #     width -= 1
            # my_pen.client_pen(my_pen.r,my_pen.g,my_pen.b, width, 0)
            # print("b")

            self.pen.width = int(input("width :"))
            self.client_pen(self.pen)
            
        else:
            self.pub.publish(msg)


if __name__ == "__main__":
    rospy.init_node("turtle_keyboard_pen")
    my_turtle = MyTurtle()
    # my_pen = TurtlePen()
    rospy.spin()


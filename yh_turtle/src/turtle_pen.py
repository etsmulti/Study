#!/home/min/anaconda3/bin/python
# -*- coding: utf8 -*-

from sqlalchemy import true
import rospy
from turtlesim.srv import SetPen 


class TurtlePen:
    def __init__(self):
        self.client_pen = rospy.ServiceProxy("turtle1/set_pen", SetPen)  
        ### 서비스이름 "turtle1/set_pen" 서비스 타입 일치 SetPen


    def run(self):
        while(true):
            try:
                r = int(input("r 값: "))
                g = int(input("g 값: "))
                b = int(input("b 값: "))
                width = int(input("width 값: "))
                off = int(input("off 값: "))
                self.client_pen(r, g, b, width, off)
            except:
                pass

if __name__ == "__main__":
    rospy.init_node("turtle_pen")
    turtle_pen = TurtlePen()
    turtle_pen.run()











        
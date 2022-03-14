# 2022년 3월 7일 길찾기 프로그램 개발
# made by min sung kim
# This program licence  : GPL license 

import sys
from PyQt6.QtWidgets import *
from PyQt6.QtCore import *
from PyQt6.QtGui import *

class Node:
    def __init__(self, parent=None, position=None):
        self.parent = parent
        self.position = position
        self.g = 0
        self.h = 0
        self.f = 0
    def __eq__(self, other):
        return self.position == other.position

def heuristic(node, goal, D=1, D2=2 ** 0.5): # Diagonal Distance
    dx = abs(node.position[0] - goal.position[0])
    dy = abs(node.position[1] - goal.position[1])
    return D * (dx + dy) + (D2 - 2 * D) * min(dx, dy)

class MyWindow(QWidget):

    celldata = []
    start = (0, 0)
    end = (29, 39)
    dirlist = [(0, -1), (0, 1), (-1, 0), (1, 0),(-1, -1), (-1, 1), (1, -1), (1, 1)]

    def __init__(self):
        super().__init__()
        self.setupUI()

    def setupUI(self):
        # self.a = 10 클래스의 변수를 접근할려면 self. 으로 접근해서 처리한다. 
        self.setGeometry(50, 50, 1600, 970)
        groupBox = QGroupBox("검색옵션")
        checkBox1 = QCheckBox("8방향/4방향")
        checkBox1.stateChanged.connect(self.cb1_check)
        checkBox2 = QCheckBox("Digonal")
        checkBox1.stateChanged.connect(self.cb2_check)
        checkBox3 = QCheckBox("Manhattan")
        checkBox1.stateChanged.connect(self.cb3_check)
        btn1 = QPushButton("선택초기화", self)
        btn1.clicked.connect(self.btn1_clicked)
        btn2 = QPushButton("선택저장", self)
        btn2.clicked.connect(self.btn2_clicked)
        btn3 = QPushButton("선택 x", self)
        btn3.clicked.connect(self.btn3_clicked)
        btnstart = QPushButton("출발점", self)
        btnstart.clicked.connect(self.btnstart_clicked)
        btnend = QPushButton("도착점", self)
        btnend.clicked.connect(self.btnend_clicked)
        btn5 = QPushButton("불러오기", self)
        btn5.clicked.connect(self.btn5_clicked)        
        btn6 = QPushButton("길찾기", self)
        btn6.clicked.connect(self.btn6_clicked)
        btn7 = QPushButton("파일열기", self)
        btn7.clicked.connect(self.add_open)
        btn8 = QPushButton("파일저장", self)
        btn8.clicked.connect(self.add_save)
        btn9 = QPushButton("파일찾기", self)
        btn9.clicked.connect(self.find_folder)
        self.tableWidget = QTableWidget(30, 40)
        # tableWidget.setHorizontalHeaderLabels(["종목코드", "종목명", "현재가", "등락률", "거래량"])
        self.tableWidget.resizeColumnsToContents()
        self.tableWidget.resizeRowsToContents()
        # tableWidget.selectedItems()
        leftInnerLayOut = QVBoxLayout()
        leftInnerLayOut.addWidget(checkBox1)
        leftInnerLayOut.addWidget(checkBox2)
        leftInnerLayOut.addWidget(checkBox3)
        leftInnerLayOut.addWidget(btn1)
        leftInnerLayOut.addWidget(btn2)
        leftInnerLayOut.addWidget(btn3)
        leftInnerLayOut.addWidget(btnstart)
        leftInnerLayOut.addWidget(btnend)
        leftInnerLayOut.addWidget(btn5)
        leftInnerLayOut.addWidget(btn6)
        leftInnerLayOut.addWidget(btn7)
        leftInnerLayOut.addWidget(btn8)
        leftInnerLayOut.addWidget(btn9)
        groupBox.setLayout(leftInnerLayOut)
        leftLayOut = QVBoxLayout()
        leftLayOut.addWidget(groupBox)
        rightLayOut = QVBoxLayout()
        rightLayOut.addWidget(self.tableWidget)
        layout = QHBoxLayout()
        layout.addLayout(leftLayOut)
        layout.addLayout(rightLayOut)
        self.setLayout(layout)

    def heuristic(self, node, goal, D=1, D2=2 ** 0.5): # Diagonal Distance
        dx = abs(node.position[0] - goal.position[0])
        dy = abs(node.position[1] - goal.position[1])
        return D * (dx + dy) + (D2 - 2 * D) * min(dx, dy)

    def aStar(self, celldata, start, end):
        
        
        maze = celldata
        # startNode와 endNode 초기화
        startNode = Node(None, start)
        endNode = Node(None, end)
        # openList, closedList 초기화
        openList = []
        closedList = []
        # openList에 시작 노드 추가
        openList.append(startNode)
        # endNode를 찾을 때까지 실행
        while openList:
            # 현재 노드 지정
            currentNode = openList[0]
            currentIdx = 0
            # enumerate() 는 index를 얻어 오는대 좋다.
            # 이미 같은 노드가 openList에 있고, f 값이 더 크면
            # currentNode를 openList안에 있는 값으로 교체
            for index, item in enumerate(openList):
                if item.f < currentNode.f:
                    currentNode = item
                    currentIdx = index
            # openList에서 제거하고 closedList에 추가
            openList.pop(currentIdx)
            closedList.append(currentNode)
            # 현재 노드가 목적지면 current.position 추가하고
            # current의 부모로 이동
            if currentNode == endNode:
                path = []
                current = currentNode
                while current is not None:
                    # maze 길을 표시하려면 주석 해제
                    x, y = current.position
                    # maze[x* 40 + y] = 7
                    self.tableWidget.item(x, y).setBackground(QColor(255,0,0))

                    path.append(current.position)
                    current = current.parent
                # print(maze)
                return path[::-1] # reverse
            children = []

            for newPosition in self.dirlist :
                # 노드 위치 업데이크
                nodePosition = (
                    currentNode.position[0] + newPosition[0], # X
                    currentNode.position[1] +newPosition[1]) # Y
                # 미로 maze index 범위 안에 있어야함
                within_range_criteria = [
                    nodePosition[0] > 29, # row 의 갯수 - 1
                    nodePosition[0] < 0,
                    nodePosition[1] > 39, # column 의 갯수 -1
                    nodePosition[1] < 0,
                    ]
                if any(within_range_criteria): # 하나라도 true면 범위 밖임
                    continue
                # 장애물이 있으면 다른 위치 불러오기
                if maze[nodePosition[0]*40 + nodePosition[1]] == 'X':
                    continue
                new_node = Node(currentNode, nodePosition)
                
                children.append(new_node)
            # 자식들 모두 lop
            for child in children:
            # 자식이 closeList에 있으면 continue
                if child in closedList:
                    continue
            # f, g, h값 업데이트
                child.g = currentNode.g + 1
                child.h = ((child.position[0] - endNode.position[0]) **
                    2) + ((child.position[1] - endNode.position[1]) ** 2)

                child.f = child.g + child.h
                # 자식이 openList에 있고, g값이 더 크면 continue
                if len([openNode for openNode in openList
                    if child == openNode and child.g > openNode.g]) > 0:
                        continue
                openList.append(child)

    def setTableWidgetData(self):
        indexes = self.tableWidget.selectedIndexes()
        for index in indexes:
            i = index.row()
            j = index.column()
            # print(f'{index.row()}, {index.column()} , {index.data()} ')
            # self.tableWidget.setItem(i, j, QTableWidgetItem(str(i+j)))
            self.tableWidget.setItem(i, j, QTableWidgetItem(""))
            self.tableWidget.item(i, j).setBackground(QColor(255,255,255))
            # self.tableWidget.setItem(i, j, QTableWidgetItem.setBackground(color))

    def cb1_check(self, state):
        if state == Qt.Checked:
            self.setWindowTitle('8방향 추적')
            self.dirlist = [(0, -1), (0, 1), (-1, 0), (1, 0),(-1, -1), (-1, 1), (1, -1), (1, 1)]
        else:
            self.setWindowTitle('4방향 추적')
            self.dirlist = [(0, -1), (0, 1), (-1, 0), (1, 0)]


    def cb2_check(self):
        pass

    def cb3_check(self):
        pass

    

    def btn1_clicked(self):
        self.setTableWidgetData()

    def btn2_clicked(self):
        self.celldata = []
        self.tableWidget.selectAll()
        indexes = self.tableWidget.selectedIndexes()
        for index in indexes:
            if(index.data() == None):
                self.celldata.append('o')
            else:
                self.celldata.append(index.data())
                # print(index.data(), end='')
        self.tableWidget.clearSelection()    
        

    def btn3_clicked(self):
        indexes = self.tableWidget.selectedIndexes()
        for index in indexes:
            i = index.row()
            j = index.column()
            # print(f'{index.row()}, {index.column()} , {index.data()} ')
            # self.tableWidget.setItem(i, j, QTableWidgetItem(str(i+j)))
            self.tableWidget.setItem(i, j, QTableWidgetItem('X'))
            self.tableWidget.item(i, j).setBackground(QColor(0,255,255))
            # self.tableWidget.setItem(i, j, QTableWidgetItem.setBackground(color))
            
    def btnstart_clicked(self):
        indexes = self.tableWidget.selectedIndexes()
        row = indexes[0].row()
        col = indexes[0].column()
        self.tableWidget.setItem(row, col, QTableWidgetItem('S'))
        self.tableWidget.item(row, col).setBackground(QColor(0,0,255))
        self.start = (row, col)
        print(f'startpoint {row}, {col}')
        

    def btnend_clicked(self):
        indexes = self.tableWidget.selectedIndexes()
        row = indexes[0].row()
        col = indexes[0].column()
        self.tableWidget.setItem(row, col, QTableWidgetItem('F'))
        self.tableWidget.item(row, col).setBackground(QColor(255,0,0))
        self.end = (row, col)
        print(f'endpoint {row}, {col}')

    def btn5_clicked(self):
        i = 0
        j = 0
        for cell in self.celldata:

            self.tableWidget.setItem(j, i, QTableWidgetItem(cell))
            # print(f'{j},{i},{cell}' , end='') 
            if( cell == 'o'):
                self.tableWidget.item(j, i).setBackground(QColor(255,255,255))
            if( cell == 'X'):
                self.tableWidget.item(j, i).setBackground(QColor(0,255,255))

            if( i <  39):
                i = i + 1
            else:
                i = 0
                j = j + 1 
                

    def btn6_clicked(self):        

        print(self.start)
        print(self.end)
        path = self.aStar(self.celldata, self.start, self.end)
        # print(path)

    def add_open(self):
        FileOpen = QFileDialog.getOpenFileName(self, 'Open file', './')

        if FileOpen[0]:
            with open(FileOpen[0], encoding='UTF-8') as f:
                data = f.read()
                self.celldata = data.split()
                # print(self.celldata)

                self.btn5_clicked()




    def add_save(self):

        FileSave = QFileDialog.getSaveFileName(self, 'Save file', './')
        i = 0
        # j = 0

        with open(FileSave[0], 'w', encoding='UTF-8') as f:
            for cell in self.celldata:
                if(i < 39):
                    f.write(f'{cell} ')
                    i = i + 1
                else :
                    f.write(cell+'\n')
                    i = 0

    def find_folder(self): 
        FileFolder = QFileDialog.getExistingDirectory(self,'Find Folder')
        # self.label3.setText(FileFolder)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    mywindow = MyWindow()
    mywindow.show()
    sys.exit(app.exec()) 
#This code implements constructors in Python 3.0

#1
class Point:
    def __init__(self,x,y):    #constructor
        self.x=x
        self.y=y

    def move(self):
        print('move')

    def draw(self):
        print('draw')
    
point=Point(10,20)
#point.x=11
print(point.x)


#2
class Person:
    def __init__(self,name):
        self.name=name

    def talk(self):
        print(f"Hi, I am {self.name}")

john=Person("John Smith")
john.talk()

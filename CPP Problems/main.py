import sys
import os
def read ():
    with open("template.txt", "r") as template:
        return template.readlines()
if sys.argv[1] == 'cf':
    path = os.path.abspath(os.path.dirname(__file__))
    os.mkdir(path + '\\' + sys.argv[2])
    text = read()
    text = ''.join(text)
    for i in range(int(sys.argv[3])):
        newpath = './' + str(sys.argv[2]) + '/' + str(chr(ord('A') + i)) + '.cpp'
        file = open(newpath, 'w')
        file.write(text)
        file.close()
elif sys.argv[1] == 'a2':
    path = os.path.abspath(os.path.dirname(__file__))
    os.mkdir(path + '\\' + sys.argv[2])
    text = read()
    text = ''.join(text)
    for i in range(int(sys.argv[3])):
        newpath = './' + str(sys.argv[2]) + '/' + 'problem' + str(i) + '.cpp'
        file = open(newpath, 'w')
        file.write(text)
        file.close()
else :
    print('cant create items')
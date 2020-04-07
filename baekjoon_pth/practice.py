import sys

'''
print("\\    /\\\n )  ( \')\n(  /  )\n \\(__)|")

print("|\\_/|\n|q p|   /}\n( 0 )\"\"\"\\\n|\"^\"`    |\n||_/=\\\\__|")



input1, input2 = input().split()

input1 = int(input1)
input2 = int(input2)

print(input1+input2)
print(input1-input2)
print(input1*input2)
print(input1//input2)
print(input1%input2)



input1, input2, input3 = input().split()

input1 = int(input1)
input2 = int(input2)
input3 = int(input3)

print((input1+input2)%input3)
print((input1%input3+input2%input3)%input3)
print((input1*input2)%input3)
print((input1%input3*input2%input3)%input3)



in1 = input()
in2 = input()

in1 = int(in1)
tin2 = int(in2)
in2 = list(in2)

print(in1*int(in2[2]))
print(in1*int(in2[1]))
print(in1*int(in2[0]))
print(in1*tin2)



in1, in2 = input().split()
in1 = int(in1)
in2 = int(in2)

if in1 > in2:
    print(">")
elif in1 < in2:
    print("<")
else:
    print("==")



in1 = int(input())

if in1%4 == 0 and (in1%100 != 0 or in1%400 == 0):
    print(1)
else:
    print(0)



H, M = input().split()
H1 = int(H)
M1 = int(M)

M2 = M1-45

if M2 < 0:
    if H1 == 0:
        print("{} {}".format(23, M2+60))
    else:
        print("{} {}".format(H1-1, M2+60))
else:
    print("{} {}".format(H1, M2))



in1, in2, in3 = input().split()
in1 = int(in1)
in2 = int(in2)
in3 = int(in3)
inlist = [in1, in2, in3]
inlist.sort()
print(inlist[1])



tenum = int(input())
for i in range (tenum):
    in1, in2 = input().split()
    in1 = int(in1)
    in2 = int(in2)
    print(in1+in2)



in1 = int(input())
print(sum(range(in1))+in1)




tenum = int(sys.stdin.readline())
for i in range(tenum):
    in1, in2 = sys.stdin.readline().rstrip().split()
    in1 = int(in1)
    in2 = int(in2)
    print(in1+in2)



n = int(sys.stdin.readline())
for i in range(1,n+1):
    print(i)



n = int(sys.stdin.readline())
for i in range(n):
    print(n-i)



t = int(sys.stdin.readline())
for i in range(t):
    in1, in2 = sys.stdin.readline().rstrip().split()
    in1 = int(in1)
    in2 = int(in2)
    print("Case #{}: {}".format(i+1,in1+in2))



t = int(sys.stdin.readline())
for i in range(t):
    in1, in2 = sys.stdin.readline().rstrip().split()
    in1 = int(in1)
    in2 = int(in2)
    print("Case #{}: {} + {} = {}".format(i+1, in1, in2, in1+in2))



n = int(sys.stdin.readline())
for i in range(1,n+1):
    print(" "*(n-i)+"*"*i)



n, x = sys.stdin.readline().rstrip().split()
alist = sys.stdin.readline().rstrip().split()
n = int(n)
x = int(x)
alist = list(map(int,alist))

for i in range(n):
    if alist[i] < x:
        print(alist[i], end=" ")



while True:
    in1, in2 = sys.stdin.readline().rstrip().split()
    in1 = int(in1)
    in2 = int(in2)
    if in1 == 0 and in2 == 0:
        break
    print(in1+in2)



while True:
    try:
        in1, in2 = sys.stdin.readline().rstrip().split()
        in1 = int(in1)
        in2 = int(in2)
        print(in1+in2)
    except:
        break

#using while True - there should be 'break'



inp = sys.stdin.readline().rstrip()
in1 = int(int(inp)/10)
in2 = int(inp)%10
count = 0

while True:
    in3 = in1 + in2
    in3 = in3%10
    in1 = in2
    in2 = in3
    count += 1
    if in1*10 + in2 == int(inp):
        print(count)
        break



n = int(sys.stdin.readline())
inp = sys.stdin.readline().rstrip().split()
inp = list(map(int,inp))
inp.sort()
print(inp[0], inp[n-1])



inp = []
for i in range(9):
    inp.append(int(sys.stdin.readline()))
    
m = 0

for i in range(1,9):
    if inp[m] < inp[i]:
        m = i

print(inp[m], m+1, sep = "\n")



a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
c = int(sys.stdin.readline())

abc = a*b*c
abc = str(abc)
abc = list(abc)
abc = list(map(int,abc))

for i in range(10):
    count = 0
    for j in range(len(abc)):
        if abc[j] == i:
            count += 1
    print(count)

'''

'''

import sys
import copy

N = int(sys.stdin.readline())
c = 0

for i in range(N):
    S1 = list(sys.stdin.readline().rstrip())
    S2 = copy.deepcopy(S1)

    for j in range(len(S2)-1,-1,-1):
        if S2.count(S2[j]) > 1:
            del S2[j]
    d1 = 0
    d2 = 0
    
    for k in range(len(S1)):
        d2 = S2.index(S1[k])
        if d2 < d1:
            break

        d1 = d2

        if k == len(S1)-1:
            c += 1

print (c)

'''


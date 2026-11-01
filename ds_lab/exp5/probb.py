'''
d, sumTime
[minTime, maxTime]

d1, d2, d3, d4, ....., dn
sum = sumTime

minTime <= di <= maxTime 
i = 1...n
'''
def isPossible(time, sumTime: int) -> None:
    timeSum = []
    maxPossible = []
    for i in range(len(time)):
        timeSum.append(time[i][0])
        maxPossible.append(time[i][1])
    if sum(timeSum) > sumTime or sum(maxPossible) < sumTime:
        print("NO")
        return
    elif sum(timeSum) == sumTime:
        print("YES")
        print(*timeSum)
    else:
        curSum = sum(timeSum)
        i = 0
        while i < len(time) and curSum < sumTime:
            if timeSum[i] <= time[i][1]:
                timeSum[i] += 1
            else:
                i += 1
        if sum(timeSum) == sumTime:
            print("YES")
            print(*timeSum)
        else:
            print("NO")        

d, sumTime = map(int, input().split())
time = []

for _ in range(d):
    minTime, maxTime = map(int, input().split())
    time.append([minTime, maxTime])

isPossible(time, sumTime)

def upper_bound(a, x):
    le, ri = 0, len(a) - 1
    while le <= ri:
        mid = (le + ri) / 2
        midVal = a[mid]
        if midVal > x:
            ri = ri - 1
        else:
            le = le + 1
    if le - 1 >= 0 and a[le - 1] == x:
        return le - 1
    else:
        return le

def lower_bound(a, x):
    le, ri = 0, len(a) - 1
    while le <= ri:
        mid = (le + ri) / 2
        midVal = a[mid]
        if midVal >= x:
            ri = ri - 1
        else:
            le = le + 1
    if ri + 1 < len(a) and a[ri + 1] == x:
        return ri + 1
    else:
        return ri

            
f = [1, 2]
i = 0;
lim = 10 ** 100
while True:
    num = f[-1] + f[-2]
    if num > lim:
        break
    f.append(num)

while True:
    line = raw_input()
    (a, b) = map(int, line.split(' '))
    if a == 0 and b == 0:
        break
    print lower_bound(f, b) - upper_bound(f, a) + 1


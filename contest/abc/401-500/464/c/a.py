n, m = map(int, input().split())

d = {}
for i in range(n):
    d[i] = set()

kind = [0]*n
s = set()
va = list()
vb = list()
vd = list()
for i in range(n):
    a, d, b = map(int, input().split())
    va.append(a)
    vd.append(d)
    vb.append(b)
    s.add(a)
    kind[a-1] += 1

print(va)
print(vd)
print(vb)
print(kind)

for i in range(n):
    if 

for i in range(n):
    if vd[i] == i+1:
        s = s - set(va[i])
        s.add(vb[i])
    print(s)
    print(len(s))

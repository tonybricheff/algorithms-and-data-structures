import mmap				#BFS ��������

def tokenGen():
  with open('input.txt', 'r') as inf:
    tokens, count, cur = [], 0, 0
    mm = mmap.mmap(inf.fileno(), 0, access=mmap.ACCESS_READ)
    while True:
      while cur == count:
        tokens = mm.readline().split()
        count = len(tokens)
        cur = 0
      cur += 1
      yield tokens[cur-1]
token = tokenGen()
def nextStr(): return next(token)
def nextInt(): return int(nextStr())

with open('output.txt', 'w') as ouf:
  n,m = nextInt() + 1, nextInt()
  e = [[] for i in range(0,n)]
  color = [0 for i in range(0,n)]
  for i in range(0, m):
    x,y = nextInt(), nextInt()
    e[x].append(y)
    e[y].append(x)
  def isBipartite():
    for s in range(1,n):
      if color[s] == 0:
        q = [s]
        color[s] = 1
        head = 0
        while head < len(q):
          u = q[head]
          head += 1
          for v in e[u]:
            if color[v] == color[u]:
              return False
            elif color[v] == 0:
              q.append(v)
              color[v] = 3 - color[u]
    return True
  ouf.write("YES" if isBipartite() else "NO")
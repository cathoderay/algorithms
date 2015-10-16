
class QUW:
    def __init__(self, n):
        self.pi = range(0, n + 1)
        self.size = [1]*(n + 1)

    def union(self, a, b):
        ra = self.find(a)
        rb = self.find(b)
        if ra == rb: return

        if self.size[ra] < self.size[rb]:
           self.pi[ra] = rb;
           self.size[rb] += self.size[ra]
        else:
            self.pi[rb] = ra
            self.size[ra] += self.size[rb]

    def find(self, a):
        while not self.pi[a] == a:
            a = self.pi[a]
        return a

    def connected(self, a, b):
        return self.find(a) == self.find(b)

    def add(self, a, b):
        if not self.connected(a, b):
            self.union(a, b)
        

if __name__ == '__main__':
    QUW = QUW(10)
    QUW.add(1, 6)
    QUW.add(7, 6)
    QUW.add(2, 3)
    QUW.add(3, 8)
    QUW.add(4, 5)
    QUW.add(4, 9)
    QUW.add(5, 10)

    assert QUW.connected(1, 6) == True
    assert QUW.connected(8, 4) == False

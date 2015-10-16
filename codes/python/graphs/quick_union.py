
class QU:
    def __init__(self, n):
        self.pi = range(0, n + 1)

    def union(self, a, b):
        self.pi[self.find(a)] = self.find(b)

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
    QU = QU(10)
    QU.add(1, 6)
    QU.add(7, 6)
    QU.add(2, 3)
    QU.add(3, 8)
    QU.add(4, 5)
    QU.add(4, 9)
    QU.add(5, 10)

    assert QU.connected(1, 6) == True
    assert QU.connected(8, 4) == False

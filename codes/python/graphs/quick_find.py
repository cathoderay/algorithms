
class QF:
    def __init__(self, n):
        self.ids = range(0, n + 1)

    def union(self, a, b):
        ida = self.ids[a]
        idb = self.ids[b]
        for i, v in enumerate(self.ids):
            if v == ida:
                self.ids[i] = idb

    def find(self, a):
        return self.ids[a]

    def connected(self, a, b):
        return self.find(a) == self.find(b)

    def add(self, a, b):
        if not self.connected(a, b):
            self.union(a, b)
        

if __name__ == '__main__':
    QF = QF(10)
    QF.add(1, 6)
    QF.add(7, 6)
    QF.add(2, 3)
    QF.add(3, 8)
    QF.add(4, 5)
    QF.add(4, 9)
    QF.add(5, 10)

    assert QF.connected(1, 6) == True
    assert QF.connected(8, 4) == False

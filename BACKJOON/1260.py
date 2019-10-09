class Queue() :
    def __init__(self) :
        self.data = list()
    def push(self, value) :
        self.data.append(value)
    def pop(self) : 
        if len(self.data) == 0 :
            return -1
        value = self.data[0]
        del self.data[0]
        return value
    def size(self) :
        return len(self.data)

var_input = input().split()
N = int(var_input[0])
count = int(var_input[1])
start_node = int(var_input[2])

graphs = list()
d_visit = list()
b_visit = list()

i = 0
while i <= N :
    graphs.append(list())
    d_visit.append(False)
    b_visit.append(False)
    i += 1

i = 0
while i < count :
    var_m = input().split()
    graphs[int(var_m[0])].append(int(var_m[1]))
    graphs[int(var_m[1])].append(int(var_m[0]))
    i += 1

for graph in graphs :
    graph = graph.sort()

def DFS(start_node) : 
    print(start_node, end = ' ')
    d_visit[start_node] = True
    for search in graphs[start_node] :
        if d_visit[search] == False :
            DFS(search)

def BFS() :
    queue = Queue()
    queue.push(start_node)
    b_visit[start_node] = True

    while queue.size() > 0 :
        next_node = queue.pop()
        print(next_node, end = ' ')
        for search in graphs[next_node] :
            if b_visit[search] == False :
                b_visit[search] = True
                queue.push(search)

DFS(start_node)
print()
BFS()

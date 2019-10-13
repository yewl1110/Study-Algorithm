N = int(input())
NN = int(input())

graph = list()
visit = list()
i = 0
while i <= N:
    graph.append(list())
    visit.append(False)
    i += 1

i = 0
while i < NN:
    var_input = input().split()
    graph[int(var_input[0])].append(int(var_input[1]))
    graph[int(var_input[1])].append(int(var_input[0]))
    i += 1
count = 0

def DFS(current):
    global count
    count += 1
    visit[current] = True
    for search in graph[current]:
        if visit[search] == False:
            DFS(search)
DFS(1)
print(count - 1, end = '')

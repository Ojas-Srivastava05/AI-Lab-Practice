from queue import Queue
graph={
    "A":[("B",10),("C",30)],
    "B":[("D",50)],
    "C":[("E",40)],
    "D":[]
}

def bfs(source,destination,graph):
    queue=Queue()
    queue.put((source,[source],0))
    allroute=[]
    while not queue.empty():
        node,path,cost=queue.get()

        if node==destination:
            allroute.append((path,cost))
        
        else:
            for neighbour,weight in graph.get(node,[]):
                if neighbour in path:
                    continue
                queue.put((neighbour,path+[neighbour],cost+weight))

    return allroute

bfs_routes = bfs("A", "D",graph)
for p, d in bfs_routes:
    print(f"Path: {' -> '.join(p)} | Distance: {d}")



def dfs(src,des,graph,path,dist,allroute):
    path=path+[src]
    if src==des:
        allroute.append((path,dist))
        return 
    
    for neighbour,wt in graph.get(src,[]):
        if neighbour in allroute:
            continue
        dfs(neighbour,des,graph,path,dist+wt,allroute)

dfs_routes = []
dfs("A","D",graph,[],0,dfs_routes)
for p, d in dfs_routes:
    print(f"Path: {' -> '.join(p)} | Distance: {d}")
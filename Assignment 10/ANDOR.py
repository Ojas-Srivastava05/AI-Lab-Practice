def solve(loc, A, B, visited):
    if (loc, A, B) in visited:
        return False

    if A==1 and B==1:
        return True

    visited.add((loc, A, B))

    # Suck
    if loc=='A':
        if solve('A',1,B,visited) and solve('A',1,1,visited):
            return True
    else:
        if solve('B',A,1,visited) and solve('B',1,1,visited):
            return True

    # Move
    if loc=='A':
        if solve('B',A,B,visited):
            return True
    else:
        if solve('A',A,B,visited):
            return True

    return False

print(solve('A',0,0,set()))
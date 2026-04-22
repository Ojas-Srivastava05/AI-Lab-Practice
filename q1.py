def forwardchaining(rules,facts,goal):
    inferred=True
    while inferred:
        inferred=False
        for preconditions,conclusion in rules:
            if conclusion not in facts:
                if all(p in preconditions for p in preconditions):
                    facts.add(conclusion)
                    inferred=True

                    if conclusion==goal:
                        return True
                    
    return False

import heapq

#chatgpt generated djikstras
def dijkstra_with_edge_limit(graph, start, end, max_edges):

    # Create a priority queue for Dijkstra's algorithm
    queue = [(0, start, 0)]  # (distance, node, number of edges)
    visited = set()

    while queue:
        dist, current, edges_traversed = heapq.heappop(queue)

        # Check if the current node is the destination
        if current == end:
            return f"Total cost of flight(s) is ${dist}"

        # If the number of edges traversed exceeds the limit, skip the node
        if edges_traversed > max_edges:
            continue

        # If the node has already been visited, skip it
        if current in visited:
            continue

        visited.add(current)

        # Explore neighbors and update the distances
        for neighbor, weight in graph[current].items():
            new_dist = dist + weight
            heapq.heappush(queue, (new_dist, neighbor, edges_traversed + 1))

    return "No satisfactory flights"




input() # num scenerios
input() # blank line
c = 1
while(True):
    try:
        
        d ={}
        for i in range(int(input())):
            d[input()] = {}

        print(f"Scenario #{c}")
        for i in range(int(input())):
            text = input() 
            text = text.split(" ")
            if text[1] in d[text[0]]:
                if d[text[0]][text[1]] > int(text[2]):
                    d[text[0]][text[1]] = int(text[2])
            else:
                d[text[0]][text[1]] = int(text[2])
            
            

        text = input() #cases
        text = text.split(" ")
        text = text[1:]

        for edge_limit in text:
            result = dijkstra_with_edge_limit(d, 'Calgary', 'Fredericton', int(edge_limit))
            print(result)
        c = c + 1
        input() # blank line
        print()
    except EOFError:
        break
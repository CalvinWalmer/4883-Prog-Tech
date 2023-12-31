# Python3 code for printing shortest path between
# two vertices of unweighted graph
#CODE TAKEN FROM GEEKS FOR GEEKS

# utility function to form edge between two vertices
# source and dest
def add_edge(adj, src, dest):

	adj[src].append(dest)
	adj[dest].append(src)

# a modified version of BFS that stores predecessor
# of each vertex in array p
# and its distance from source in array d
def BFS(adj, src, dest, v, pred, dist):

	# a queue to maintain queue of vertices whose
	# adjacency list is to be scanned as per normal
	# DFS algorithm
	queue = []

	# boolean array visited[] which stores the
	# information whether ith vertex is reached
	# at least once in the Breadth first search
	visited = [False for i in range(v)]

	# initially all vertices are unvisited
	# so v[i] for all i is false
	# and as no path is yet constructed
	# dist[i] for all i set to infinity
	for i in range(v):

		dist[i] = 1000000
		pred[i] = -1
	
	# now source is first to be visited and
	# distance from source to itself should be 0
	visited[src] = True
	dist[src] = 0
	queue.append(src)

	# standard BFS algorithm
	while (len(queue) != 0):
		u = queue[0]
		queue.pop(0)
		for i in range(len(adj[u])):
		
			if (visited[adj[u][i]] == False):
				visited[adj[u][i]] = True
				dist[adj[u][i]] = dist[u] + 1
				pred[adj[u][i]] = u
				queue.append(adj[u][i])

				# We stop BFS when we find
				# destination.
				if (adj[u][i] == dest):
					return True

	return False

# utility function to print the shortest distance
# between source vertex and destination vertex
def shortestPath(adj, s, dest, v):
	
	# predecessor[i] array stores predecessor of
	# i and distance array stores distance of i
	# from s
	pred=[0 for i in range(v)]
	dist=[0 for i in range(v)]

	if (BFS(adj, s, dest, v, pred, dist) == False):
		return None

	# vector path stores the shortest path
	path = []
	crawl = dest
	# path.append(crawl)
	
	while (pred[crawl] != -1):
		path.insert(0, (pred[crawl], crawl))
		crawl = pred[crawl]
	

	# # distance from source is in distance array
	# print("Shortest path length is : " + str(dist[dest]), end = '')

	return(path)



while(True):
	numEdges = int(input())
	nodes = []
	lines = []
	start = ''
	end = ''

	for i in range(numEdges + 1):
		line = input()
		line = line.split(' ')
		
		if not line[0] in nodes:
			nodes.append(line[0])
		if not line[1] in nodes:
			nodes.append(line[1])
		if i == numEdges:
			start = line[0]
			end = line[1]
		else:
			lines.append(line)




	lookupName = {}
	lookupNum = {}
	i = 0
	for key in nodes:
		lookupName[key] = i
		lookupNum[i] = key
		i = i + 1
		

	v = len(nodes)

	adj = [[] for _ in range(v)]

	for line in lines:
		add_edge(adj, lookupName[line[0]], lookupName[line[1]])
		add_edge(adj, lookupName[line[1]], lookupName[line[0]])

	path = shortestPath(adj, lookupName[start], lookupName[end], v)
	if path == None:
		print('No route')
	else:
		for pair in path:
				print(lookupNum[pair[0]] + " " + lookupNum[pair[1]])

	try:
		input()
		print()
	except:
		exit()
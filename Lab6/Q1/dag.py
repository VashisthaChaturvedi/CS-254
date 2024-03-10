import random

def generate_dag(N, M):
  """
  Generates a directed acyclic graph (DAG) with N vertices and M edges.

  Args:
      N: Number of vertices (0 to N-1).
      M: Number of edges.

  Returns:
      A list of strings representing the connections between vertices, in the format "A B".
  """
  # Initialize empty graph
  graph = []

  # Ensure M edges are less than total possible connections (N^2 - N) for a DAG
  M = min(M, N * (N - 1))

  # Add edges randomly while avoiding cycles
  while M > 0:
    source = random.randint(0, N - 1)
    target = random.randint(0, N - 1)

    # Avoid self-loops and edges going from higher numbered vertex to lower
    if source != target and source < target:
      # Check for cycles by ensuring target doesn't have incoming edges from source (already visited)
      cycle_free = True
      for edge in graph:
        if edge.split()[1] == str(source):
          cycle_free = False
          break
      if cycle_free:
        graph.append(str(source) + " " + str(target))
        M -= 1

  return graph


def write_to_file(filename, connections):

  with open(filename, "w") as f:
    for edge in connections:
      f.write(edge + "\n")



T = 1
with open("input.in","w") as f:

  while T>0:

    N = random.randint(0,10)
    M = random.randint(0,N*(N-1)/2)
    connections = generate_dag(N, M)
    f.write(str(N)+" "+str(M)+"\n")
    for edge in connections:
      f.write(edge+"\n")
      print("\n")
    T-=1



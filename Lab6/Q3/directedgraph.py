import random


def generate_dag(N, M):

    graph = []

    M = min(M, N * (N - 1))

    # Add edges randomly while avoiding cycles
    while M > 0:
        source = random.randint(0, N - 1)
        target = random.randint(0, N - 1)
        graph.append(str(source) + " " + str(target))
        M -= 1

    return graph


T = 20
with open("input.in", "w") as f:
    f.write(str(T)+"\n")
    while T > 0:

        N = random.randint(0, 50)
        M = random.randint(0, N*(N-1)/2)
        connections = generate_dag(N, M)
        f.write(str(N)+" "+str(M)+"\n")
        for edge in connections:
            f.write(edge+"\n")
            print("\n")
        f.write("\n")
        T -= 1

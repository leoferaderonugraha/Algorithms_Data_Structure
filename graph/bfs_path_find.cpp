#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Graph
{
    private:
    std::vector<std::vector<int>> Edges;
    std::vector<bool> visited;
    std::vector<int> prev;
    public:
    Graph(int n)
    {
        Edges.resize(n);
        visited.resize(n);
        prev.resize(n);
        std::fill(visited.begin(), visited.end(), false);
        // for reconstructing, so we can know when to stop
        std::fill(prev.begin(), prev.end(), -1);
    }

    void connect(int p1, int p2)
    {
        Edges[p1].push_back(p2);
        Edges[p2].push_back(p1);
    }

    void reconstruct_path(int start, int dest)
    {
        // check if the input is valid
        if (dest > Edges.size() || (dest - 1) < 0) {
            std::cout << "\nNo path found to " << dest << std::endl;
            return;
        }

        std::vector<int> path;
        for (int at = dest; at != -1; at = prev[at]) {
            path.push_back(at);
        }

        std::reverse(path.begin(), path.end());

        if(path.front() == start) {
            std::cout << "\nraw path data: ";
            for (auto &i : prev) {
                std::cout << i << ' ';
            }

            std::cout << "\nreconstructed path: ";
            for (int &p : path) {
                std::cout << p << ' ';
            }
        } else {
            // this mean that the dest is disconnected
            // from the starting point
            std::cout << "\nNo path found to " << dest << std::endl;
        }

        std::cout << std::endl;
    }

    void BFS_Path(int start, int dest)
    {
        std::queue<int> Queue;

        Queue.push(start);
        visited[start] = true;
        bool found = false;

        std::cout << "Starting from " << start << " to " << dest << ": ";

        while (!Queue.empty() && !found) {
            start = Queue.front();
            Queue.pop();

            for (int &edge : Edges[start]) {
                if (!visited[edge]) {
                    Queue.push(edge);
                    visited[edge] = true;
                    prev[edge] = start;
                    // some minor improvement to decrease time usages for larger graph
                    if (edge == dest) {
                        found = true;
                        break;
                    }
                    //std::cout << edge << ' ';
                }
            }
        }
    }
};

int main()
{

    /*
            0
        |       |
        1   -   2 - 5
                |
                3
                |
                4 - 6
        
        7
        |   (disconnected from the rest of the graph)
        9
    */

    Graph g(10);
    g.connect(0, 1);
    g.connect(1, 2);
    g.connect(2, 0);
    g.connect(2, 3);
    g.connect(3, 4);
    g.connect(5, 2);
    g.connect(6, 4);
    g.connect(7, 9);

    int p1, p2;

    std::cout << "From: ";
    std::cin >> p1;
    std::cout << "To: ";
    std::cin >> p2;

    g.BFS_Path(p1, p2);
    g.reconstruct_path(p1, p2);

    // for (auto &i : g.prev) {
    //     std::cout << i << ' ';
    // }
    // std::cout << '\n';
}

#include <iostream>
using namespace std;

class adjNode
{
public:
    int vertex;
    adjNode *next;

    // Constructor
    adjNode(int v) : vertex(v), next(NULL) {}
};

class AdjList
{
private:
    int v;           // Number of vertices
    adjNode **graph; // Array of adjacency lists

public:
    // Constructor
    AdjList(int vertices)
    {
        v = vertices;
        graph = new adjNode *[v];
        for (int i = 0; i < v; i++)
            graph[i] = NULL; // Initialize all adjacency lists to NULL
    }

    // Add an edge
    void addEdge(int source, int destination)
    {
        // Add edge from source to destination
        adjNode *newNode = new adjNode(destination);
        newNode->next = graph[source];
        graph[source] = newNode;

        // Add edge from destination to source (since the graph is undirected)
        newNode = new adjNode(source);
        newNode->next = graph[destination];
        graph[destination] = newNode;
    }

    // Function to sort the linked list of each vertex
    void sortAdjList()
    {
        for (int i = 0; i < v; i++)
        {
            // Convert the linked list to an array
            int count = 0;
            adjNode *temp = graph[i];
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }

            int *neighbors = new int[count];
            temp = graph[i];
            for (int j = 0; j < count; j++)
            {
                neighbors[j] = temp->vertex;
                temp = temp->next;
            }

            // Sort the array using a simple bubble sort
            for (int j = 0; j < count - 1; j++)
            {
                for (int k = 0; k < count - j - 1; k++)
                {
                    if (neighbors[k] > neighbors[k + 1])
                    {
                        int temp = neighbors[k];
                        neighbors[k] = neighbors[k + 1];
                        neighbors[k + 1] = temp;
                    }
                }
            }

            // Rebuild the sorted linked list
            graph[i] = NULL;
            for (int j = count - 1; j >= 0; j--)
            {
                adjNode *newNode = new adjNode(neighbors[j]);
                newNode->next = graph[i];
                graph[i] = newNode;
            }

            delete[] neighbors;
        }
    }

    // Print the adjacency list
    void printGraph()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << ": ";
            adjNode *temp = graph[i];
            while (temp != NULL)
            {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Destructor to free memory
    ~AdjList()
    {
        for (int i = 0; i < v; i++)
        {
            adjNode *temp = graph[i];
            while (temp != NULL)
            {
                adjNode *next = temp->next;
                delete temp;
                temp = next;
            }
        }
        delete[] graph;
    }
};

int main()
{
    // Input: Number of vertices and edges
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Create the graph
    AdjList graph(V);

    // Input: Edges
    cout << "Enter the edges (source and destination pairs):" << endl;
    for (int i = 0; i < E; i++)
    {
        int source, destination;
        cin >> source >> destination;
        graph.addEdge(source, destination);
    }

    // Sort the adjacency list
    graph.sortAdjList();

    // Print the adjacency list
    cout << "Adjacency List representation of the graph (sorted):" << endl;
    graph.printGraph();

    return 0;
}
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TaskNode
{
    string taskName;
    int taskPriority;

    TaskNode() {}
    TaskNode(string name, int priority) : taskName(name), taskPriority(priority) {}
};

class PriorityQueue
{
private:
    TaskNode *heapArray;
    int maxCapacity;
    int currentSize;

    int getParentIndex(int index) { return (index - 1) / 2; }
    int getLeftChildIndex(int index) { return 2 * index + 1; }
    int getRightChildIndex(int index) { return 2 * index + 2; }

    void siftUp(int index)
    {
        while (index > 0 && heapArray[getParentIndex(index)].taskPriority < heapArray[index].taskPriority)
        {
            swap(heapArray[getParentIndex(index)], heapArray[index]);
            index = getParentIndex(index);
        }
    }

    void siftDown(int index)
    {
        int highest = index;
        int left = getLeftChildIndex(index);
        int right = getRightChildIndex(index);

        if (left < currentSize && heapArray[highest].taskPriority < heapArray[left].taskPriority)
            highest = left;
        if (right < currentSize && heapArray[highest].taskPriority < heapArray[right].taskPriority)
            highest = right;

        if (highest != index)
        {
            swap(heapArray[highest], heapArray[index]);
            siftDown(highest);
        }
    }

public:
    PriorityQueue(int capacity) : maxCapacity(capacity), currentSize(0)
    {
        heapArray = new TaskNode[maxCapacity];
    }

    ~PriorityQueue()
    {
        delete[] heapArray;
    }

    void addTask(TaskNode task)
    {
        if (currentSize == maxCapacity)
        {
            cout << "Queue is full, cannot add more tasks.\n";
            return;
        }
        heapArray[currentSize] = task;
        siftUp(currentSize);
        currentSize++;
    }

    TaskNode processTask()
    {
        if (currentSize <= 0)
        {
            cout << "No tasks in the queue!\n";
            exit(1);
        }
        TaskNode topTask = heapArray[0];
        heapArray[0] = heapArray[currentSize - 1];
        currentSize--;
        siftDown(0);
        return topTask;
    }

    bool isQueueEmpty()
    {
        return currentSize == 0;
    }
};

int main()
{
    srand(time(0));
    int taskCount;

    cout << "How many tasks do you want to schedule? ";
    cin >> taskCount;

    PriorityQueue taskQueue(taskCount);

    for (int i = 1; i <= taskCount; i++)
    {
        int priority = rand() % 10 + 1;
        string taskName = "Task_" + to_string(i);
        taskQueue.addTask(TaskNode(taskName, priority));
        cout << "Added " << taskName << " with a priority of " << priority << " to the queue.\n";
    }

    cout << "\nTasks will now be handled in descending order of priority:\n";

    while (!taskQueue.isQueueEmpty())
    {
        TaskNode currentTask = taskQueue.processTask();
        cout << "Now processing " << currentTask.taskName << " with priority level " << currentTask.taskPriority << ".\n";
    }

    return 0;
}

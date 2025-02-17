#include <iostream>
#include <list>
#include <algorithm>
#include<string>
using namespace std;

class Process {
public:
    int pid;
    int arrival_time;
    int cpu_burst;
    int start_time;
    int finish_time;
    int waiting_time;
    int turnaround_time;

    Process(int pid, int arrival_time, int cpu_burst) :
        pid(pid), arrival_time(arrival_time), cpu_burst(cpu_burst),
        start_time(0), finish_time(0), waiting_time(0), turnaround_time(0) {}

    string toString() {
        return "Process " + to_string(pid) + " (arrival time: " + to_string(arrival_time) +
            ", cpu burst: " + to_string(cpu_burst) + ")";
    }
};

pair<int*, int*> fcfs(Process* processes, int num_processes) {
    int* waiting_times = new int[num_processes];
    int* finish_times = new int[num_processes];
    int current_time = 0;

    for (int i = 0; i < num_processes; i++) {
        waiting_times[i] = max(0, current_time - processes[i].arrival_time);
        processes[i].start_time = current_time;
        current_time += processes[i].cpu_burst;
        processes[i].finish_time = current_time;
    }

    return make_pair(waiting_times, finish_times);
}

pair<int*, int*> srt(Process* processes, int num_processes) {
    int* waiting_times = new int[num_processes];
    int* finish_times = new int[num_processes];
    int current_time = 0;

    // Sort processes by CPU burst
    sort(processes, processes + num_processes, [](const Process& a, const Process& b) {
        return a.cpu_burst < b.cpu_burst;
        });

    for (int i = 0; i < num_processes; i++) {
        waiting_times[processes[i].pid] = max(0, current_time - processes[i].arrival_time);
        processes[i].start_time = max(current_time, processes[i].arrival_time);
        current_time += processes[i].cpu_burst;
        processes[i].finish_time = current_time;
    }

    return make_pair(waiting_times, finish_times);
}

pair<int*, int*> round_robin(Process* processes, int num_processes, int time_quantum) {
    int* waiting_times = new int[num_processes];
    int* finish_times = new int[num_processes];
    int current_time = 0;
    list<Process> ready_queue;

    for (int i = 0; i < num_processes; i++) {
        if (processes[i].arrival_time <= current_time) {
            ready_queue.push_back(processes[i]);
        }
    }

    while (!ready_queue.empty()) {
        Process process = ready_queue.front();
        ready_queue.pop_front();

        waiting_times[process.pid] = max(0, current_time - process.arrival_time);
        process.start_time = max(current_time, process.arrival_time);

        int remaining_burst = process.cpu_burst;
        while (remaining_burst > 0) {
            int to_process = min(remaining_burst, time_quantum);
            remaining_burst -= to_process;
            current_time += to_process;

            if (remaining_burst > 0) {
                ready_queue.push_back(process); // Process not finished, push back to queue
            }
        }

        process.finish_time = current_time;
        finish_times[process.pid] = current_time;
    }

    return make_pair(waiting_times, finish_times);
}

void calculate_turnaround_times(Process* processes, int num_processes, const int* waiting_times, const int* finish_times) {
    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = finish_times[i] - processes[i].arrival_time;
    }
}
int main() {
    // Create an array of processes with sample data
    Process processes[] = {
      Process(1, 0, 5),
      Process(2, 1, 3),
      Process(3, 2, 2)
    };
    int num_processes = sizeof(processes) / sizeof(processes[0]);

    // Choose a scheduling algorithm to use
    pair<int*, int*> results = fcfs(processes, num_processes); // Example using FCFS
    // Or use srt or round_robin instead

    // Calculate turnaround times
    calculate_turnaround_times(processes, num_processes, results.first, results.second);

    // Print the results (you can modify this to display the results as needed)
    for (int i = 0; i < num_processes; i++) {
        cout << "Process " << processes[i].pid << ": " << endl;
        cout << "\tWaiting time: " << results.first[i] << endl;
        cout << "\tTurnaround time: " << processes[i].turnaround_time << endl;
    }

    return 0;
}

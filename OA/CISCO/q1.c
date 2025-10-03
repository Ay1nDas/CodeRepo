#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Data Structures ---

// For Adjacency List
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    AdjListNode* head;
} AdjList;

typedef struct Graph {
    int V;
    AdjList* array;
} Graph;

// For Hash Table (used as HashMap and HashSet)
#define HT_CAPACITY 1024
typedef struct HT_Item {
    int key;
    int value;
    int is_occupied;
} HT_Item;

typedef struct HashTable {
    HT_Item items[HT_CAPACITY];
    int keys[HT_CAPACITY];
    int key_count;
} HashTable;

// For BFS Queue
typedef struct QueueItem {
    int user;
    int depth;
} QueueItem;

typedef struct Queue {
    QueueItem* items;
    int front, rear, size, capacity;
} Queue;


// --- Forward Declarations for Functions ---
HashTable* findReachableUsers(Graph* graph, int startNode, int maxDepth);


// --- Graph Functions ---
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc((V + 1) * sizeof(AdjList));
    for (int i = 0; i <= V; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = src;
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void freeGraph(Graph* graph) {
    for (int i = 0; i <= graph->V; i++) {
        AdjListNode* pCrawl = graph->array[i].head;
        while (pCrawl != NULL) {
            AdjListNode* temp = pCrawl;
            pCrawl = pCrawl->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}

// --- Hash Table Functions ---
unsigned int hash(int key) {
    return key % HT_CAPACITY;
}

void ht_init(HashTable* ht) {
    ht->key_count = 0;
    for (int i = 0; i < HT_CAPACITY; i++) {
        ht->items[i].is_occupied = 0;
    }
}

void ht_put(HashTable* ht, int key, int value) {
    unsigned int index = hash(key);
    while (ht->items[index].is_occupied && ht->items[index].key != key) {
        index = (index + 1) % HT_CAPACITY;
    }
    if (!ht->items[index].is_occupied) {
       ht->keys[ht->key_count++] = key;
    }
    ht->items[index] = (HT_Item){key, value, 1};
}

int ht_get(HashTable* ht, int key, int* value) {
    unsigned int index = hash(key);
    while (ht->items[index].is_occupied) {
        if (ht->items[index].key == key) {
            *value = ht->items[index].value;
            return 1; // Found
        }
        index = (index + 1) % HT_CAPACITY;
    }
    return 0; // Not found
}

void ht_remove(HashTable* ht, int key) {
    // Note: Simple removal is tricky with linear probing. For this problem,
    // we just mark it as not occupied, which is sufficient.
    unsigned int index = hash(key);
    while (ht->items[index].is_occupied) {
        if (ht->items[index].key == key) {
            ht->items[index].is_occupied = 0;
            // Also remove from keys array to stop iteration over it
            for (int i = 0; i < ht->key_count; ++i) {
                if (ht->keys[i] == key) {
                    ht->keys[i] = ht->keys[ht->key_count - 1];
                    ht->key_count--;
                    break;
                }
            }
            return;
        }
        index = (index + 1) % HT_CAPACITY;
    }
}

// --- Queue Functions ---
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->items = (QueueItem*)malloc(q->capacity * sizeof(QueueItem));
    return q;
}

int is_empty(Queue* q) { return (q->size == 0); }

void enqueue(Queue* q, int user, int depth) {
    q->rear = (q->rear + 1) % q->capacity;
    q->items[q->rear] = (QueueItem){user, depth};
    q->size++;
}

QueueItem dequeue(Queue* q) {
    QueueItem item = q->items[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

void freeQueue(Queue* q) {
    free(q->items);
    free(q);
}

// --- Main Algorithm ---
int main() {
    // --- 1. Read Inputs ---
    int no_of_users, no_of_connections;
    scanf("%d %d", &no_of_users, &no_of_connections);

    Graph* graph = createGraph(no_of_users);
    for (int i = 0; i < no_of_connections; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int no_of_potential_seeds;
    scanf("%d", &no_of_potential_seeds);

    HashTable potential_seeds;
    ht_init(&potential_seeds);
    for (int i = 0; i < no_of_potential_seeds; i++) {
        int id, cost;
        scanf("%d %d", &id, &cost);
        ht_put(&potential_seeds, id, cost);
    }

    HashTable values;
    ht_init(&values);
    for (int i = 1; i <= no_of_users; i++) {
        int val;
        scanf("%d", &val);
        ht_put(&values, i, val);
    }

    int budget, depth;
    scanf("%d %d", &budget, &depth);

    // --- 2. Solve ---
    int chosen_seeds[no_of_users];
    int chosen_seeds_count = 0;
    long long total_value = 0;
    long long total_cost = 0;
    HashTable reached_users;
    ht_init(&reached_users);
    long long remaining_budget = budget;

    while (1) {
        double max_efficiency = -1.0;
        int best_seed = -1;
        long long best_seed_cost = 0;
        long long best_marginal_value = 0;
        HashTable* best_new_users = NULL;

        for (int i = 0; i < potential_seeds.key_count; ++i) {
            int current_seed_id = potential_seeds.keys[i];
            int current_seed_cost;
            ht_get(&potential_seeds, current_seed_id, &current_seed_cost);

            if (current_seed_cost > remaining_budget) continue;

            HashTable* reachable = findReachableUsers(graph, current_seed_id, depth);
            
            long long current_marginal_value = 0;
            HashTable* current_new_users = (HashTable*)malloc(sizeof(HashTable));
            ht_init(current_new_users);

            for (int j = 0; j < reachable->key_count; j++) {
                int user = reachable->keys[j];
                int dummy;
                if (!ht_get(&reached_users, user, &dummy)) {
                    int user_val;
                    ht_get(&values, user, &user_val);
                    current_marginal_value += user_val;
                    ht_put(current_new_users, user, 1);
                }
            }
            free(reachable);
            
            if (current_seed_cost > 0) {
                double efficiency = (double)current_marginal_value / current_seed_cost;
                if (efficiency > max_efficiency) {
                    max_efficiency = efficiency;
                    best_seed = current_seed_id;
                    best_seed_cost = current_seed_cost;
                    best_marginal_value = current_marginal_value;
                    if (best_new_users) free(best_new_users);
                    best_new_users = current_new_users;
                } else {
                    free(current_new_users);
                }
            } else {
                free(current_new_users);
            }
        }

        if (best_seed == -1 || best_marginal_value <= 0) {
            if (best_new_users) free(best_new_users);
            break;
        }

        chosen_seeds[chosen_seeds_count++] = best_seed;
        total_cost += best_seed_cost;
        total_value += best_marginal_value;
        remaining_budget -= best_seed_cost;
        
        for (int i = 0; i < best_new_users->key_count; i++) {
            ht_put(&reached_users, best_new_users->keys[i], 1);
        }
        
        ht_remove(&potential_seeds, best_seed);
        free(best_new_users);
    }

    // --- 3. Print Output ---
    printf("Chosen Seeds: [");
    for (int i = 0; i < chosen_seeds_count; i++) {
        printf("%d%s", chosen_seeds[i], (i == chosen_seeds_count - 1) ? "" : ", ");
    }
    printf("]\n");
    printf("Total Value: %lld\n", total_value);
    printf("Total Cost: %lld\n", total_cost);

    // --- 4. Cleanup ---
    freeGraph(graph);

    return 0;
}

// --- BFS Implementation ---
HashTable* findReachableUsers(Graph* graph, int startNode, int maxDepth) {
    HashTable* reachable = (HashTable*)malloc(sizeof(HashTable));
    ht_init(reachable);
    
    HashTable visited;
    ht_init(&visited);

    Queue* q = createQueue(graph->V + 1);

    enqueue(q, startNode, 0);
    ht_put(&visited, startNode, 1);

    while (!is_empty(q)) {
        QueueItem current = dequeue(q);
        int user = current.user;
        int depth = current.depth;

        ht_put(reachable, user, 1);

        if (depth >= maxDepth) continue;

        AdjListNode* pCrawl = graph->array[user].head;
        while (pCrawl) {
            int neighbor = pCrawl->dest;
            int dummy;
            if (!ht_get(&visited, neighbor, &dummy)) {
                ht_put(&visited, neighbor, 1);
                enqueue(q, neighbor, depth + 1);
            }
            pCrawl = pCrawl->next;
        }
    }
    freeQueue(q);
    return reachable;
}
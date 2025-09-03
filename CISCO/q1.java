import java.util.*;

public class Solution {

    // Adjacency list to represent the network graph
    private static Map<Integer, List<Integer>> adj = new HashMap<>();
    
    // Map to store the market value of each user
    private static Map<Integer, Integer> values = new HashMap<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // --- 1. Read Inputs ---
        int noOfUsers = scanner.nextInt();
        int noOfConnections = scanner.nextInt();

        for (int i = 0; i < noOfConnections; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            // Build undirected graph
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        int noOfPotentialSeeds = scanner.nextInt();
        Map<Integer, Integer> potentialSeeds = new HashMap<>();
        for (int i = 0; i < noOfPotentialSeeds; i++) {
            potentialSeeds.put(scanner.nextInt(), scanner.nextInt());
        }

        for (int i = 1; i <= noOfUsers; i++) {
            values.put(i, scanner.nextInt());
        }

        int budget = scanner.nextInt();
        int depth = scanner.nextInt();
        
        scanner.close();

        // --- 2. Main Algorithm Logic ---
        List<Integer> chosenSeeds = new ArrayList<>();
        long totalValue = 0;
        long totalCost = 0;
        Set<Integer> reachedUsers = new HashSet<>();
        long remainingBudget = budget;

        while (true) {
            double maxEfficiency = -1.0;
            int bestSeed = -1;
            long bestSeedCost = 0;
            long bestMarginalValue = 0;
            Set<Integer> bestNewUsers = new HashSet<>();

            // Find the most efficient seed among the remaining ones
            for (Map.Entry<Integer, Integer> entry : potentialSeeds.entrySet()) {
                int currentSeed = entry.getKey();
                int currentCost = entry.getValue();

                if (currentCost > remainingBudget) {
                    continue;
                }

                Set<Integer> reachableByCurrent = findReachableUsers(currentSeed, depth);
                Set<Integer> newUsers = new HashSet<>(reachableByCurrent);
                newUsers.removeAll(reachedUsers);

                long marginalValue = 0;
                for (int user : newUsers) {
                    marginalValue += values.get(user);
                }

                if (currentCost > 0) {
                    double efficiency = (double) marginalValue / currentCost;
                    if (efficiency > maxEfficiency) {
                        maxEfficiency = efficiency;
                        bestSeed = currentSeed;
                        bestSeedCost = currentCost;
                        bestMarginalValue = marginalValue;
                        bestNewUsers = newUsers;
                    }
                }
            }

            // --- 3. Stopping Condition ---
            // Stop if no effective seed was found (or all have 0 marginal value)
            if (bestSeed == -1 || bestMarginalValue <= 0) {
                break;
            }

            // --- 4. Update State with the Chosen Seed ---
            chosenSeeds.add(bestSeed);
            totalCost += bestSeedCost;
            totalValue += bestMarginalValue;
            remainingBudget -= bestSeedCost;
            reachedUsers.addAll(bestNewUsers);
            potentialSeeds.remove(bestSeed); // This seed can't be chosen again
        }

        // --- 5. Print Output ---
        System.out.println("Chosen Seeds: " + chosenSeeds);
        System.out.println("Total Value: " + totalValue);
        System.out.println("Total Cost: " + totalCost);
    }

    /**
     * Performs a Breadth-First Search (BFS) to find all users reachable from a 
     * start node within a maximum depth.
     * @param startNode The starting user ID for the search.
     * @param maxDepth  The maximum number of connections to traverse.
     * @return A Set of unique user IDs reachable within the given depth.
     */
    private static Set<Integer> findReachableUsers(int startNode, int maxDepth) {
        Set<Integer> reachable = new HashSet<>();
        Set<Integer> visited = new HashSet<>();
        Queue<int[]> queue = new LinkedList<>();

        // queue stores pairs of [userID, currentDepth]
        queue.add(new int[]{startNode, 0});
        visited.add(startNode);
        
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int user = current[0];
            int depth = current[1];

            reachable.add(user);

            if (depth >= maxDepth) {
                continue;
            }

            // Explore neighbors
            for (int neighbor : adj.getOrDefault(user, Collections.emptyList())) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.add(new int[]{neighbor, depth + 1});
                }
            }
        }
        return reachable;
    }
}
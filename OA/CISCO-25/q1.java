import java.util.*;
import java.util.stream.Collectors;

public class Solution {

    private static Map<Integer, List<Integer>> adj = new HashMap<>();
    private static Map<Integer, Integer> values = new HashMap<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int noOfUsers = scanner.nextInt();
        int noOfConnections = scanner.nextInt();

        for (int i = 0; i < noOfConnections; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
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

            if (bestSeed == -1 || bestMarginalValue <= 0) {
                break;
            }

            chosenSeeds.add(bestSeed);
            totalCost += bestSeedCost;
            totalValue += bestMarginalValue;
            remainingBudget -= bestSeedCost;
            reachedUsers.addAll(bestNewUsers);
            potentialSeeds.remove(bestSeed);
        }

        // --- FIX: Corrected Output Formatting ---
        if (chosenSeeds.isEmpty()) {
            System.out.println(""); // Or handle as per problem spec for no seeds
        } else {
            System.out.println(
                chosenSeeds.stream()
                           .map(String::valueOf)
                           .collect(Collectors.joining(" "))
            );
        }
        System.out.println(totalValue);
        System.out.println(totalCost);
    }

    private static Set<Integer> findReachableUsers(int startNode, int maxDepth) {
        Set<Integer> reachable = new HashSet<>();
        Set<Integer> visited = new HashSet<>();
        Queue<int[]> queue = new LinkedList<>();

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
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class BoggleSolver {

    // A static inner class for the Trie Node.
    static class TrieNode {
        TrieNode[] children = new TrieNode[26];
        String word = null; // If not null, this node marks the end of a word.
    }

    /**
     * The main solver function.
     * @param board The 2D character grid.
     * @param dictionary An array of words to search for.
     * @return A sorted list of unique words found on the board.
     */
    public List<String> findWords(char[][] board, String[] dictionary) {
        // 1. Build the Trie from the dictionary words.
        TrieNode root = new TrieNode();
        for (String word : dictionary) {
            insert(root, word);
        }

        Set<String> resultSet = new HashSet<>();
        int rows = board.length;
        int cols = board[0].length;
        boolean[][] visited = new boolean[rows][cols];

        // 2. Start a DFS from every cell on the board.
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root, visited, resultSet);
            }
        }

        // 3. Convert the set to a list and sort it alphabetically.
        List<String> sortedResult = new ArrayList<>(resultSet);
        Collections.sort(sortedResult);
        return sortedResult;
    }

    /**
     * Inserts a word into the Trie data structure.
     */
    private void insert(TrieNode root, String word) {
        TrieNode curr = root;
        for (char ch : word.toCharArray()) {
            int index = ch - 'a';
            if (curr.children[index] == null) {
                curr.children[index] = new TrieNode();
            }
            curr = curr.children[index];
        }
        curr.word = word; // Store the full word at the final node.
    }

    /**
     * The recursive Depth-First Search function.
     */
    private void dfs(char[][] board, int r, int c, TrieNode parentNode, boolean[][] visited, Set<String> resultSet) {
        // --- Base Cases for stopping the search down this path ---
        if (r < 0 || c < 0 || r >= board.length || c >= board[0].length || visited[r][c]) {
            return;
        }

        char ch = board[r][c];
        TrieNode currentNode = parentNode.children[ch - 'a'];

        // If the current path doesn't form a valid prefix, stop.
        if (currentNode == null) {
            return;
        }

        // --- Process the current cell ---
        visited[r][c] = true;

        // If a word is found, add it to our results.
        if (currentNode.word != null) {
            resultSet.add(currentNode.word);
            // Optimization: "un-mark" the word in the trie to avoid duplicates
            // if the same word can be formed in multiple ways.
            currentNode.word = null;
        }

        // --- Recurse in all 8 directions ---
        int[] dr = {-1, -1, -1, 0, 0, 1, 1, 1}; // Delta for row
        int[] dc = {-1, 0, 1, -1, 1, -1, 0, 1}; // Delta for column

        for (int i = 0; i < 8; i++) {
            dfs(board, r + dr[i], c + dc[i], currentNode, visited, resultSet);
        }

        // --- Backtrack ---
        // Un-mark the cell so it can be used in other paths.
        visited[r][c] = false;
    }

    // --- Main method to handle input and output ---
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            // Read board dimensions
            int rows = scanner.nextInt();
            int cols = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            // Read the board
            char[][] board = new char[rows][cols];
            for (int i = 0; i < rows; i++) {
                String[] line = scanner.nextLine().split(" ");
                for (int j = 0; j < cols; j++) {
                    board[i][j] = line[j].charAt(0);
                }
            }

            // Read the dictionary
            int numWords = scanner.nextInt();
            scanner.nextLine(); // Consume newline
            String[] dictionary = new String[numWords];
            for (int i = 0; i < numWords; i++) {
                dictionary[i] = scanner.nextLine();
            }

            // Solve the problem
            BoggleSolver solver = new BoggleSolver();
            List<String> foundWords = solver.findWords(board, dictionary);

            // Print the output in the required format
            System.out.println(foundWords.size());
            for (String word : foundWords) {
                System.out.println(word);
            }
        }
    }
}
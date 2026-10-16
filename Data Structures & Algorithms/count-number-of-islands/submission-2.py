import collections

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        rows = len(grid)
        cols = len(grid[0])

        visited = set()
        islands = 0
        
        def bfs(r, c):
            q = collections.deque()
            visited.add((r, c))
            q.append((r, c))

            while q:
                row, col = q.popleft()
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

                for dr, dc in directions:
                    new_row = row + dr  
                    new_col = col + dc  

                    if (
                        new_row in range(rows)
                        and new_col in range(cols)
                        and grid[new_row][new_col] == "1"
                        and (new_row, new_col) not in visited
                    ):
                        q.append((new_row, new_col))       
                        visited.add((new_row, new_col))    
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and (r, c) not in visited:
                    bfs(r, c)
                    islands += 1

        return islands
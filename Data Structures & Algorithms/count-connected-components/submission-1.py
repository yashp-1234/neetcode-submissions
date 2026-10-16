class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = {i:[] for i in range(n)}

        for x,y in edges:
            adj[x].append(y)
            adj[y].append(x)

        print(adj)

        visited = set()
        ans = 0

        def dfs(i):
            if i in visited:
                return
            visited.add(i)
            for j in adj[i]:
                dfs(j)
            

        for i in adj.keys():
            if i in visited:
                continue
            
            dfs(i)
            ans += 1
            

        return ans
        